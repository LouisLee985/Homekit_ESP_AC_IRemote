#include "SHTC3.h"

#define H_K                 (0.001525878906f)
#define H_K_SCALED          (15259UL)      
#define T_K                 (0.002670288086f)
#define T_K_SCALED          (26703UL)
#define T_MIN               (45.0f)
#define T_MIN_INT           (-4500)
#define T_MAX_INT           (17500)


uint8_t SHTC3::crc8(const uint8_t *data, uint8_t len) {
  
  uint8_t crc = 0xff;
  uint8_t byteCtr;
  for (byteCtr = 0; byteCtr < len; ++byteCtr) {
    crc ^= data[byteCtr];
    for (uint8_t bit = 8; bit > 0; --bit) {
      if (crc & 0x80) {
        crc = (crc << 1) ^ 0x31;
      } else {
        crc = (crc << 1);
      }
    }
  }
  return crc;
}

bool SHTC3::twiCommand(uint16_t cmd,uint8_t stop) {
    uint8_t tx=0;
    //Serial.print("WIRE CMD:"); Serial.print(cmd,HEX);
    _wire.beginTransmission(SHTC3_ADDRESS);
    tx+= _wire.write((uint8_t)(cmd >> 8 ));             // MSB first
    tx+= _wire.write((uint8_t)(cmd & 0xFF));
    uint8_t r=_wire.endTransmission(stop);
    //Serial.print("/res:"); Serial.println(r==0 && tx==2);
    return  r==0 && (tx==2) ;
}

bool SHTC3::twiTransfer(uint16_t cmd,uint8_t *data,uint8_t len,uint8_t pause) {
    bool r=false;
    if(twiCommand(cmd,false)) {
        if(pause>0) delay(pause);
        _wire.requestFrom(SHTC3_ADDRESS, len, (uint8_t)true);
        r= ( _wire.available() == len );
        if(r) {
            while(len--) //{*data=_wire.read(); Serial.print(*data,HEX); data++; }
                *data++=_wire.read();
        }
    }
    return r;
}


bool SHTC3::begin(bool do_sample) {
    
    uint8_t id[3]; // ID + CRC
    bool r=false;
    delayMicroseconds(SHTC3_RESET_DELAY_US);
    wakeup();
    if(twiTransfer(SHTC3_ID,id,3) && checkCRC(id)) {
        // xxxx ' 1xxx  |  xx00 ’ 0111  is chip signature  Check it
        r= (id[0] & 0b00001000) && ( (id[1] & 0b00111111) == 0b000000111 );
        // Soft reset of the device && put in sleep mode
        r = r && reset();
        r =  r  && ( (do_sample) ? sample() : sleep() );
    }
    return r;
}
bool SHTC3::sample(uint16_t readcmd,uint8_t pause) {
    bool r=false;
    uint8_t buff[6];    // tmp buffer
    if(wakeup()) {
        r = twiTransfer(readcmd,buff,6,pause);
        r = r && checkCRC(buff) && checkCRC(&buff[3]);
        if (r) { // translate measurement to values
            _t = (buff[0] << 8 ) + buff[1];
            _h = (buff[3] << 8 ) + buff[4];
        }
        sleep(); // Sleep at the end
    }
    return r;
}

#if defined(ARDUINO_SHTC3_NOFLOAT)

int16_t SHTC3::readTempC() {
    uint32_t t= T_K_SCALED * _t;
    return   ( (uint16_t)(t/100000) ) - (int16_t)4500;
}

uint16_t SHTC3::readHumidity() {
    uint32_t h= H_K_SCALED * _h;
    return   (h/100000);
}

#else

float SHTC3::readTempC(){
    return   ( _t * T_K ) - T_MIN; 
}

float SHTC3::readHumidity() {
    return (float)_h * H_K;
}

#endif

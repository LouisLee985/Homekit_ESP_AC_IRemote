#ifndef _H_ARDUINO_SHTC3_H_
#define _H_ARDUINO_SHTC3_H_

#include <Arduino.h>
#include <Wire.h>

#define SHTC3_ADDRESS            ( (uint8_t) 0x70 )
#define SHTC3_RESET_DELAY_US      ( 255 )

typedef TwoWire arduino_shtc3_wire_t;

enum shtc3_cmds_t {
    SHTC3_SLEEP=    0xB098,
    SHTC3_WAKEUP=   0x3517,
    SHTC3_RESET=    0x805D,
    SHTC3_ID=       0xEFC8,
    SHTC3_READ=     0x7CA2, // T first + Clock streching
    SHTC3_READ_LP=  0x6458  // T first + Clock streching + Low power
};

class SHTC3 {
    public:
        SHTC3(arduino_shtc3_wire_t &w) : _wire(w),_t(0),_h(0) { }
        
        bool begin(bool do_sample=false);
        bool sample(uint16_t readcmd=SHTC3_READ_LP,uint8_t pause=0);
        
        float       readTempC();
        float       readHumidity();       

        inline bool  sleep()  { return  twiCommand(SHTC3_SLEEP);  }
        inline bool  wakeup() { bool b=twiCommand(SHTC3_WAKEUP); delayMicroseconds(SHTC3_RESET_DELAY_US); return b; }
        inline bool  reset()  { bool b=twiCommand(SHTC3_RESET); delayMicroseconds(SHTC3_RESET_DELAY_US);  return b; }

        bool twiCommand(uint16_t cmd,uint8_t stop=true);
        bool twiTransfer(uint16_t cmd,uint8_t *data,uint8_t len,uint8_t pause=0);

    private:
        // Properties
        arduino_shtc3_wire_t&   _wire;
        uint16_t  _t;
        uint16_t  _h;
       // Private methods
        inline bool checkCRC(const uint8_t *data) { return crc8(data,2) == data[2]; }
        uint8_t     crc8(const uint8_t *data, uint8_t len);
};
#endif

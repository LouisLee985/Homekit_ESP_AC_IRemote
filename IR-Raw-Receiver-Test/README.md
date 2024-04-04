## IR receiver Pin  GPIO 12
   

* Flash to 0x0 of device based on an ESP8266 microcontroller (ESP8266EX and ESP8285 chips), rboot.bin and blank_config.bin is not needed.
* Power off device.
* Connect receiver data pin to GPIO 12 using an IR receiver like <a href="https://www.cytron.io/p-ir-receiver-diode-vs1838b-38khz">VS1838B</a>, <a href="https://www.vishay.com/en/product/82484/">TSMP1138</a> ...
* Power on device using USB adapter.
* Output is transmitted to UART. You can read it using screen command or any other serial reader.
* To get a good capture, put IR transmitter very near of receiver (1cm - 0.4inch).

---
## Data format

* The haa_ir_capture_IO_12.bin is compiled from <a href="https://github.com/RavenSystem/esp-homekit-devices/releases/tag/HAAIR_1.0.0">HAA IR Capture Tool v1.0</a></h3>


```
Packets: 199
Standard Format
+ 4323 - 4515 +  494 - 1690 +  493 -  585 ... ... ...
HAA RAW Format
JhJkAODFAOAhAODFAODFAOAhATAcATDAATAcATAcATDAATAcATAcATDAATDAATAcATDAATDAATDAATDAATDAATDAATDAATDAATDAATAcATAcATAcATAcATAcATAcATAcATAcATDAATAcATAcATDAATDAATDAATAcATAiANAcATDAATDAATAcATAcATAcATDAATDAATL1JoJ#ATDAASAdASDAATDAATAcATAcASDAATAcATAcASDAATAcASAdASDBASDBASAdASDBASDAASDBASDBASDBASDBASDBASDBASDBASAdASAdASAdASAdASAdASAdASAdASAdASDBARAdASAdASDBARDCARDBARAeARAeARAeARDCARDCARAeARAeARAeARDCARDCAR
```


* IRrecvDumpV2_IO_12.bin is compiled from <a href="https://github.com/crankyoldgit/IRremoteESP8266">IRremoteESP8266</a>

```
Timestamp : 000470.742,  Library : v2.8.2
Code : 0xA1834AFFFF56 (48 Bits)
Protocol: 34 (MIDEA), Type: 1 (Command), Power: On, Mode: 3 (Heat), Celsius: On, Temp: 27C/80F, On Timer: Off, Off Timer: Off, Fan: 0 (Auto), Sleep: Off, Swing(V): -, Econo: -, Turbo: -, Quiet: Off, Light: -, Clean: -, 8C Heat: -
uint16_t rawData[199] = {4444, 4560,  536, 1714,  538, 618,  ... ... ... };  // MIDEA A1834AFFFF56
uint64_t data = 0xA1834AFFFF56;
```

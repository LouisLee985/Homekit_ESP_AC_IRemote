<h2>IR receiver Pin is GPIO 12.</h2>
<p>   
<ol>
<li>Flash to 0x0 of device based on an ESP8266 microcontroller (ESP8266EX and ESP8285 chips), rboot.bin and blank_config.bin is not needed.</li>
<li>Power off device.</li>
<li>Connect receiver data pin to GPIO 12 using an IR receiver like <a href="https://www.cytron.io/p-ir-receiver-diode-vs1838b-38khz">VS1838B</a>, <a href="https://www.vishay.com/en/product/82484/">TSMP1138</a> ...</li>
<li>Power on device using USB adapter.</li>
<li>Output is transmitted to UART. You can read it using screen command or any other serial reader.</li>
<li>To get a good capture, put IR transmitter very near of receiver (1cm - 0.4inch).</li>
</ol>
</p>
<h2>Data format </h2>
<h3>The haa_ir_capture_IO_12.bin is compiled from <a href="https://github.com/RavenSystem/esp-homekit-devices/releases/tag/HAAIR_1.0.0">HAA IR Capture Tool v1.0</a></h3>
<p>

`Packets: 199`
<br>`Standard Format`
<br>`+ 4323 - 4515 +  494 - 1690 +  493 -  585 ... ... ...`
### HAA RAW Format

```
JhJkAODFAOAhAODFAODFAOAhATAcATDAATAcATAcATDAATAcATAcATDAATDAATAcATDAATDAATDAATDAATDAATDAATDAATDAATDAATAcATAcATAcATAcATAcATAcATAcATAcATDAATAcATAcATDAATDAATDAATAcATAiANAcATDAATDAATAcATAcATAcATDAATDAATL1JoJ#ATDAASAdASDAATDAATAcATAcASDAATAcATAcASDAATAcASAdASDBASDBASAdASDBASDAASDBASDBASDBASDBASDBASDBASDBASAdASAdASAdASAdASAdASAdASAdASAdASDBARAdASAdASDBARDCARDBARAeARAeARAeARDCARDCARAeARAeARAeARDCARDCAR
```
</p>
<p>
<br>
<h3>IRrecvDumpV2_IO_12.bin is compiled from <a href="https://github.com/crankyoldgit/IRremoteESP8266">IRremoteESP8266</a></h3>

```
Timestamp : 000470.742,  Library : v2.8.2
Code : 0xA1834AFFFF56 (48 Bits)
Protocol: 34 (MIDEA), Type: 1 (Command), Power: On, Mode: 3 (Heat), Celsius: On, Temp: 27C/80F, On Timer: Off, Off Timer: Off, Fan: 0 (Auto), Sleep: Off, Swing(V): -, Econo: -, Turbo: -, Quiet: Off, Light: -, Clean: -, 8C Heat: -
uint16_t rawData[199] = {4444, 4560,  536, 1714,  538, 618,  ... ... ... };  // MIDEA A1834AFFFF56
uint64_t data = 0xA1834AFFFF56;
```

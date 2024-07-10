# Homekit_ESP_AC_IRemote

### Installation
<ol>
<li>Connect your device to your FTDI adapter in flash-mode, holding down device button IO0 while connecting or connecting GPIO-0 to GND.
</li>
<li>Use  <a href="https://www.espressif.com.cn/zh-hans/support/download/other-tools">flash_download_tool</a> to flash it in your device.</li>

<br>Homekit_AC_Remote_1.0.0.bin，@0x0
<br>DoNotChgBin is unchecked。
<br>select COM：...，BAUD:115200。
<br>ERASE...
<br>START...
</ol>


<div align="center">
<br><img src="/image/flash_download.png"  width="50%" alt="flash_download"/>
</div>


### ESP8285 PIN
&emsp;&emsp;[Homekit-Air-Conditioner-Remote](https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/tree/main/hardware)
<br>&emsp;&emsp;[Air_Conditioner_Remote_1.6.0.bin](/firware_bin)
<div align = "center">

| IR_T(OUT) |IO14|
| :---: |:---: |
|**IR_R(IN)** |**IO12**|
|**LED** |**IO2**|
|**Button**|**IO0** |
|**SDA**|**IO4** |
|**SCL**|**IO5** |
</div>

### Sparkfun_ir_blaster PIN
&emsp;&emsp;[SparkFun WiFi IR Blaster (ESP8266)](https://github.com/sparkfun/ESP8266_WiFi_IR_Blaster)
<br>&emsp;&emsp;[Air_Conditioner_Remote_1.6.0-sparkfun_ir_blaster.bin](/firware_bin)

<div align="center">
<br><img src="/image/SparkFun_WiFi_IR_Blaster_ESP8266.png"  width="60%" alt="SparkFun_WiFi_IR_Blaster_ESP8266"/>
</div>

<div align = "center">

| IR_T(OUT) |IO4|
| :---: |:---: |
|**IR_R(IN)** |**IO13**|
|**LED** |**IO5**|
|**Button**|**IO0** |
|**SDA**|**IO12** |
|**SCL**|**IO14** |
</div>



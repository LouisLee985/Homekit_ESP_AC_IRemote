# AC_IRemote_ESP-01F
* <a href='http://htmlpreview.github.io/?https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/blob/main/image/BOM_AC_IR_Homekit_USB_TYPE_A.html'>InteractiveHtmlBom</a>

<div align="center">
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A2.jpg"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A2"/>
<br>
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A3.png"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A3"/>
<br> 
<br><img src="/image/IMG_3366.png"  width="60%"/>
<br>
</div>
<br>




* Regarding Temperature and Humidity:
<br>Due to the compactness of the PCB, the temperature and humidity sensor *`SHTC3`*  on the PCB is affected by the heat dissipation of the *`ESP-01F`*  ,resulting in consistently higher temperature readings.
<br>The temperature and humidity sensor and related resistors and capacitors U8,R8,R9,C5，can be left unsoldered, and the temperature and humidity display in the HomeKit App will show 0.

* If accurate temperature and humidity readings are required, do not solder U8,R8,R9,C5， After flashing the firmware, connect an external *`temperature and humidity sensor module`* , keeping it away from heat sources.
<br>SDA,SCL,3V3,GNDare used for connecting an external *`temperature and humidity sensor module`*.

* Supported external SHT *`temperature and humidity sensor modules`*: 　SHTC1，SHTC3，SHTW1，SHTW2，SHT3x-DIS (I2C)，SHT3x-ARP (ratiometric analog voltage output)，SHT85，SHT4x，e.g.
<div align="center">
<br><img src="/image/SHT3X.png"  width="40%"/>
 </div> 


* AC_IRemote_ESP-01F PIN

<div align = "center">

| IR_T(OUT) |IO14|
| :---: |:---: |
|**IR_R(IN)** |**IO12**|
|**LED** |**IO2**|
|**Button**|**IO0** |
|**SDA**|**IO4** |
|**SCL**|**IO5** |
</div>

## [Sparkfun_ir_blaster ](https://github.com/sparkfun/ESP8266_WiFi_IR_Blaster)
* SparkFun WiFi IR Blaster (ESP8266) is supported. 
&emsp;&emsp;
[sparkfun_ir_blaster.bin](https://github.com/LouisLee985/Homekit_ESP_AC_IRemote/releases/download/v1.2.0/Air_Conditioner_Remote_1.2.0-sparkfun_ir_blaster.bin)

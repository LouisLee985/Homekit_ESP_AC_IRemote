# AC_IRemote_ESP-01F
* 2层PCB，0603封装，便于焊接。

<div align="center">
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A2.jpg"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A2"/>
<br>
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A3.png"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A3"/>
<br> 
<br><img src="/image/IMG_3366.png"  width="60%"/>
<br>
</div>
<br>

* <a href='http://htmlpreview.github.io/?https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/blob/main/image/BOM_AC_IR_Homekit_USB_TYPE_A.html'>InteractiveHtmlBom</a>


* 关于温湿度：
<br>因PCB过于紧凑，PCB上温湿度传感器 *`SHTC3`* 受 *`ESP-01F`* 散热干扰，测温始终偏高。
<br>可不焊温湿度传感器及相关阻容U8,R8,R9,C5，Homekit App 的温湿度显示为0。

* 如有准确温湿度的需求，不焊U8,R8,R9,C5，刷入固件后，另外接 *`温湿度传感器模块`* ，远离散热源。
<br>SDA,SCL,3V3,GND用于外接 *`温湿度传感器模块`* 。

* 支持的SHT温湿度传感器外接模块:　SHTC1，SHTC3，SHTW1，SHTW2，SHT3x-DIS (I2C)，SHT3x-ARP (ratiometric analog voltage output)，SHT85，SHT4x，e.g.
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

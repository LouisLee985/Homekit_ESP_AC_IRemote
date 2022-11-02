# Homekit_Air_Conditioner_Remote
* 2层PCB打样，内置空调机内。
* 无需USB公插和红外接收电路, 直接连接到空调数显主板上，共用主板+5V供电和红外接收。
* 需有电工基础和空调维修经验。 
* SDA,SCL,3V3,GND红色标记处，用于外接 *`温湿度传感器模块`* 。避免因PCB过于紧凑，导致PCB上SHTC3受ESP-01F散热干扰而测温始终高的问题。

<div align="center">
<br><img src="/image/AC_IR_Homekit_Inside_3.0_0402.jpg" width="60%"/>

<br><img src="/image/IMG_2002.JPG" width="60%"/>

<br><img src="/image/IMG_2003.JPG"  width="60%"/>

<br><img src="/image/IMG_2004.jpg"  width="60%"/>

<br><img src="/image/IMG_2007.jpg"  width="60%"/>

<br><img src="/image/IMG_2029.jpg"  width="60%"/>

<br><img src="/image/IMG_2030.jpg"  width="60%"/>

<br><img src="/image/IMG_2031.JPG"  width="60%"/>
</div>

* 柜机数显主板, 找出+5V, GND, REV(红外接收数据pin), 同样使用。
<div align="center">
<br><img src="/image/IMG_2005.JPG"  width="200"/>
 </div> 
 
*  [支持的SHT温湿度传感器外接模块](https://github.com/Sensirion/arduino-sht#supported-sensors)。

<div align="center">
<br><img src="/image/SHT3X.jpg"  width="60%"/>
 </div> 

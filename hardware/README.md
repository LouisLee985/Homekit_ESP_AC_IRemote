# AC_IR_Homekit_USB_TYPE_A
0603封装，便于焊接，2层PCB打样，形似U盘，简洁不简单。
## 关于测温：
因PCB过于紧凑，导致PCB上SHTC3受ESP-01F散热干扰而测温始终偏高。可不使用板载温湿度传感器，而另外接 *`温湿度传感器模块`* ，远离散热源。
* SDA,SCL,3V3,GND红色标记处，用于外接 *`温湿度传感器模块`* 。
* 支持的SHT温湿度传感器外接模块:　SHTC1，　SHTC3，　SHTW1，　SHTW2，　SHT3x-DIS (I2C)，　SHT3x-ARP (ratiometric analog voltage output)，　SHT85，　SHT4x。
<br>如使用外接模块，PCB上的SHTC3及相关阻容不必焊接。黑色标记处。
<div align="center">
<br><img src="/image/SHT3X.jpg"  width="60%"/>
 </div> 
 
 <div align="center">
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A1.jpg"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A1"/>
<br>
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A2.jpg"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A2"/>

<br>

</div>

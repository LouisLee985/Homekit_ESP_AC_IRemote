# AC_IR_Homekit_USB_TYPE_A
0603封装，便于焊接，2层PCB打样。
<br><a href='http://htmlpreview.github.io/?https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/blob/main/hardware/BOM_AC_IR_Homekit_USB_TYPE_A.html'>BOM表</a>

<div align="center">
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A1.jpg"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A1"/>
<br>
<br><img src="/image/AC_IR_Homekit_USB_TYPE_A2.jpg"  width="60%" alt="AC_IR_Homekit_USB_TYPE_A2"/>
<br>
</div>

## 关于测温：
因PCB过于紧凑，导致PCB上SHTC3受ESP-01F散热干扰而测温始终偏高。
<br>如果不焊温湿度传感器SHTC3及相关阻容U8,C5,R8,R9，homekit app 的温湿度显示为0.
 

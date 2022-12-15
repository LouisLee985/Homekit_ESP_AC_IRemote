# Homekit_Air_Conditioner_Remote
## 硬件有三个版本：

* [5V1A版本](/hardware/AC_IR_Homekit_5V1A_3.0_0402)：0402封装，2层PCB打样，外观专门与Apple 5V1A 充电头配套。其它USB充电头也可用。
* [Inside版本](/hardware/AC_IR_Homekit_Inside_3.0_0402)：0402封装，2层PCB打样，安装在空调内部, 直接从空调内部取电和红外反馈。需有电工基础和空调维修经验。
* [USB_TYPE版本](/hardware/AC_IR_Homekit_USB_TYPE_0603)：0603封装，便于焊接，2层PCB打样，形似U盘，简洁不简单。
## 测温干扰：
* SDA,SCL,3V3,GND红色标记处，用于外接 *`温湿度传感器模块`* 。避免因PCB过于紧凑，导致PCB上SHTC3受ESP-01F散热干扰而测温始终高的问题。
* 支持的SHT温湿度传感器外接模块:　SHTC1，　SHTC3，　SHTW1，　SHTW2，　SHT3x-DIS (I2C)，　SHT3x-ARP (ratiometric analog voltage output)，　SHT85，　SHT4x。
<br>如使用外接模块，PCB上的SHTC3及相关阻容不必焊接。黑色标记处。
<div align="center">
<br><img src="/image/SHT3X.jpg"  width="60%"/>
 </div> 

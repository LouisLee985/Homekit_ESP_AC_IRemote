# Homekit_Air_Conditioner_Remote

### 刷机
<ol>
<li>使用针距1.27mm 4P烧录针或烧录夹，连接 USB转串口。</li>
<li>按住IO0按键上电。</li>
<li>松开IO0按键。</li>
<li> <a href="https://www.espressif.com.cn/zh-hans/support/download/other-tools">ESP Flash 下载烧录工具：</a></li>

<br>Homekit_AC_Remote_1.0.0.bin，@0x0
<br>DoNotChgBin is unchecked。
<br>select COM：...，BAUD:115200。
<br>ERASE...
<br>START...
</ol>

<!--
<div align="center">
<br><img src="/image/flash_download.jpg"  width="50%" alt="flash_download"/>
</div>
-->

### ESP8266 PIN引脚定义
&emsp;&emsp;[Homekit-Air-Conditioner-Remote](https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/tree/main/hardware)
<br>&emsp;&emsp;[Air_Conditioner_Remote_1.6.0.bin](https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/blob/main/firware_bin/Air_Conditioner_Remote_1.6.0.bin)
<div align = "center">

| IR_T(OUT) | 红外发射 |IO14|
| :---: | :---: |:---: |
|**IR_R(IN)** | **红外接收** |**IO12**|
|**LED** |**指示灯** |**IO2**|
|**Button**|**按键** |**IO0** |
|**SDA**| |**IO4** |
|**SCL**| |**IO5** |
</div>

### Sparkfun_ir_blaster PIN引脚定义
&emsp;&emsp;[SparkFun WiFi IR Blaster (ESP8266)](https://github.com/sparkfun/ESP8266_WiFi_IR_Blaster)
<br>&emsp;&emsp;[Air_Conditioner_Remote_1.6.0-sparkfun_ir_blaster.bin](https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/blob/main/firware_bin/Air_Conditioner_Remote_1.6.0-sparkfun_ir_blaster.bin)
<div align = "center">

| IR_T(OUT) | 红外发射 |IO4|
| :---: | :---: |:---: |
|**IR_R(IN)** | **红外接收** |**IO13**|
|**LED** |**指示灯** |**IO5**|
|**Button**|**按键** |**IO0** |
|**SDA**| |**IO12** |
|**SCL**| |**IO14** |
</div>




### TYSW-012 PIN引脚定义
&emsp;&emsp;[TYSW_012](https://developer.tuya.com/cn/docs/iot/tysw012-round-universal-remote-control?id=K9lnm617oupeb)
<br>&emsp;&emsp;[Air_Conditioner_Remote_1.6.0-TYSW-012.bin]()
<div align = "center">

| IR_T(OUT) | 红外发射 |IO14|
| :---: | :---: |:---: |
|**IR_R(IN)** | **红外接收** |**IO5**|
|**LED** |**指示灯** |**IO4**|
|**Button**|**按键** |**IO13** |
|**SDA**| |**IO2** |
|**SCL**| |**IO12** |
</div>


# Homekit_Air_Conditioner_Remote

### 刷机
<ol>
<li>使用针距1.27mm 4P烧录针或烧录夹,连接 USB转串口.</li>
<li>按住IO0按键上电.</li>
<li>松开IO0按键.</li>
<li> <a href="https://www.espressif.com.cn/zh-hans/support/download/other-tools">ESP Flash 下载烧录工具:</a></li>
chipType:ESP8285,  workMode:develop
<br>SPIDownload
<br>Homekit_AC_Remote_1.0.0.bin,  @0x0
<br>SPI SPEED 40MHz,  SPI MODE DOUT <!-- ,  DoNotChgBin不勾选。-->
<br>select COM:...,  BAUD:115200.
<br>ERASE...
<br>START...
</ol>
<div align="center">
<br><img src="/image/flash_download.jpg"  width="50%" alt="flash_download"/>
</div>

### Sparkfun_ir_blaster ESP8266 PIN引脚定义

<div align = "center">

| IR_T | 红外发射 |IO4|
| :---: | :---: |:---: |
|**IR_R** | **红外接收** |**IO13**|
|**LED** |**指示灯** |**IO5**|
|**Button**|**按键** |**IO0** |
|**SDA**| |**IO12** |
|**SCL**| |**IO14** |
</div>



<!--
### TYSW-012 PIN引脚定义

<div align = "center">

| IR_T | 红外发射 |IO14|
| :---: | :---: |:---: |
|**IR_R** | **红外接收** |**IO5**|
|**LED** |**指示灯** |**IO4**|
|**Button**|**按键** |**IO0** |
|**SDA**| |**IO2** |
|**SCL**| |**IO12** |
</div>
-->

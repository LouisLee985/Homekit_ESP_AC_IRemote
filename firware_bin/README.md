# Homekit_Air_Conditioner_Remote
[Homekit_Air_Conditioner_Remote_bin_v1.0.0](https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/releases)

### 刷机
<ol>
<li>使用针距1.27mm 4P烧录针或烧录夹,连接 USB转串口.</li>
<li>按住IO0按键上电.</li>
<li>松开IO0按键.</li>
<li> <a href="https://www.espressif.com.cn/zh-hans/support/download/other-tools">ESP Flash 下载烧录工具:</a></li>
chipType:ESP8285,  workMode:develop
<br>SPIDownload
<br>Air_Conditioner_1.0.bin,  @0x0
<br>SPI SPEED 40MHz,  SPI MODE DOUT,  DoNotChgBin不勾选。
<br>select COM:...,  BAUD:115200.
<br>ERASE...
<br>START...
</ol>
<div align="center">
<br><img src="/image/flash_download.jpg"  width="50%" alt="flash_download"/>
</div>

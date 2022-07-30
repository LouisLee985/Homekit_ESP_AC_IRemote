# 刷机
<ol>
<li>使用针距1.27mm 4P探针刷机夹连接 USB转串口.
<li>按住IO0按钮上电.
<li>松开IO0按钮.
<li> <a href="https://www.espressif.com.cn/zh-hans/support/download/other-tools">ESP Flash 下载烧录工具:</a>
<br>chipType:ESP8285,  workMode:develop
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

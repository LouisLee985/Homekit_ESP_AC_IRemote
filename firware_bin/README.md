# 刷机
使用针距1.27mm 4P探针刷机夹连接 USB转串口.
<br>按住IO0按钮上电.
<br>松开IO0按钮.
<br>Flash 下载工具: 
<br>https://www.espressif.com.cn/zh-hans/support/download/other-tools
<br>chipType:ESP8285, workMode:develop
<br>SPIDownload
<br>Air_Conditioner_1.0.bin, @0x0
<br>SPI SPEED 40MHz, SPI MODE DOUT, DoNotChgBin不勾选。
<br>select COM:..., BAUD:115200.
<br>ERASE...
<br>START...

# 功能
Homekit 配对码：11111111
红外协议设定。
红外信号反馈。
Apple Homekit App 空调功能:制冷，制热，风速，当前环境温湿度显示。

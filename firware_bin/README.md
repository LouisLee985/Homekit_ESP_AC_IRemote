# 刷机
<ol>
<li>使用针距1.27mm 4P探针刷机夹连接 USB转串口.
<li>按住IO0按钮上电.
<li>松开IO0按钮.
<li>Flash 下载烧录工具: 
<br>https://www.espressif.com.cn/zh-hans/support/download/other-tools
<br>chipType:ESP8285, workMode:develop
<br>SPIDownload
<br>Air_Conditioner_1.0.bin, @0x0
<br>SPI SPEED 40MHz, SPI MODE DOUT, DoNotChgBin不勾选。
<br>select COM:..., BAUD:115200.
<br>ERASE...
<br>START...
</ol>

# 功能
Homekit 配对码：11111111
<br>空调遥控识别:按下IO0按键5S，LED闪烁，松开按键，10S内普通空调遥控器对准此项目上的遥控接收头(IR_R)按下开关机键，等待LED闪烁停止。
<br>Apple Homekit App 空调功能:制冷，制热，风速，当前环境温湿度显示。
<br>红外信号反馈，普通空调遥控器调节制冷，制热，温度，风速等Homekit支持的动作时，Homekit App会同步更新状态。
<br>IO0按键定义:
<br>空调遥控识别(如上):按下IO0按键5S,LED闪烁，松开按键.
<br>抹除Homekit配对信息:按下IO0按键10S,LED闪烁，加快闪烁，松开按键,抹除Homekit配对信息.
<br>恢复设置:按下IO0按键15S,LED闪烁，加快闪烁，更快闪烁，松开按键,抹除Homekit配对信息,WIFI连接信息,空调遥控识别(恢复设置).

# Homekit_Air_Conditioner
<h3>WiFi配网</h3>
<ol>
<li>上电后, ESP8266在未联网/断网时LED 2/S闪烁, 生成ESP_XXXXXX的热点, XXXXXX是8266芯片的CHIPID.</li>
<li>手机连接该热点, 自动弹出配网页面，ios版本不同自动弹出的时间不同, 12.5以下很快就弹出配网页面, 15.0以上要等很长时间. 如果未自动弹出可手动访问192.168.4.1</li>
<li>Configure WiFi, 选择WiFi，输入密码, Save，连接成功后会自动退出配网模式并关闭ESP_XXXXXX热点.</li>
</ol>
<div align="center">
<br><img src="/image/WiFi_Configure.jpg"  width="80%"/>
</div>
<h3>Add accessories 添加 HomeKit 配件</h3>
<br>Homekit 配对码: 11111111
<div align="center">
<br><img src="/image/Add_accessories1.jpg"  width="90%"/>
<br><img src="/image/Add_accessories2.jpg"  width="80%"/>
</div>
<br>https://support.apple.com/en-us/HT204893

<br>Apple Homekit App 空调功能: 制冷, 制热, 风速, 当前环境温湿度显示. 
<br>红外信号反馈: 普通空调遥控器调节制冷, 制热, 温度, 风速等Apple Homekit协议支持的动作时, Homekit App会同步更新状态. 
<br>如果需要出门在外时远程控制 HomeKit 配件, 请将 HomePod、HomePod mini、Apple TV 或 iPad <a href="https://support.apple.com/zh-cn/HT207057">设置为家居中枢. </a>
    

<h3>IO0按键定义:</h3>
<ol>
<li>空调遥控识别: 按下IO0按键5S, LED 2/S闪烁, 松开按键, 15S内普通空调遥控器对准此项目上的遥控接收头(IR_R)按一下开关机键, 等待LED闪烁停止.</li>
<li>抹除Homekit配对信息: 按下IO0按键10S, LED 2/S闪烁, 4/S闪烁, 松开按键, 抹除Homekit配对信息. </li>
<li>恢复设置: 按下IO0按键15S, LED 2/S闪烁, 4/S闪烁, 8/S闪烁, 松开按键, 抹除Homekit配对信息, 抹除Wifi连接信息, 抹除空调遥控识别信息. </li>
</ol>

# Thanks
https://github.com/tzapu/WiFiManager
<br>https://github.com/ludiazv/arduino-SHTC3
<br>https://github.com/crankyoldgit/IRremoteESP8266
<br>https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266
<br>https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press

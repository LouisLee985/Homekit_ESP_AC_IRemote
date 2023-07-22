
# Homekit_Air_Conditioner_Remote

<p align="center">
<img src="/image/HomeApp_Icon_2.svg" width="10%"/>
</p>

<div align="center">
<br><img src="/image/IMG_3366.JPG"  width="60%"/>
</div>

### WiFi配网


1. 上电后, ESP8266在未联网/断网时LED 2/S闪烁, 生成ESP_XXXXXX的热点, XXXXXX是8266芯片的MAC.
2. 手机连接该热点，自动弹出配网页面。如果未自动弹出可手动访问192.168.4.1。
3. Configure WiFi, 选择 WiFi，输入密码, Save，连接成功后会自动退出配网模式并关闭 ESP_XXXXXX 热点.

<div align="center">
<br><img src="/image/WiFi_Configure.jpg"  width="80%"/>
</div>

### Add accessories 添加 HomeKit 配件

* Homekit 配对码: 985-21-985。
   
<div align="center">
<br><img src="/image/qrcode.jpg"  width="20%"/>
</div>

   　
* [向“家庭”App 添加配件](https://support.apple.com/zh-cn/HT204893) ３种途径：
<!-- 
https://support.apple.com/en-us/HT204893 
-->


 <br>
　　１．使用 iPhone 或 iPad 上的相机扫描上面的二维码。　＂家庭＂二维码　　在＂家庭＂中打开
<br>
　　２．或者　　打开“家庭”App，然后轻点“添加”；　　轻点“添加配件”。

<div align="center">
<br><img src="/image/IMG_3209.jpg"  width="80%"/>
</div>
<br>
 
　　３．也可以输入配对码。

<div align="center">
<br><img src="/image/Add_accessories3.jpg"  width="80%"/>
</div>

<!-- 
<div align="center">
<br><img src="/image/Add_accessories1.jpg"  width="90%"/>
<br><img src="/image/Add_accessories2.jpg"  width="80%"/>
</div>
-->
<br>

### 空调功能

1. Apple Homekit App 空调功能: 开机, 关机, 制冷, 制热, 风速, 当前环境温湿度显示. 
<br>基于 [HomeKit Accessory Protocol Specification(Noncommercial Version) Release R2](https://developers.apple.com/homekit/faq) , 有 *`此配件尚未经过认证可与Homekit配合使用， 因此部分功能可能不可用。`* 字样. 
2. 如果需要出门在外时远程控制 HomeKit 配件, 请将 HomePod、HomePod mini、Apple TV 或 iPad  [设置为家居中枢. ](https://support.apple.com/zh-cn/HT207057)
3. 红外信号反馈: 普通空调遥控器进行 开机, 关机, 制冷, 制热, 风速等 Apple Homekit 协议支持的动作时, Homekit App 会同步更新状态. 


<div align="center">
<br><img src="/image/HAP-Specification-Non-Commercial-Version.jpg"  width="60%"/>
<br><img src="/image/Add_accessories3.PNG"  width="80%"/>
</div>

### Button IO0 按键定义

1. 长按 IO0 按键5-10S，LED 2/S 闪烁，松开按键, 空调遥控识别：15S 内普通空调遥控器对准此项目上的遥控接收头(IR_R)按一下开关机键，等待 LED 闪烁停止。IRremoteESP8266 库，支持市场上绝大多数空调品牌。
2. 长按 IO0 按键 10-15S，LED 2/S 闪烁，4/S 闪烁，松开按键，恢复设置：抹除 Homekit 配对信息，抹除 Wifi 连接信息，抹除空调遥控识别信息。
 



# Thanks
* [HomeKit Accessory Protocol Specification(Noncommercial Version) Release R2](https://developers.apple.com/homekit/faq)
* [arduino-sht](https://github.com/Sensirion/arduino-sht) 
* [arduino-SHTC3](https://github.com/ludiazv/arduino-SHTC3) 
* [WiFiManager](https://github.com/tzapu/WiFiManager)
* [IRremoteESP8266](https://github.com/crankyoldgit/IRremoteESP8266) 
* [Arduino-HomeKit-ESP8266](https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266) 
* [arduino-button-long-press-short-press](https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press)
*  https://github.com/openscopeproject/InteractiveHtmlBom
*  https://github.com/yanranxiaoxi/InteractiveHtmlBom
<div align="center">  
<img src="https://myoctocat.com/assets/images/base-octocat.svg"  width="10%"/> 
</div>



# Homekit_ESP_AC_IRemote
[![Release](https://img.shields.io/github/v/tag/LouisLee985/Homekit-Air-Conditioner-Remote?color=red&label=release)](https://github.com/LouisLee985/Homekit-Air-Conditioner-Remote/releases/latest)

<p align="center">
<img src="/image/HomeApp_Icon_2.svg" width="20%"/>
</p>

<p align="center">
<img src="/image/process.svg"  width="90%"/>
</p>
<br>

### [WiFiManager](https://github.com/tzapu/WiFiManager?tab=readme-ov-file#how-it-works)
* When your ESP starts up, it sets it up in Station mode and tries to connect to a previously saved Access Point
* if this is unsuccessful (or no previous network saved) it moves the ESP into Access Point mode and spins up a DNS and WebServer (default ip 192.168.4.1)
* using any wifi enabled device with a browser (computer, phone, tablet) connect to the newly created Access Point
* because of the Captive Portal and the DNS server you will either get a 'Join to network' type of popup or get any domain you try to access redirected to the configuration portal
* choose one of the access points scanned, enter password, click save
* ESP will try to connect. If successful, it relinquishes control back to your app. If not, reconnect to AP and reconfigure.
* There are options to change this behavior or manually start the configportal and webportal independantly as well as run them in non blocking mode.
<br>

### HomeKit setup
In your iOS device, open Home App and follow normal steps to [add a new accessory](https://support.apple.com/en-us/104998).

* Homekit Normal Code:
  ```
  985-21-985
  ```

* Homekit QR-Code:
<div align="center">
<br><img src="/image/qrcode.jpg"  width="20%"/>
</div>  　

<br>

### 空调功能

1. Apple Homekit App 空调功能：开机，关机，制冷，制热，~~风速~~，当前环境温湿度显示。 
<br>基于 [HomeKit Accessory Protocol Specification(Noncommercial Version) Release R2](https://developers.apple.com/homekit/faq) ，有 *`此配件尚未经过认证可与Homekit配合使用， 因此部分功能可能不可用。`* 字样。
2. 如果需要出门在外时远程控制 HomeKit 配件，请将 HomePod、HomePod mini、Apple TV 或 iPad  [设置为家居中枢。 ](https://support.apple.com/en-us/102557)
3. 红外信号反馈：普通空调遥控器进行 开机，关机，制冷，制热，~~风速~~等 Apple Homekit 协议支持的动作时，Homekit App 会同步更新状态。


<div align="center">
<br><img src="/image/HAP-Specification-Non-Commercial-Version.jpg"  width="60%"/>
<br><img src="/image/Add_accessories3.PNG"  width="80%"/>
</div>
<br>

### Button IO0 按键定义

  - Long pressed&ensp;&ensp;5-10 second:&emsp;Set up the infrared protocol.
  - Long pressed&ensp;10-15 second:&emsp;Restore settings.
<br>

# Thanks
* [HomeKit Accessory Protocol Specification(Noncommercial Version) Release R2](https://developers.apple.com/homekit/faq)
* [arduino-sht](https://github.com/Sensirion/arduino-sht) 
* [WiFiManager](https://github.com/tzapu/WiFiManager)
* [IRremoteESP8266](https://github.com/crankyoldgit/IRremoteESP8266) 
* [Arduino-HomeKit-ESP8266](https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266) 
* [arduino-button-long-press-short-press](https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press)
*  https://github.com/openscopeproject/InteractiveHtmlBom

<div align="center">  
<img src="https://myoctocat.com/assets/images/base-octocat.svg"  width="10%"/> 
</div>


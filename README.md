# Homekit_Air_Conditioner

Homekit 配对码: 11111111
<br>Apple Homekit App 空调功能: 制冷, 制热, 风速, 当前环境温湿度显示. 
<br>红外信号反馈: 普通空调遥控器调节制冷, 制热, 温度, 风速等Homekit支持的动作时, Homekit App会同步更新状态. 
<br>
<br>IO0按键定义: 
<ol>
<li>空调遥控识别: 按下IO0按键5S, LED 2/S闪烁, 松开按键, 15S内普通空调遥控器对准此项目上的遥控接收头(IR_R)按下开关机键, 等待LED闪烁停止.
<li>抹除Homekit配对信息: 按下IO0按键10S, LED 2/S闪烁, 4/S闪烁, 松开按键, 抹除Homekit配对信息. 
<li>恢复设置: 按下IO0按键15S, LED 2/S闪烁, 4/S闪烁, 8/S闪烁, 松开按键, 抹除Homekit配对信息, WIFI连接信息, 空调遥控识别信息. 
</ol>

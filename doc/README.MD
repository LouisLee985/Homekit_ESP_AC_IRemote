# Study notes
<ol>
<p><h3>Note:</h3>
<li>modify printfs via macro to include file</li>
    
```
#define LOG_PRINT(fmt,args...)  printf(("%s,%s,LINE%d: " fmt "\n"),__FILE__,__func__,__LINE__, ##args)
```
```
#define LOG_INFO(fmt,...)       printf_P(PSTR("%s,%s,LINE%d: " fmt "\n"),__FILE__,__func__,__LINE__, ##__VA_ARGS__)
```
It's from:
<br>
<a href="https://stackoverflow.com/questions/15549893/modify-printfs-via-macro-to-include-file-and-line-number-information">https://stackoverflow.com/questions/15549893/modify-printfs-via-macro-to-include-file-and-line-number-information</a>
    
```
#define MYPRINT(str,args...) printf("%s:%d %s() "str"\n",__FILE__,__LINE__,__func__, ##args)
```
</p>

<p>
<li>erase_before_upload.py</li>
<br><a href="https://community.platformio.org/t/erase-flash-before-upload-in-debug-mode/23703/5">https://community.platformio.org/t/erase-flash-before-upload-in-debug-mode/23703/5</a>
    
```
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
extra_scripts = erase_before_upload.py
```
With<a href=""> erase_before_upload.py </a>in the root project folder
    
```
Import("env")
old_uploaderflags = env["UPLOADERFLAGS"]
#print("Old uploaderflags: " + str(old_uploaderflags))    
index_write_flash = old_uploaderflags.index("write_flash")
if index_write_flash != -1: 
    new_uploaderflags = old_uploaderflags[::]
    new_uploaderflags.insert(index_write_flash + 1, "--erase-all")
    #print("Replaced with: " + str(new_uploaderflags))
    env.Replace(UPLOADERFLAGS=new_uploaderflags)
```
</p>

<p>
<li>Platformio auto upload:</li>
.platformio\platforms\espressif8266\builder\main.py
<br>Change line:319
    
```
UPLOADERFLAGS=[
            "--chip", "esp8266",
            "--port", '"$UPLOAD_PORT"',
            "--baud", "$UPLOAD_SPEED",
            "write_flash"            
        ],
```
To:
    
```
UPLOADERFLAGS=[
            "--before", "default_reset",
            "--after", "hard_reset",
            "--chip", "esp8266",
            "--port", '"$UPLOAD_PORT"',
            "--baud", "$UPLOAD_SPEED",
            "write_flash"            
        ],
```
 </p>
</ol>

<p>
<ol>
<h3>Issues:</h3>
<li>'No Response' after reboot/ssid_off WiFi router</li>
<br>https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266/issues/139
<br>https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266/issues/139#issuecomment-940078639
<br>https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266/issues/139#issuecomment-1040287908

<li>How to use the EEPROM flash:</li>
<br>https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266/issues/79#issuecomment-721092920
</ol>
</p>

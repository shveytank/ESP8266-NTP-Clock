# ESP8266-NTP-Clock
this is a code for esp8266 NTP clock, which will get time from NTP server which means you don't need an RTC to get the time.
There are three codes provided here :
1: simple code to print time from NTP server in serial monitor
2: printing time on 1.8" SPI ST7735 TFT display
3: printing time on 1.8" SPI TFT ST7735 display with custom 7seg font and the font file (.h) is already added in this repo.

for more information check this video on YT:
https://www.youtube.com/watch?v=N0dCZ37cE5o


make sure before uploading the code you edited the offsetTime which will select your country timezone as for me it is 19800
since my time standerd is UTC+5:30=5.5*60*60=19800
say yours is UTC+1=1*60*60=3600
so refer these two examples to get offset time for your time standerd.

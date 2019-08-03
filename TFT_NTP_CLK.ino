#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_ST7735.h>   // include Adafruit ST7735 TFT library
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
// ST7735 TFT module connections
#define TFT_RST   D4     // TFT RST pin is connected to NodeMCU pin D4 (GPIO2)
#define TFT_CS    D3     // TFT CS  pin is connected to NodeMCU pin D4 (GPIO0)
#define TFT_DC    D2     // TFT DC  pin is connected to NodeMCU pin D4 (GPIO4)
// initialize ST7735 TFT library with hardware SPI module
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
 
float p = 3.1415926;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const char *ssid     = "***********";
const char *password = "***********";

WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 19800, 60000);
NTPClient timeClient(ntpUDP);

String formattedDate;
String dayStamp;
String timeStamp;

void setup(void) {
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
  }

  timeClient.begin();
  timeClient.setTimeOffset(19800);
  
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
 tft.setRotation(1);
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  time = millis() - time;
  
  delay(500);
 
  // large block of text
  tft.fillScreen(ST7735_BLACK);
//  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);
  delay(1000);
 
}


void loop() {
  timeClient.update();
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(10,30);
  tft.setTextSize(3);
  tft.println(timeClient.getFormattedTime());
  tft.setCursor(30, 80);
  tft.setTextSize(2);
  tft.println(daysOfTheWeek[timeClient.getDay()]);
  
  

  delay(1000);
  tft.fillScreen(ST7735_BLACK);
}

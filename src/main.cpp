#include <Arduino.h>

#define WiFi_SSID "infinix" // имя сети
#define WiFi_PASS "123456789" // пароль сети

 // иниализация библиотеки датчика темпиратуры
#include <Adafruit_Sensor.h>
#include <DHT.h>
DHT dht(20, DHT11);

// иниализация библииотеки дисплея
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define CS 5
#define RES 16
#define DC 17

Adafruit_ST7735 tft = Adafruit_ST7735(CS, DC, RES);

// иниализация библиотеки для сайта
#include <WiFi.h>
#include<GyverDBFile.h>
#include<LittleFS.h>
GyverDBFile db(&LittleFS, "/data.db");

#include<SettingsGyver.h>
SettingsGyver sett("My settings", &db);


#define buzz // пишалка
#define led_1 // светодиод 1
#define led_2 // светодиод 2

#define gas // датчик газа
#define fire // датчик огня

enum kk : size_t {

};

void build(sets::Builder& b){
   

}

 void setup(){

   Serial.begin(115200);
   Serial.println("");
   
    dht.begin();
    tft.initR(INITR_18BLACKTAB); // иниализация дисплея
    tft.setRotation(4);

    tft.fillScreen(ST7735_BLACK);

    WiFi.begin(WiFi_SSID, WiFi_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
      
      delay(500);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println("Вы подключились сети WiFi!!! ");
    Serial.println(WiFi.localIP());
    

    sett.begin();
    sett.onBuild(build);

   // экран загрузки
   tft.setCursor(20, 20);
   tft.setTextSize(3);
   tft.setTextColor(ST7735_GREEN);
   tft.print("ESP32");

   tft.setCursor(23, 70);
   tft.setTextSize(2);
   tft.print("Loading");

   tft.drawFastHLine(10, 90, 105, ST77XX_BLUE);
   tft.drawFastHLine(10, 120, 105, ST77XX_BLUE);
   tft.drawFastVLine(10, 90, 30, ST77XX_BLUE);
   tft.drawFastVLine(115, 90, 30, ST77XX_BLUE);
   
   // цикл для эффекта закрузки 
   for (int i = 10; i <= 105; i++){
      tft.fillRect(10, 90, i, 30, ST7735_BLUE);
      delay(100);
   }

   tft.setCursor(35, 140);
   tft.setTextSize(1);
   tft.setTextColor(ST7735_GREEN);
   tft.print("by Lino-e");
   delay(1000);

   
    }

 void loop(){
 }

void loading(){
  tft.setCursor(20, 20);
  tft.setTextSize(3);
  tft.setTextColor(ST7735_GREEN);
  tft.print("ESP32");

  tft.setCursor(23, 70);
  tft.setTextSize(2);
  tft.print("Loading");

  tft.drawFastHLine(10, 90, 105, ST77XX_ORANGE);
  tft.drawFastHLine(10, 120, 105, ST77XX_ORANGE);
  tft.drawFastVLine(10, 90, 30, ST77XX_ORANGE);
  tft.drawFastVLine(115, 90, 30, ST77XX_ORANGE);
  
  // цикл для эффекта закрузки 
  for (int i = 10; i <= 105; i++){
     tft.fillRect(10, 90, i, 30, ST7735_ORANGE);
     delay(100);
  }

  tft.setCursor(35, 140);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_GREEN);
  tft.print("by Lino-e");
  delay(1000);

  tft.fillScreen(ST7735_BLACK);
}

void home(){
  tft.drawFastHLine(0, 20, 128, ST7735_ORANGE);
tft.drawFastHLine(0, 21, 128, ST7735_ORANGE);
tft.drawLine(35, 0, 50, 10, ST7735_ORANGE);
tft.drawLine(36, 0, 51, 10, ST7735_ORANGE);
tft.drawLine(34, 0, 49, 10, ST7735_ORANGE);

tft.drawLine(35, 20, 50, 10, ST7735_ORANGE);
tft.drawLine(36, 20, 51, 10, ST7735_ORANGE);
tft.drawLine(34, 20, 49, 10, ST7735_ORANGE);

tft.drawLine(82, 0, 97, 20, ST7735_ORANGE);
tft.drawLine(83, 0, 98, 20, ST7735_ORANGE);
tft.drawLine(81, 0, 96, 20, ST7735_ORANGE);

  tft.setTextSize(1);
  tft.setTextColor(ST7735_GREEN);
  tft.setCursor(10, 5);
  tft.print("Home");

  tft.setTextSize(2);
  tft.setCursor(55, 2);
  tft.print(12);
  tft.setCursor(100, 2);
  tft.print(25);


tft.drawLine(15, 20, 0, 40, ST7735_ORANGE);
tft.drawLine(16, 20, 1, 40, ST7735_ORANGE);
tft.drawLine(14, 20, -1, 40, ST7735_ORANGE);
tft.drawLine(113, 20, 128, 40, ST7735_ORANGE);
tft.drawLine(114, 20, 129, 40, ST7735_ORANGE);
tft.drawLine(112, 20, 127, 40, ST7735_ORANGE);
tft.drawLine(0, 65, 15, 80, ST7735_ORANGE);
tft.drawLine(1, 65, 16, 80, ST7735_ORANGE);
tft.drawLine(-1, 65, 14, 80, ST7735_ORANGE);
tft.drawLine(128, 65, 113, 80, ST7735_ORANGE);
tft.drawLine(127, 65, 112, 80, ST7735_ORANGE);
tft.drawLine(129, 65, 114, 80, ST7735_ORANGE);
tft.drawFastHLine(15, 80, 98, ST7735_ORANGE);
tft.drawFastHLine(15, 81, 98, ST7735_ORANGE);

  tft.setTextSize(3);
  tft.setCursor(22, 30);
  tft.print("21:30");

  tft.setTextSize(2);
  tft.setCursor(30, 60);
  tft.print("Friday");

tft.drawFastVLine(65, 85, 22, ST7735_ORANGE);
tft.drawFastVLine(66, 85, 22, ST7735_ORANGE);
tft.drawFastVLine(67, 85, 22, ST7735_ORANGE);
tft.drawFastVLine(60, 115, 22, ST7735_ORANGE);
tft.drawFastVLine(59, 115, 22, ST7735_ORANGE);
tft.drawFastVLine(58, 115, 22, ST7735_ORANGE);
tft.drawFastHLine(80, 107, 22, ST7735_ORANGE);
tft.drawFastHLine(80, 106, 22, ST7735_ORANGE);


  tft.setTextSize(3);
  tft.setCursor(10, 85);
  tft.print("21C");

  tft.setTextSize(3);
  tft.setCursor(65, 115);
  tft.print("51%");

tft.drawLine(5, 150, 10, 140, ST7735_ORANGE);
tft.drawLine(6, 150, 11, 140, ST7735_ORANGE);
tft.drawLine(4, 150, 9, 140, ST7735_ORANGE);
tft.drawLine(5, 146, 10, 156, ST7735_ORANGE);
tft.drawLine(6, 146, 11, 156, ST7735_ORANGE);
tft.drawLine(4, 146, 9, 156, ST7735_ORANGE);

tft.drawLine(95, 150, 90, 140, ST7735_ORANGE);
tft.drawLine(96, 150, 91, 140, ST7735_ORANGE);
tft.drawLine(94, 150, 89, 140, ST7735_ORANGE);
tft.drawLine(95, 146, 90, 156, ST7735_ORANGE);
tft.drawLine(96, 146, 91, 156, ST7735_ORANGE);
tft.drawLine(94, 146, 89, 156, ST7735_ORANGE);

  tft.setTextSize(2);
  tft.setCursor(15, 140);
  tft.print("23 ppm");
}

void indicators(){
  tft.setTextColor(ST7735_GREEN);
tft.setTextSize(2);
tft.setCursor(5, 0);
tft.print("Indicators");

tft.drawFastHLine(0, 20, 128, ST7735_ORANGE);
tft.drawFastHLine(0, 19, 128, ST7735_ORANGE);

tft.drawRoundRect(5, 25, 118, 35, 15, ST7735_ORANGE);
tft.drawRoundRect(6, 26, 116, 33, 15, ST7735_ORANGE);
tft.drawRoundRect(4, 24, 120, 37, 15, ST7735_ORANGE);
  
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(3);
  tft.setCursor(40, 33);
  tft.print("21C");

tft.drawRoundRect(5, 65, 118, 35, 15, ST7735_ORANGE);
tft.drawRoundRect(6, 66, 116, 33, 15, ST7735_ORANGE);
tft.drawRoundRect(4, 64, 120, 37, 15, ST7735_ORANGE);

tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(3);
  tft.setCursor(40, 73);
  tft.print("53%");

tft.drawRoundRect(5, 105, 58, 48, 15, ST7735_ORANGE);
tft.drawRoundRect(6, 106, 56, 46, 15, ST7735_ORANGE);
tft.drawRoundRect(4, 104, 60, 50, 15, ST7735_ORANGE);

  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(2);
  tft.setCursor(21, 111);
  tft.print("23");

  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(2);
  tft.setCursor(19, 130);
  tft.print("ppm");

tft.drawCircle(95, 130, 25, ST7735_ORANGE);
tft.drawCircle(95, 130, 26, ST7735_ORANGE);
tft.drawCircle(95, 130, 24, ST7735_ORANGE);

  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);
  tft.setCursor(80, 120);
  tft.print("760");

  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(1);
  tft.setCursor(81, 138);
  tft.print("PT.CT");

}

  

 
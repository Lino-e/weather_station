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
 

  

 
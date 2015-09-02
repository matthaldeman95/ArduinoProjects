#include <DS3231.h>
#include <Time.h>
#include <Wire.h>


DS3231 Clock;
bool Century=false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

//Initialize Adafruit LED Backpacks
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
Adafruit_7segment matrix0 = Adafruit_7segment();
Adafruit_7segment matrix1 = Adafruit_7segment();
Adafruit_8x8matrix matrix2 = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix3 = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix4 = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix5 = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix7 = Adafruit_8x8matrix();


void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.begin(9600);
  matrix0.begin(0x70);
  matrix1.begin(0x71);
  matrix2.begin(0x72);
  matrix3.begin(0x73);
  matrix4.begin(0x74);
  matrix5.begin(0x75);
  matrix7.begin(0x77);
}

void loop() {
  ReadDs3231();
}

void ReadDs3231(){
  byte second, minute, hour, date, month, year;
  second = Clock.getSecond();
  minute=Clock.getMinute();
  //hour=Clock.getHour(h12, PM);
  date = Clock.getDate();
  month = Clock.getMonth(Century);
  year=Clock.getYear();
  //Serial.print("Current time and date: ");
  //Serial.print(month);  Serial.print("/");  
  //Serial.print(date);  Serial.print("/");  
  //Serial.print(year);  Serial.print("     ");
  //Serial.print(hour);  Serial.print(":");  Serial.print(minute);  Serial.print(":");  Serial.println(second);
  matrix0.clear();
  hour = 12;
  float htens = (hour)/10;
  if(htens < 1){
     matrix0.writeDigitNum(0x01, hour);
     matrix0.writeDisplay();
  }
  else{
    matrix0.writeDigitNum(0x00, 1);
    int newhour = (hour - 10);
    matrix0.writeDigitNum(0x01, newhour);
    matrix0.writeDisplay();
  }   
}


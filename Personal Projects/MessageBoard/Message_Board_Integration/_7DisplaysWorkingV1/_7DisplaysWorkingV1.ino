//Initialize I2C comm
#include <Wire.h> 

#include <Process.h>

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

//Initialize Real Time Clock
#include <DS3231.h>
#include <Time.h>
DS3231 Clock;
bool Century=false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

int temp;
String condition;
String data[3];


void setup() {
  Bridge.begin();
  Serial.begin(9600);
  matrix0.begin(0x70);
  matrix1.begin(0x71);
  matrix2.begin(0x72);
  matrix3.begin(0x73);
  matrix4.begin(0x74);
  matrix5.begin(0x75);
  matrix7.begin(0x77);
  
}

//Weather images storage
static const uint8_t PROGMEM
  sun_bmp[] =
  { B10010001,
    B01000010,
    B00011000,
    B00111101,
    B10111100,
    B00011000,
    B01000010,
    B10001001,};

void loop() {
  
  for(int dtcount = 0; dtcount<20; ++dtcount){

      //If first run through 20x loop, collect all HTML data and assign to array
      if(dtcount == 0){
        temp = writeTemp();
        data[0] =  getCond();
        data[1] = todayfc();
        data[2] = tomfc();
        data[3] = getDCULast();
      }

      //Read RTC time and write to 7-seg 0 every time
      
      writeTime();

       /*
      //Weather condition image led matrix, write every time
      
      matrix7.clear();
      matrix7.setTextSize(1);
      matrix7.setRotation(1);
      matrix7.setTextWrap(false);
      matrix7.drawBitmap(0, 0, sun_bmp, 8, 8, LED_ON);
      matrix7.writeDisplay();
      
      */
      //Run loop for every HTML string collected
      
      for(int i = 0; i < 4; ++i){
      
        int ins = i % 2;
        //Print loop number for debugging:
        //Serial.println(ins);
        
        //If loop number is even, write the data
        
        if(ins == 0){
        
          writeDate();
        }

        //If loop number is odd, write the temperature
        
        else if(ins == 1){
        
          Serial.println(temp);
          float temptens = (temp)/10;
          float temphunds = temp/100;
          if(temptens < 1){
            matrix1.clear();
            matrix1.writeDigitRaw(2, 0x10);
            matrix1.writeDigitNum(0x03, temp);
            matrix1.writeDisplay();
          }
          else if(temphunds < 1){
            float temps = temp - (temptens*10);
            matrix1.clear();
            matrix1.writeDigitRaw(2, 0x10);
            matrix1.writeDigitNum(0x01, temptens);
            matrix1.writeDigitNum(0x03, temps);
            matrix1.writeDisplay();
          }
        }
        //Write datastring in array with index i
        Serial.println(data[i]);
        int strl = data[i].length();
        int adjlength = (strl*8 + 16);

        matrix2.clear();  matrix3.clear();  matrix4.clear();  matrix5.clear();
        matrix2.setTextSize(1);  matrix3.setTextSize(1);  matrix4.setTextSize(1);  matrix5.setTextSize(1);  
        matrix2.setRotation(3);  matrix3.setRotation(3);  matrix4.setRotation(3);  matrix5.setRotation(3); 
        matrix2.setTextWrap(false); matrix3.setTextWrap(false);  matrix4.setTextWrap(false);  matrix5.setTextWrap(false);
        for(int n = 0; n>=-adjlength; n--){
          matrix2.clear(); matrix3.clear();   matrix4.clear();  matrix5.clear();
          matrix2.setCursor(n+24,0);  matrix3.setCursor(n+16,0);  matrix4.setCursor(n+8,0);  matrix5.setCursor(n,0);
          matrix5.print(data[i]);  matrix4.print(data[i]);  matrix3.print(data[i]);  matrix2.print(data[i]);
          matrix2.writeDisplay();  matrix3.writeDisplay();  matrix4.writeDisplay();  matrix5.writeDisplay();
          delay(30);
      }

        
    }
}

}



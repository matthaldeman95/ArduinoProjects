#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include <SparkFunMLX90614.h>

IRTherm therm;

// pin 13 - Serial clock out (SCLK)
// pin 11 - Serial data out (DIN)
// pin 10 - Data/Command select (D/C)
// pin 9 - LCD chip select (CS)
// pin 8 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 9, 10, 12);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16


int objtemp;
int ambtemp;
String unit = "F";


void setup() {
  Serial.begin(9600);

  display.begin();
  
  display.setContrast(50);
  
  display.clearDisplay();
  
  therm.begin();
  therm.setUnit(TEMP_F);
  
  pinMode(8, INPUT);
  
  
}

void loop() {
  if(digitalRead(8) > 0){
    if (therm.read()) // On success, read() will return 1, on fail 0.
    {
      // Use the object() and ambient() functions to grab the object and ambient
  	// temperatures.
  	// They'll be floats, calculated out to the unit you set with setUnit().
      Serial.print("Object: " + String(therm.object(), 2));
      Serial.write('°'); // Degree Symbol
      Serial.println("F");
      Serial.print("Ambient: " + String(therm.ambient(), 2));
      Serial.write('°'); // Degree Symbol
      Serial.println("F");
      Serial.println();
      objtemp = int(therm.object());
      ambtemp = int(therm.ambient());
      
    }
  }
  
  
  
    if(objtemp < 100 && objtemp > 9){
   
      display.clearDisplay();
      display.setTextSize(0.8);
      display.setTextColor(BLACK);
      display.setCursor(5,0);
      display.println("IRTherm V1.1");
      display.setTextSize(4);
      display.setCursor(20,10);
      display.print(objtemp);
      display.drawCircle(73, 13, 3, BLACK);
      display.setTextSize(2);
      display.setCursor(72, 23);
      display.println(unit);
      display.display();
      
    }
  
    else if(objtemp > 99){
      
      display.clearDisplay();
      display.setTextSize(0.8);
      display.setTextColor(BLACK);
      display.setCursor(5,0);
      display.println("IRTherm V1.1");
      display.setTextSize(4);
      display.setCursor(0, 10);
      display.print(objtemp);
      display.drawCircle(73, 13, 3, BLACK);
      display.setCursor(72, 23);
      display.setTextSize(2);
      display.println(unit);
      
      display.display();
    }
    
    else if (objtemp < 10 && objtemp > -1){
      display.clearDisplay();
      display.setTextSize(0.8);
      display.setTextColor(BLACK);
      display.setCursor(5,0);
      display.println("IRTherm V1.1");
      display.setTextSize(4);
      display.setCursor(30, 10);
      display.print(objtemp);
      display.drawCircle(73, 13, 3, BLACK);
      display.setCursor(72, 23);
      display.setTextSize(2);
      display.println(unit);
        
      display.display();
    }
    
    else if(objtemp < 0 && objtemp > -10){
      
      display.clearDisplay();
      display.setTextSize(0.8);
      display.setTextColor(BLACK);
      display.setCursor(5,0);
      display.println("IRTherm V1.1");
      display.setTextSize(4);
      display.setCursor(10, 10);
      display.print(objtemp);
      display.drawCircle(73, 13, 3, BLACK);
      display.setCursor(72, 23);
      display.setTextSize(2);
      display.println(unit);
        
      display.display();
    }
    
    else if(objtemp < -9){
      display.clearDisplay();
      display.setTextSize(0.8);
      display.setTextColor(BLACK);
      display.setCursor(5,0);
      display.println("IRTherm V1.1");
      display.setTextSize(4);
      display.setCursor(0, 10);
      display.print(objtemp);
      display.drawCircle(73, 13, 3, BLACK);
      display.setCursor(72, 23);
      display.setTextSize(2);
      display.println(unit);
        
      display.display();
    }
    
    display.setTextSize(1);
    display.setCursor(10, 40);
    display.print("Ambient: ");
    display.setCursor(65, 40);
    display.print(ambtemp);
    display.display();
}

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 10, 9, 8);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

void setup() {
  Serial.begin(9600);

  display.begin();
  
  display.clearDisplay();
  
}

void loop() {
  display.clearDisplay();
  display.drawCircle(42, 24, 20, BLACK);
  display.drawCircle(42, 24, 19, BLACK);
  display.display();
}

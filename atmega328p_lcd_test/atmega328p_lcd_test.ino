#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  float time = millis();
  lcd.setCursor(0,0);
  lcd.print("Current time: ");
  lcd.setCursor(8,0);
  lcd.print(time);
  lcd.setCursor(0,1);
  lcd.print("You are pretty today");
  
}

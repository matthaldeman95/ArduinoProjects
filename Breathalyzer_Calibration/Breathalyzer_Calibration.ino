#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup(){
  Serial.begin(9600); 
  lcd.begin(16,2); 
}

void loop(){
  int value = analogRead(A0);
  value = value >> 2;
  value *= 2;
  Serial.print("Sensor value: ");
  Serial.print(value);
  float voltage = value * (5.0 / 1023.0);
  Serial.print(", voltage: ");
  Serial.println(voltage);
  lcd.setCursor(0,0);
  lcd.print("Value: ");
  lcd.setCursor(8,0);
  lcd.print(value);
  lcd.setCursor(0,1);
  lcd.print("Volts: ");
  lcd.setCursor(8,1);
  lcd.print(voltage);
}

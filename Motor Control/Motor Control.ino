#include "LiquidCrystal_I2C.h"
#include "Wire.h"
#include "LCD.h"
#include <LiquidCrystal.h>
 
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7);
 
int potPin = 0;
int motorPin = 3;
int potValue = 0;
int motorValue = 0; 
 
void setup() {
 
pinMode(motorPin, OUTPUT);
pinMode(potPin, INPUT);
 
}
 
void loop() {
 
potValue = analogRead(potPin);
 
motorValue = map(potValue, 0, 1023, 0, 255);
analogWrite(motorPin, motorValue);
 
}
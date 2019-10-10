#include "LiquidCrystal_I2C.h"
#include "Wire.h"

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7);
int potPin = A4;
int led = 9;
int dial = 0; // variable to store the value coming form the sense
int bright = 0; // variable to store the output pin
void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.print("BRIGHTNESS:");
  pinMode(led, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  dial = analogRead(potPin); // reads the value form the sensor
  bright = map(dial, 0, 1023, 0, 255);
  dial = map(dial, 0, 1023, 0, 255); // converts from 0-1023 proportonal to the number from 0 to 255
  analogWrite(led, bright); // turn the led on depending on the potentiometer
  lcd.setCursor(0, 1);
  lcd.print(dial);
  lcd.print("     ");
}

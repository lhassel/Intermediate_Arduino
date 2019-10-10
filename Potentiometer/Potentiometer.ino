#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display.  
int potPin = A2;
int led = 9;
int dial = 0; // variable to store the value coming form the sense
int bright = 0; // variable to store the output pin
void setup()
{
	lcd.begin (16,2); // 16 x 2 LCD module
    lcd.init();
    lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("BRIGHTNESS:");
	pinMode(led, OUTPUT);
	pinMode(potPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	dial = analogRead(potPin); // reads the value form the sensor
	bright = map(dial, 0, 1023, 0, 255);
	dial = map(dial, 0, 1023, 0, 10); // converts from 0-1023 proportonal to the number from 0 to 255
	analogWrite(led, bright); // turn the led on depending on the potentiometer
	lcd.setCursor(0, 1);
	lcd.print(dial);
	lcd.print("     ");
}


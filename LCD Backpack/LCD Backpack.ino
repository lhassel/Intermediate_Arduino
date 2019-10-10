
#include "LiquidCrystal_I2C.h" // Added library*
//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display.  
// If 0x27 doesn't work, try 0x3F.
const int buttonPin = 7;
int buttonState = 0;  
int count= 0;   
int bp=0;
void setup()
{ 
   // Set off LCD module
   lcd.begin (16,2); // 16 x 2 LCD module
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Hello World");
   pinMode(buttonPin, INPUT);
   Serial.begin(9600);
}
void loop()
{
 buttonState = digitalRead(buttonPin);
 Serial.println(buttonState);
 if ((buttonState== HIGH) && (bp==0)){
 	count=count+1;
 	lcd.setCursor(0,1);
 	bp=1;
 	lcd.print(count);
 }
 if (buttonState== LOW) {
 	bp=0;
 }
}
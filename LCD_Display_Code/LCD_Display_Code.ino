#include <LiquidCrystal_I2C.h>

// ESP8266 Pin
// SCL = D1, SDA = D2, Vcc = Vin, GND = GND

LiquidCrystal_I2C lcd(0x27, 16, 2); 
// LiquidCrystal_I2C lcd(0x3F, 20, 4);


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello World");
  delay(1000);
  
  lcd.setCursor(0,1);
  lcd.print("Nayan");
  delay(800);

  lcd.clear();
}

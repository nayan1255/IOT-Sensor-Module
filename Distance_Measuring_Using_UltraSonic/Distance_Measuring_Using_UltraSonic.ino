// ESP8266 Pin
//
//int triggerpin = D4;  
//int echopin = D3;
//
//int triggerpin = D6;  
//int echopin = D5;
//
//int triggerpin = D1;  
//int echopin = D2;
 
long duration;  
int distance1;
int distance2;

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //SDA = D2 and SCL = D1 ; Vcc = Vin and Gnd = Gnd

void setup()
{  
  pinMode(triggerpin,OUTPUT);  
  pinMode(echopin,INPUT);
  //digitalWrite(LED,HIGH);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();  
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04"); // print some text in Serial Monitor
  Serial.println("with NODEMCU ESP8266");  
}  
  
void loop()
{  
  digitalWrite(triggerpin,HIGH);  
  delayMicroseconds(10);  
  digitalWrite(triggerpin,LOW);  
  duration=pulseIn(echopin,HIGH);  
  distance1 = duration * 0.034 / 2; //( speed of sound * time )/2
  Serial.print(" Total distance in cm : ");  
  Serial.println(distance1);
  delay(1000);
  distance2 = distance1 * 0.033;
  Serial.print(" Total distance in feet : ");  
  Serial.println(distance2);
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print(distance1);
  delay(1000);
  lcd.clear();
} 

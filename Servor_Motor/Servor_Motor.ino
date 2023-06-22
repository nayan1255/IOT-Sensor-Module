#include <Servo.h>

Servo myservo;

int ServoPin = D3;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(ServoPin);
  myservo.write(90);
  delay(2000);
}

void loop() 
{
  Serial.println("Degree 0");
  myservo.write(0);
  delay(2000);
  Serial.println("Degree 90");
  myservo.write(90);
  delay(2000);
  Serial.println("Degree 180");
  myservo.write(180);
  delay(2000);
  Serial.println("Degree 270");
  myservo.write(270);
  delay(2000);
  Serial.println("Degree 360");
  myservo.write(360);
  delay(2000);
}

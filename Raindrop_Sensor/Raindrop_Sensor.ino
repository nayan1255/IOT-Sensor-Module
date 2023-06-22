int sensor = D1;
int buzzer = D3;

int val = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() 
{
  int val = digitalRead(sensor);
//  Serial.print("Digital Output: ");
//  Serial.print(val);

  if (val == 1) {
    Serial.println("Status: Dry");
    digitalWrite(buzzer, LOW);
  } else {
    Serial.println("Status: Wet");
    digitalWrite(buzzer, HIGH);
  }

  delay(1000);
}



//// for ESP8266 Microcontroller
//#define rainAnalog A0
//#define rainDigital D1
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(rainDigital,INPUT);
//}
//void loop() {
//  int rainAnalogVal = analogRead(rainAnalog);
//  int rainDigitalVal = digitalRead(rainDigital);
//
//  Serial.print(rainAnalogVal);
//  Serial.print("\t");
//  Serial.println(rainDigitalVal);
//  delay(200);
//}

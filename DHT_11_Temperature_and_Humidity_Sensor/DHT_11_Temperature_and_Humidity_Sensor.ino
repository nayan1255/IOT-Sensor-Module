#include "DHT.h"

const int DHTTYPE = DHT11;

// DHT Sensor
uint8_t DHTPin = D1;

// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;

void setup()
{
  Serial.begin(9600);
  delay(100);
  pinMode(DHTPin, INPUT);
  dht.begin();
}
void loop()  
{  
  Serial.print("Temperature in C : ");  
  Serial.println((dht.readTemperature( )));  
  Serial.print("Humidity in C : ");  
  Serial.println((dht.readHumidity()));  
  delay(1000);  
}

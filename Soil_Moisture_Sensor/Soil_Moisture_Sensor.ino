int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */

float moisture_percentage;
float moisture;

void setup() 
{
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() 
{
  int value = analogRead(sensor_pin);

  moisture = (100.00 - (value / 1023.00));
  moisture_percentage = (moisture * 100.00);

  Serial.println("Soil Moisture(in value) = ");
  Serial.print(moisture);
  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");

  delay(1000);
}
int TOUCH_PIN = D1; // choose pin for the LED
int val = 0; // variable for reading the pin status

void setup() 
{
  Serial.begin(9600);
  pinMode(TOUCH_PIN, INPUT); // declare LED as output
}

void loop() 
{
  val = digitalRead(TOUCH_PIN); // read input value
  if (val == 1)
  {
    Serial.println("Sensor is touched");
  }
  else
  {
    Serial.println("Sensor is untouched");
  }
  
  delay(1000);
}

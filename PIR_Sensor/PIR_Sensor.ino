int sensor = D3;  // Digital pin D3

void setup() 
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);   // declare sensor as input
}
void loop() 
{
  long state = digitalRead(sensor);
  if(state == LOW)
  {
    Serial.println("Motion detected!");
    delay(1000);
  }
  else 
  {
    Serial.println("Motion absent!");
    delay(1000);
  }
}

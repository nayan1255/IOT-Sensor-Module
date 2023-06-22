int led = D0;
int flame = D1;

int val = 0;

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(flame, INPUT);
  Serial.begin(9600);
  
}

void loop() 
{
  val = digitalRead(flame);
  
  if (val == 1)
  {
    Serial.println("No Flame Detected");
    digitalWrite(led, LOW);
  }
  
  else
  {                               
    Serial.println("Flame Detected");
    digitalWrite(led, HIGH);
  }
}

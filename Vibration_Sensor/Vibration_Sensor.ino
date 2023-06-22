int sensor = D1;
int led = D2;

void setup() 
{
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);
}

void loop() 
{
  int val;
  
  val = digitalRead(led);
  
  if(val==0)
  {
    digitalWrite(led,HIGH);
  }

  else
  {
   digitalWrite(led,LOW);
  }
}
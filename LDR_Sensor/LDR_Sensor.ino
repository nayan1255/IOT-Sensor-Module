// // Analog Code

// int sensor_val;
// float intensity;

// const int ldr = A0;

// void setup() 
// {
//   Serial.begin(9600);
//   pinMode(ldr,INPUT);
// }

// void loop() 
// {
//   sensor_val = analogRead(ldr);
//   intensity = sensor_val * (5.0 / 1023.0);   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
//   Serial.println(intensity);
//   if (intensity <= 0.07)
//   {
//     Serial.println("Brightness");
//   }
//   else
//   {
//     Serial.println("Darkness");
//   }
//   delay(1000);
// }

// Digital Code

int ldr = D1;

void setup() 
{
  Serial.begin(9600);
  pinMode(ldr,INPUT);
}

void loop() 
{
  int sensor = digitalRead(ldr);
  
  //Serial.println(sensor);
  
  if (sensor == 0)
  {
    Serial.println("Sunny Day");
  }
  
  else
  {
    Serial.println("Cloudy Day");
  }
  delay(1000);
}

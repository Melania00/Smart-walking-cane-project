#include <Arduino.h>

const int trigPin = 9;
const int echoPin = 8;
const int motor = 5;
long duration = 0;

void setup()
{ 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

long distance(long time)
{
  long distanceCalc;
  distanceCalc = ((time * 0.034) / 2); // centimeters
  return distanceCalc;
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  long distanceCm = distance(duration);
  
  if (distanceCm <= 160 && distanceCm > 50) 
  {
    digitalWrite(motor,HIGH);
  }
  else
  {
    digitalWrite(motor,LOW);
  } 
  
  Serial.print("Distance = "); 
  Serial.print(distanceCm); 
  Serial.println (" cm");
  delay(500);
}

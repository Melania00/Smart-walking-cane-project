#include <Arduino.h>

const int trigPin = 9;
const int echoPin = 8;
const int motor = 5;
const int buzzerPin = 3;
const int buttonPin = 2;  
int buttonState = 0;    
int lastButtonState = 0;
unsigned long startTime = 0; 
const unsigned long longPressDuration = 1000; 
long duration = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
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
  if (distanceCm <= 160 && distanceCm > 10)
  {
    digitalWrite(motor, HIGH);
  }
  else
  {
    digitalWrite(motor, LOW);
  }
  if (distanceCm <= 50 && distanceCm > 0)
  {
    tone(buzzerPin, 500);
  }
  else
  {
    noTone(buzzerPin);
  }

  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) 
    {
    if (buttonState == LOW) 
    { 
      startTime = millis();
    } 
    else { 
      duration = millis() - startTime;
      if (duration >= longPressDuration) 
      { 
        noTone(buzzerPin);
      }
    }
      lastButtonState = buttonState;
    }
  
  Serial.print("Distance = ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  delay(500);
}

#include<Servo.h>

int button = 8;
int motor = 3;
int trigpin =11;
int echopin = 10;

void setup()
{
  pinMode(button, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(trigpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long x, inches;
  int buttonstate = digitalRead(button);
  while (buttonstate == 1)
  {
    inches = microsecondsToInches(x);
    delay(1000);
    Serial.print("Inches= ");
    Serial.println(inches);
    
    if (inches>10)
    {
      digitalWrite(motor, HIGH);
    }
    else
    {
      digitalWrite(motor, LOW);
    }
  }
}

double microsecondsToInches(long duration)
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  
  duration = pulseIn(echopin, HIGH);
  return duration / 74 /2;
}
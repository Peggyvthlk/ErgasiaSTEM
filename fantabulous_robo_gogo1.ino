#include <Servo.h>

Servo myServo;


const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 8;
const int servoPin = 11;

bool flag=false;

void setup() 
{
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  
  myServo.attach(servoPin);

  
  Serial.begin(9600);
}

void loop() 
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  
  if(distance < 10) 
  {
    flag=true;
    myServo.write(110);
    
    for(int i = 0; i < 5; i++) 
    {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
    
    myServo.write(0);
    
    do
    {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }while(flag==true);
     
    
  } 
  else 
  {
    flag=false;
    digitalWrite(ledPin, LOW);
    myServo.write(0);
  }
  
}


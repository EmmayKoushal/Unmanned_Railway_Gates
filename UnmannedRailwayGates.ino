#include<Servo.h>
int val1,val2;
int ledR = 13;
int ledG = 10;
int p1 = 12;
int p2 = 11;
Servo sm;
void setup()
{
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(val1,INPUT);
  pinMode(val2,INPUT);
  sm.attach(9);
  Serial.begin(9600);
}
void loop()
{
  val1 = digitalRead(p1);
  val2 = digitalRead(p2);
  if (val1 == HIGH && val2 == LOW){
    digitalWrite(ledG,LOW);
    digitalWrite(ledR,HIGH);
    sm.write(0);
    while(1)
{
      val1 = digitalRead(p1);
      val2 = digitalRead(p2);
      if (val1 == LOW && val2 == HIGH){
        digitalWrite(ledR,LOW);
        digitalWrite(ledG,HIGH);
        sm.write(90);
        delay(3000);
        break;
      }
    }
  }
  else if (val2 == HIGH && val1 == LOW){
    digitalWrite(ledG,LOW);
    digitalWrite(ledR,HIGH);
    sm.write(0);
    while(1)
    {
      val1 = digitalRead(p1);
      val2 = digitalRead(p2);
      if (val1 == HIGH && val2 == LOW){
        digitalWrite(ledR,LOW);
        digitalWrite(ledG,HIGH);
        sm.write(90);
        delay(3000);
        break;
      }
}
  }
  else if (val1 == LOW && val2 == LOW){
    digitalWrite(ledR,LOW);
    digitalWrite(ledG,HIGH);
    sm.write(90);
  }
  delay(10);
}

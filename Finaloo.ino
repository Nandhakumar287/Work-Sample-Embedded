#include<Servo.h>
Servo servo;
const int trigPin=2;
const int echoPin=0;
const int trigPin1=13;
const int echoPin1=15;
const int smokein=A0;
const int smokeout=10;
int pos;


long duration;
float distance;
long duration1;
float distance1;

float getDistance(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long duration=pulseIn(echoPin,HIGH);
  return(duration*0.034/2);
}

float getDistance1(){
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);

  

  long duration1=pulseIn(echoPin1,HIGH);
  return (duration1*0.034/2);
}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 pinMode(trigPin,OUTPUT);
 pinMode(trigPin1,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(echoPin1,INPUT);
 pinMode(smokein,INPUT);
 pinMode(smokeout,OUTPUT);

 servo.attach(5);
 servo.write(0);
 
 

}

void loop() {
  // put your main code here, to run repeatedly:
  int analogSensor=analogRead(smokein);  
distance=getDistance();
distance1=getDistance1();

Serial.println("Garbage Level:");
Serial.println(distance);
Serial.print("ln");
Serial.println("Methane Level:");
Serial.println(analogSensor);
Serial.println("-------------------------");
Serial.println("Garbage Open:");
Serial.println(distance1);

if(distance1<10){
  Serial.println("Door Open....");
  for(pos=0;pos<=180;pos +=20){
    servo.write(pos);
    delay(15);
  }

  delay(3000);
  
  for(pos=180;pos>=0;pos -=50){
    servo.write(pos);
    delay(15);
    
  }
}
else{
  Serial.println("Nothing Found");
}

}

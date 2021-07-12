#define trigPin 7
#define echoPin 8
#include <Servo.h> 
  

long duration; 
long StartT;//Time of start
int distance; 
  
Servo S1;
Servo S2;
Servo S3;
Servo S4;
Servo S5;
Servo S6;

void setup(){
Serial.begin(9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
S1.write(0); 
S2.write(0);
S3.write(0); 
S4.write(0); 
S5.write(0); 
S6.write(0); 

S1.attach(3);
S2.attach(5); 
S3.attach(6); 
S4.attach(9); 
S5.attach(10); 
S6.attach(11); 

  
while(!Serial)
    {
      
    }
  

    
  }
  

void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
  

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
  

Serial.print("Distance = ");
Serial.println(distance);
  
if(distance <=15){
     StartT = millis();
     while(distance <=15){
     if(millis() - StartT == 3000){
     Serial.println("3 Seconds :)");
     S1.write(90);
       S2.write(90);
       S3.write(90);
       S4.write(90);
       S5.write(90);
       S6.write(90);
     delay(100);
     
         break;
        } 
      }
    }
  else{
     delay(1000);
     S1.write(0);
       S2.write(0);
       S3.write(0);
       S4.write(0);
       S5.write(0);
       S6.write(0);
    }  
  }

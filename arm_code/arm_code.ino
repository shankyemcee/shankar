

#include <AFMotor.h>
#include <SoftwareSerial.h>
#define MOT1 7500
#define MOT2 7600
#define MOT3 7700
#define MOT4 7350
#define MOT5 2000
#define MOT5A 2000
SoftwareSerial mySerial(A1,A0);
AF_DCMotor mot1(1, MOTOR12_64KHZ);
AF_DCMotor mot2(2, MOTOR12_64KHZ);
AF_DCMotor mot3(3, MOTOR34_64KHZ);
AF_DCMotor mot4(4, MOTOR34_64KHZ);


int key=A2;
int motor1=A3;
int motor1a=A4;
int m;
int i;
int prev;
int n;
int Q;

void setup() {
  
mySerial.begin(57600);
pinMode(motor1,OUTPUT);
pinMode(key,INPUT);
pinMode(motor1a,OUTPUT);

mot1.setSpeed(255);
mot2.setSpeed(255);
mot3.setSpeed(255);
mot4.setSpeed(255);

Serial.begin(9600);
prev=0;
}



void loop() {
  if(digitalRead(key)==HIGH)
  {
    mySerial.println(600);delay(1000);
  }
  
 
if(mySerial.available())
{
m=mySerial.read();
Q=m-48;

if(Q<0)
{
;
}
else
{
m=Q;
}

n=m-prev;

if(m==9)
{
  LET_GO();
  exit(0);
}

if(n>0&&n<6)
{
  RUN_MORE();
}

else if(n<0&&n>-6)
{
  RUN_LESS();
}

else if (n==0)
  {
    ;
  }

mySerial.flush();



prev=m;

}
}



void RUN_MORE()
{

  for(i=prev+1;i<=m;i++)
  {
    if(i==1)
    {
      mot1.run(FORWARD);delay(MOT1);mot1.run(RELEASE);
    }
    if(i==2)
    {
      mot2.run(FORWARD);delay(MOT2);mot2.run(RELEASE);
    }
    if(i==3)
    {
      mot3.run(FORWARD);delay(MOT3);mot3.run(RELEASE);
    }
    if(i==4)
    {
      mot4.run(FORWARD);delay(MOT4);mot4.run(RELEASE);
    }
    if(i==5)
    {
      digitalWrite(motor1,HIGH);delay(MOT5);digitalWrite(motor1,LOW);
    }
    
  }
  mySerial.flush();



prev=m;

  
}

void RUN_LESS()
{
  n=prev-m;

  for(i=prev;i>m;i--)
  {
    if(i==1)
    {
      mot1.run(BACKWARD);delay(MOT1);mot1.run(RELEASE);
    }
    if(i==2)
    {
      mot2.run(BACKWARD);delay(MOT2);mot2.run(RELEASE);
    }
    if(i==3)
    {
      mot3.run(BACKWARD);delay(MOT3);mot3.run(RELEASE);
    }
    if(i==4)
    {
      mot4.run(BACKWARD);delay(MOT4);mot4.run(RELEASE);
    }
    if(i==5)
    {
      digitalWrite(motor1a,HIGH);delay(MOT5A);digitalWrite(motor1a,LOW);
    }
    
  }
  mySerial.flush();



prev=m;

 
}


  void LET_GO()
  {

for(i=1;i<=prev;i++)
  {
    if(i==1)
    {
      mot1.run(BACKWARD);delay(MOT1);mot1.run(RELEASE);
    }
    if(i==2)
    {
      mot2.run(BACKWARD);delay(MOT2);mot2.run(RELEASE);
    }
    if(i==3)
    {
      mot3.run(BACKWARD);delay(MOT3);mot3.run(RELEASE);
    }
    if(i==4)
    {
      mot4.run(BACKWARD);delay(MOT4);mot4.run(RELEASE);
    }
    if(i==5)
    {
      digitalWrite(motor1a,HIGH);delay(MOT5A);digitalWrite(motor1a,LOW);
    }
    
  }

  mySerial.flush();



prev=m;

  }

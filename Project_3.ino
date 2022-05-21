//up-right motor A,,,up-left motor B
//down-right motor D,,,,,down-left motor C
//vertical motors E, F
// arduino Mega 


#include<SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); 
int in1A= 22;
int in2A= 24;
int enA= 2;
int in3B= 26;
int in4B= 28;
int enB= 3;
int in1C= 30;
int in2C= 32;
int enC= 4;
int in3D= 34;
int in4D= 36;
int enD= 5;
int in1E= 38;
int in2E= 40;
int enE= 6;
int in3F= 42;
int in4F= 44;
int enF= 7;
int xVal;
int yVal;
int zVal;
int X;
int Y;
int Z;
int but1Val;
int but2Val;
int but3Val;
int but4Val;

int mSpeed = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(enE, OUTPUT);
  pinMode(enF, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in3B, OUTPUT);
  pinMode(in4B, OUTPUT);
  pinMode(in1C, OUTPUT);
  pinMode(in2C, OUTPUT);
  pinMode(in3D, OUTPUT);
  pinMode(in4D, OUTPUT);
  pinMode(in1E, OUTPUT);
  pinMode(in2E, OUTPUT);
  pinMode(in3F, OUTPUT);
  pinMode(in4F, OUTPUT);

  Serial.begin(38400);
  }

void loop() {
  
while (mySerial.available()>0)
 {  
   X= mySerial.read();
   Y= mySerial.read();
   Z= mySerial.read();
   but1Val= mySerial.read();
   but2Val= mySerial.read();
   but3Val= mySerial.read();
   but4Val= mySerial.read();
   }
 xVal= X*4;
 yVal= Y*4;
 zVal= Z*4;
 
 if (yVal<512 && xVal==512 && zVal==512){                           
  forward();
 }
 else if (yVal>=512 && xVal==512 && zVal==512){
  backward(); 
 }
 else if (yVal==512 && xVal>512 && zVal==512){
  right();
 }
 else if(yVal==512 && xVal<=512 && zVal==512){
  left();
 }
 else if(yVal==512 && xVal==512 && zVal<512){
  up();
 }
 else if(yVal==512 && xVal==512 && zVal>=512){
  down();
 }
 else if (but1Val==0){
  rotateR();
 }
 else if(but2Val==0){
  rotateL();
 }
 else if(but3Val==0){
  upA();
 }
 else(but4Val==0);{
  downAngle();
 } 
}     
 
  void forward()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, HIGH);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, HIGH);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, HIGH);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, LOW);
  mSpeed=-255./512.*yVal+255.;
  analogWrite(enA,mSpeed);
  analogWrite(enB,mSpeed);
  analogWrite(enC,mSpeed);
  analogWrite(enD,mSpeed);
  
}

void backward()
{
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, HIGH);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, HIGH);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, HIGH);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, LOW);
  mSpeed=(255./512.)*yVal-255.;
  analogWrite(enA,mSpeed);
  analogWrite(enB,mSpeed);
  analogWrite(enC,mSpeed);
  analogWrite(enD,mSpeed);
}

void right()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, HIGH);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, LOW);
  mSpeed=(255./512.)*yVal-255.;
  analogWrite(enA,mSpeed);
  analogWrite(enD,mSpeed);
}

void left()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, HIGH);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, HIGH);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, LOW);
  mSpeed=-255./512.*yVal+255.;
  analogWrite(enB,mSpeed);
  analogWrite(enC,mSpeed);
  
}

void up()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, HIGH);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, HIGH);
  mSpeed=-255./512.*yVal+255.;
  analogWrite(enE,mSpeed);
  analogWrite(enF,mSpeed);
}


void down()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, HIGH);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, HIGH);
  digitalWrite(in4F, LOW);
  mSpeed=(255./512.)*yVal-255.;
  analogWrite(enE,mSpeed);
  analogWrite(enF,mSpeed);
}
void rotateR (){
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, HIGH);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, HIGH);
  digitalWrite(in3D, HIGH);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, LOW);
}

void rotateL (){
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  digitalWrite(in3B, HIGH);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, HIGH);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, HIGH);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, LOW);

}

void upA()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, LOW);
  digitalWrite(in2E, HIGH);
  digitalWrite(in3F, HIGH);
  digitalWrite(in4F, LOW);

}
void downAngle()
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  digitalWrite(in3B, LOW);
  digitalWrite(in4B, LOW);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, LOW);
  digitalWrite(in3D, LOW);
  digitalWrite(in4D, LOW);
  digitalWrite(in1E, HIGH);
  digitalWrite(in2E, LOW);
  digitalWrite(in3F, LOW);
  digitalWrite(in4F, HIGH);

}

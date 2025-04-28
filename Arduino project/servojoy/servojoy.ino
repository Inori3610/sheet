// Servo 
#include <Servo.h>

Servo myservo1 , myservo2;
int posX=0;
int posY=0;
int speed = 19;


// Joystick
int joyX=A0;
int joyY=A1;
int xvalue;
int yvalue;

int xneu;
int yneu;


void setup() {
  // put your setup code here, to run once:
  // attach servo to pin ~9 
  myservo1.attach(5);
  myservo2.attach(6);
  Serial.begin(9600);
  xneu = analogRead(xvalue);
  yneu = analogRead(yvalue);
  //myservo.write(pos);
}

void loop() {
  // put your main code here, to run repeatedly:
  xvalue = analogRead(joyX);
  //yvalue = analogRead(joyY);

  Serial.print("X : ");
  Serial.print(xvalue);
  Serial.print("  Y : ");
  Serial.print(yvalue);
  //Serial.print(" X neu : ");
  //Serial.print(xneu);
  //Serial.print(" Y neu : ");
  //Serial.print(yneu);
  Serial.print("posX : ");
  Serial.print(posX);
  Serial.println("\t");
  
  if (xvalue>xneu) {
    posX=posX+1;
    myservo1.write(posX);
    Serial.print("posX : ");
    Serial.print(posX);
    delay(10);
  }
  if (xvalue<xneu) {
    posX=posX-1;
    myservo1.write(posX);
    Serial.print("posX : ");
    Serial.print(posX);
    delay(10);
  }
  if (yvalue>yneu) {
    posY=posY+1;
    myservo2.write(posY);
    Serial.print("posY : ");
    Serial.print(posY);
    delay(10);
  }
  if (yvalue<yneu) {
    posY=posY-1;
    myservo2.write(posY);
    Serial.print("posX : ");
    Serial.print(posY);
    delay(10);
  }
}

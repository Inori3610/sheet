#include <Servo.h>
Servo myservo,myservo2;

// joystick value

int xvalue;
int yvalue;


void setup() {
  // put your setup code here, to run once:

  myservo.attach(7);
  myservo2.attach(4);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  xvalue = analogRead(A0);
  xvalue = map(xvalue, 0, 1023, 0, 180);
  yvalue = analogRead(A1);
  yvalue = map(yvalue, 0 ,1023, 0, 180); //servo between 0-180

  //Console
  Serial.print("X Value : ");
  Serial.print(xvalue);
  Serial.print("Y Value : ");
  Serial.print(yvalue);
  Serial.println("");

  //Write servo
  myservo.write(xvalue);
  myservo2.write(yvalue);
  delay(500);

}

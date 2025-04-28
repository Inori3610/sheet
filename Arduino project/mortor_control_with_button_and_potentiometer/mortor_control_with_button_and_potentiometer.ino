// C++ code
// Control mortor forward and backward 
// with 2 button and 1 potentiometer to control speed

//pin use
const int forwwardPin =8;
const int backwardPin = 12;
const int butforward = 2;
const int butbackward = 4;
const int delayTime = 2000;
const int speedpin = 11;
//

int but1;
int but2;
int energy;




void setup()
{
  pinMode(forwwardPin,OUTPUT);
  pinMode(backwardPin,OUTPUT);
  pinMode(butforward, INPUT_PULLUP);   //INPUT_PULLUP for button
  pinMode(butbackward, INPUT_PULLUP); 
}

void loop()
{
  but1 = digitalRead(butforward);
  but2 = digitalRead(butbackward);
  
  int value = analogRead(A0);
  int energy = map (value,0,1023,0,255);       //map value 0 -> 1023 of potentiometer to 0 -> 255 value for speed
  analogWrite(speedpin,energy);
  
  
  if (but1 == HIGH) {                //if button not press nothing happen
    //spin forward
  digitalWrite(forwwardPin,LOW);
  }
  else{                              //spin if button has been press
  	digitalWrite(forwwardPin,HIGH);
  }
  if (but2 == HIGH){
    //spin backward
    digitalWrite(backwardPin,LOW);
  }
  else{
  	digitalWrite(backwardPin,HIGH);
  }
  
}// in the end i learn how to use potentoimeter and button great exm nice cook





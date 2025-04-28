
// joystick valueable
int joyX=A0;
int joyY=A1;
int xvalue;
int yvalue;

// neutrual

int xneu;
int yneu;

// LED pin

const int yellow1 = 10;
const int green = 9;
const int yellow2 = 6;
const int red = 11;

//brightness

int yellow1_b;
int green_b;
int yellow2_b;
int red_b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // neutural at start
  xneu = analogRead(xvalue);
  yneu = analogRead(yvalue);
}

void loop() {
  // put your main code here, to run repeatedly:
  xvalue = analogRead(joyX);
  yvalue = analogRead(joyY);

  Serial.print("X : ");
  Serial.print(xvalue);
  Serial.print("  Y : ");
  Serial.print(yvalue);
  Serial.print(" X neu : ");
  Serial.print(xneu);
  Serial.print(" Y neu : ");
  Serial.print(yneu);
  Serial.println("\t");
  
  if (yvalue>=yneu) {     //joystick left
    yellow1_b = 0;
    //yellow2_b= map(yvalue,yneu,1023,0,255);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  else {
    //yellow2_b =0;
    //yellow1_b = map(yvalue,yneu,1023,0,255);
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
  }

  if (xvalue>=xneu) {
    //green_b = 0;
    //red_b = map(xvalue,yneu,1023,0,255);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH) ;
  }
  else {
    //red_b =0;
    //green_b =map(xvalue,yneu,1023,0,255);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH) ;
  }

  /*analogWrite(yellow1,yellow1_b);
  analogWrite(green, green_b);
  analogWrite(yellow2, yellow2_b);
  analogWrite(red, red_b);*/


  /*digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);*/
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(500);
}

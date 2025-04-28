#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>

#include <Keypad.h>
 // rows and cols keypad
const int col = 4;
const int row = 4;
 //store cols and rows in a array
byte rowpin[row] = {5,4,3,2};    
byte colpin[col] = {6,7,12,13};  //{6,7,8,9};


//RGB LED pins
const byte blue = 9;
const byte red = 11;
const byte green = 10;
char keys [row][col] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','a','b','c'},
  {'d','e','g','f'}
};

char generatickey [row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'+','-','*','/'}
};

Keypad mykeypad = Keypad(makeKeymap(keys) , rowpin , colpin , row , col);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blue,OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char keyPressed = mykeypad.getKey(); 
  
  if (keyPressed) {
    Serial.print("button pressed in for simple if statement: ");
    Serial.println(keyPressed);
    Serial.print("button pressed in function: ");
    getButtonPressed(keyPressed);
  };
}

char getButtonPressed(char buttonPressed){
  
  byte r1 = random(0,255);
  byte r2 = random(0,255); 
  byte r3 = random(0,255);

  switch (buttonPressed) {
    case '1':
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
    case '2':
      analogWrite(red, 0);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;
    case '3':
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 255);
      break;
    case '4':
      analogWrite(red, 255);
      analogWrite(green, 128);
      analogWrite(blue, 0);
      break;
    case '5':
      analogWrite(red, 255);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;
    case '6':
      analogWrite(red,255);
      analogWrite(green, 255);
      analogWrite(blue, 255);
      break;
    case '7':
      return Serial.println('6');
      break;
    case '8':
      return Serial.println('B');
      break;
    case '9':
      return Serial.println('7');
      break;
    case 'a':
      return Serial.println('8');
      break;
    case 'b':
      return Serial.println('9');
      break;
    case 'c':
      return Serial.println('C');
      break;
    case 'd':
      return Serial.println('+');
      break;
    case 'e':
      analogWrite(red, 1);
      analogWrite(green, 1);
      analogWrite(blue, 1);
      break;
    case 'g':
      //rev();
      break;
    case 'f':
      analogWrite(red, r1);
      analogWrite(green, r2);
      analogWrite(blue, r3);
      break;
    
      
  }
}

/*void rev(){
  int color = 0;
  int plus = 1;
  for (int i = 1 ; i>0; i =0 ) {
    analogWrite(red, color);
    analogWrite(green, color);
    analogWrite(blue, color);
    color = color + plus;
    if (color <= 0 || color >= 255) {
      plus = -plus;
    }
  }
}*/

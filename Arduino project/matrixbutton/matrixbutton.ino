#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>

#include <Keypad.h>
 // rows and cols keypad
const int col = 4;
const int row = 4;
 //store cols and rows in a array
byte rowpin[row] = {5,4,3,2};    
byte colpin[col] = {6,7,12,13};  //{6,7,8,9};

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
  switch (buttonPressed) {
    case '1':
      return Serial.println(1);
      break;
    case '2':
      return Serial.println('2');
      break;
    case '3':
      return Serial.println('3');
      break;
    case '4':
      return Serial.println('A');
      break;
    case '5':
      return Serial.println('4');
      break;
    case '6':
      return Serial.println('5');
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
      return Serial.println('-');
      break;
    case 'g':
      return Serial.println('*');
      break;
    case 'f':
      return Serial.println('/');
      break;
    
      
  }
}

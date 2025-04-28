/*How to use a seven-segment LED display.                                       A
  created by the SriTu Tech team.                                            F     B
  Read the code below and use it for any of your creations.                     G
  Home Page                                                                  E     C
*/       //   A  B  C  D  E  G  F  .                                            D
byte pin[] = {2, 3, 4, 5, 6, 7, 8, 9};//arduino pin array
 
int number[10][8] = {//number array
  {1, 1, 1, 1, 1 ,0 ,1 ,1}, //0
  {0, 1, 1, 0, 0, 0, 0, 0},//1
  {1, 1, 0, 1, 1, 1, 0, 0},//2
  {1, 1, 1, 1, 0, 1, 0, 0},//3
  {0, 1, 1, 0, 0, 1, 1, 0},//4
  {1, 0, 1, 1, 0, 1, 1, 0},//5
  {1, 0, 1, 1, 1, 1, 1, 0},//6
  {1, 1, 1, 0, 0, 0, 0, 0},//7
  {1, 1, 1, 1, 1, 1, 1, 0},//8
  {1, 1, 1, 1, 0, 1, 1, 0},//9
};
 
void setup() {
  for (byte a = 0; a < 8; a++) {
    pinMode(pin[a], OUTPUT);//define output pins
  }
}
 
void loop() {
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 8; b++) {
      digitalWrite(pin[b], number[a][b]);//display numbers
    }
    delay(1000);//delay
  }
}

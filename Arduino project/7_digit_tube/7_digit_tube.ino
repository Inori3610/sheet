
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int G = 7;
int F = 8;

int btn1 = 12;
int btn2 = 10;
bool state;
int num = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);  //A                     A
  pinMode(B, OUTPUT);  //B                  F     B
  pinMode(C, OUTPUT);  //C                     G
  pinMode(D, OUTPUT);  //D                  E     C
  pinMode(E, OUTPUT);  //E                     D
  pinMode(G, OUTPUT);  //G
  pinMode(F, OUTPUT);  //F

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if(!digitalRead(9)&digitalRead(10)&!state){
    num++; 
  
    if(num>9)num=9;
    state=1;}
    if(digitalRead(9)&!digitalRead(10)&!state){
    num--; 
  
    if(num<0)num=0;
    state=1;}
  if(digitalRead(9)&digitalRead(10))state=0;*/
  
  num++;
  if (num>9) {
    num=0;
  }

  switch (num) {
    case 0:
    //0
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(F, HIGH);
      delay(1000);
      break;
    case 1:
      //1
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(G, LOW);
      digitalWrite(F, LOW);
      delay(1000);
      break;
    case 2:
      //2
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(F, LOW);
      delay(1000);
      break;
    case 3:
      //3
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(F, LOW);
      delay(1000);
      break;
    case 4:  
      //4

      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(F, HIGH);
      delay(1000);
      break;
    case 5:
      //5
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(F, HIGH);
      delay(1000);
      break;
    case 6:
      //6
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(F, HIGH);
      delay(1000);
      break;
    case 7:
      //7
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(G, LOW);
      digitalWrite(F, LOW);
      delay(1000);
      break;
    case 8:
      //8
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(F, HIGH);
      delay(1000);
      break;
    case 9:
      //9
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(F, HIGH);
      delay(1000);
      break;
  
  }
  
}

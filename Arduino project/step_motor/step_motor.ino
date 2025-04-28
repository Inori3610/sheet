


int stepper_Pin_1 = 3;
int stepper_Pin_2 = 4;
int stepper_Pin_3 = 5;
int stepper_Pin_4 = 6;

int speed = 2;

int step_number = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(stepper_Pin_1, OUTPUT);
  pinMode(stepper_Pin_2, OUTPUT);
  pinMode(stepper_Pin_3, OUTPUT);
  pinMode(stepper_Pin_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 1000; i++) {
    Step(false);
    delay(speed);
  }
  for (int i = 0; i < 1000; i++) {
    Step(true);
    delay(speed);
  }
}

void Step(bool dir){
  if (dir) {
    switch (step_number) {
      case 0:
        digitalWrite(stepper_Pin_1, HIGH);
        digitalWrite(stepper_Pin_2, LOW);
        digitalWrite(stepper_Pin_3, LOW);
        digitalWrite(stepper_Pin_4, LOW);
        break;
      case 1:
        digitalWrite(stepper_Pin_1, LOW);
        digitalWrite(stepper_Pin_2, HIGH);
        digitalWrite(stepper_Pin_3, LOW);
        digitalWrite(stepper_Pin_4, LOW);
        break;
      case 2:
        digitalWrite(stepper_Pin_1, LOW);
        digitalWrite(stepper_Pin_2, LOW);
        digitalWrite(stepper_Pin_3, HIGH);
        digitalWrite(stepper_Pin_4, LOW);
        break;
      case 3:
        digitalWrite(stepper_Pin_1, LOW);
        digitalWrite(stepper_Pin_2, LOW);
        digitalWrite(stepper_Pin_3, LOW);
        digitalWrite(stepper_Pin_4, HIGH);
        break;
    }
  }
  else {
    switch (step_number) {
      case 0:
        digitalWrite(stepper_Pin_1, LOW);
        digitalWrite(stepper_Pin_2, LOW);
        digitalWrite(stepper_Pin_3, LOW);
        digitalWrite(stepper_Pin_4, HIGH);
        break;
      case 1:
        digitalWrite(stepper_Pin_1, LOW);
        digitalWrite(stepper_Pin_2, LOW);
        digitalWrite(stepper_Pin_3, HIGH);
        digitalWrite(stepper_Pin_4, LOW);
        break;
      case 2:
        digitalWrite(stepper_Pin_1, LOW);
        digitalWrite(stepper_Pin_2, HIGH);
        digitalWrite(stepper_Pin_3, LOW);
        digitalWrite(stepper_Pin_4, LOW);
        break;
      case 3:
        digitalWrite(stepper_Pin_1, HIGH);
        digitalWrite(stepper_Pin_2, LOW);
        digitalWrite(stepper_Pin_3, LOW);
        digitalWrite(stepper_Pin_4, LOW);
        break;
    }
  }
  step_number++;
  if (step_number > 3) {
    step_number=0;
  }  
}

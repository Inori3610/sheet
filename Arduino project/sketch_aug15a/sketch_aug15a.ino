int DELAY_TIME = 1000;
int SHORT_DELAY_TIME = 1000;
int DIGITAL_PIN_12 = 12;
int DIGITAL_PIN_8 = 8;
int DIGITAL_PIN_7 = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(DIGITAL_PIN_12, OUTPUT);
  pinMode(DIGITAL_PIN_8, OUTPUT);
  pinMode(DIGITAL_PIN_7, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(DIGITAL_PIN_12, HIGH);
  delay(DELAY_TIME);
  digitalWrite(DIGITAL_PIN_12, LOW);
  digitalWrite(DIGITAL_PIN_8, HIGH);
  delay(SHORT_DELAY_TIME);
  digitalWrite(DIGITAL_PIN_8, LOW);
  digitalWrite(DIGITAL_PIN_7, HIGH);
  delay(DELAY_TIME);
  digitalWrite(DIGITAL_PIN_7, LOW);
}

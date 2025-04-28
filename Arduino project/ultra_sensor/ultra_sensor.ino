
int trigPin = 8;
int echoPin = 7;

float cm,inches,duration;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Thiet lap phien do
  //Tat thiet bi cam bien
  digitalWrite(trigPin,LOW);
  delay(2);
  //Bat thiet bi cam bien
  digitalWrite(trigPin,HIGH);
  delay(15);
  // after ditect turn off
  digitalWrite(trigPin,LOW);
  // S = v * t
  // v = 343.2 m/s
  // t = ?
  duration = pulseIn(echoPin,HIGH);
  // t = duration
  // pulseIn -> microsec 
  // Convert into cm and inch cm * 0,0343, inch * 0,0135
  cm = (duration/2) * 29.1;

  // print cm
  Serial.println("");
  Serial.print("Cm : ");
  Serial.print(cm);
  delay(500);
}


const int sensor = 8;
const int SAMPLE_TIME=10;
unsigned long millisCurrent = 0;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;

int sampleBufferValue= 0;
void setup() {
  // put your setup code here, to run once:
  //pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  millisCurrent = millis();
  millisElapsed = millisCurrent-millisLast;

  if(digitalRead(sensor)==LOW){
    sampleBufferValue++;
  }
  if (millisElapsed > SAMPLE_TIME) {
    Serial.println(sampleBufferValue);
    sampleBufferValue=0;
    millisLast = millisCurrent;
  }
}

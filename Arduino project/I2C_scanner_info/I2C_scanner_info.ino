#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("\nI2C Scanner");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device found at address 0x");
      Serial.println(address, HEX);
      delay(500);
    }
  }
}

void loop() {}
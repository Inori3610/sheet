#include <SPI.h>
#include <SD.h>

#define SD_CS_PIN 10  // Pin 10 for CS

// Create display object


void setup() {
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    while (1);  // Stop the program
  }
  Serial.println("SD card initialized successfully!");
  Serial.println("OLED : OK");
  // List files on the SD card
  File root = SD.open("/");
  while (true) {
    File file = root.openNextFile();
    if (!file) break;
    Serial.print("File: ");
    Serial.println(file.name());
    file.close();
  }
}

void loop() {
  // Nothing to do here
}
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

int number_frame = 0;
/*
  I2C example ESP_32

  GND -> GND
  VCC -> 3.3V
  SCL -> GPIO_22
  SDA -> GPIO_21
  
*/

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialize the OLED
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the common I2C address
    Serial.println(F("OLED initialization failed!"));
    for (;;); // Stop if display not found
  }

  display.clearDisplay();                 // Clear the screen
  display.setTextSize(1);                 // Set font size (1 is default, increase for larger text)
  display.setTextColor(SSD1306_WHITE);   // Set text color
  display.setCursor(0, 0);                // Set position (top-left corner)
  display.println(F("Hello, World!"));    // Print text to screen
  display.println(F("I am OLED 128x64"));
  display.display();                      // Display the text

  delay(2000);
}

void loop() {
  // Nothing to do in the loop for this static text example

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Frame : ");
  display.print(number_frame);
  
  display.display();
  number_frame++;
  

}
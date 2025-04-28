#include <Servo.h> // Include the Servo library

Servo myServo; // Create a servo object

void setup() {
  myServo.attach(3); // Attach the servo to pin 9
}

void loop() {
  myServo.write(180); // Move the servo to 180 degrees
  delay(1000);        // Wait for 1 second
  myServo.write(0);   // Move the servo back to 0 degrees
  delay(1000);        // Wait for 1 second
}

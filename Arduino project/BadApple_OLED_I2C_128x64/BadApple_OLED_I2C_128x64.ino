#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define pin for OLED display and SD card reader

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  64
#define OLED_RESET     -1
#define SD_CS_PIN      5
// ESP use CS_PIN 5

// Create new display object using I2C address 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Total Frame 
const int totalFrames = 3286;

// Current Frame
int frameNumber = 1;

// Used to pace frame updates for ~15 FPS 15/1 = 67ms
unsigned long lastFrameTime = 0;

// Function to draw a BMP frame from SD card onto the OLED.
//            OLD CODE FOR ESP32
void drawFrame(const char *filename){
  File bmpFile = SD.open(filename);
  // if file not the bmp file
  if (!bmpFile) {
    Serial.print("Failed to open file : ");
    Serial.println(filename);
    return;
  }
  //Read BMP header
  uint8_t header[54];
  if (bmpFile.read(header, 54) != 54){
    Serial.print("Failed to read BMP header");
    bmpFile.close();
    return;
  }
  // if file not .bmp
  if(header[0] != 'B' || header[1] != 'M'){
    Serial.println("Not a BMP file ! ");
    bmpFile.close();
    return;
  }
  // The header contains the offset where pixel data starts.
  // It's stored at offset 10 as a 32-bit little-endian integer
  uint32_t dataOffset = header[10]
                        | (header[11] << 8)
                        | (header[12] << 16)
                        | (header[13] << 24);
  // Seek to the pixel data position
  bmpFile.seek(dataOffset);

  //Create a buffer to hold the entire pixel data
  uint8_t frameBuffer[128];
  for (int i = 0; i < 1024; i += 128) {
    if (bmpFile.read(frameBuffer, 128) != 128) {
      Serial.println("Error reading frame data");
      bmpFile.close();
      return;
    }
  }
  
  bmpFile.close();

  //Display the frame onto the OLED.
  display.clearDisplay();

  // drawBitmap(x, y, bitmap_data, width, height, color)
  display.drawBitmap(0,0,frameBuffer,SCREEN_WIDTH,SCREEN_HEIGHT, SSD1306_WHITE);
  display.display();
}
// NEW ONE FOR ADRUINO WITH OPTIMIZE
/*void drawFrame(const char *filename) {
  File bmpFile = SD.open(filename);
  if (!bmpFile) {
    Serial.print("Failed to open file: ");
    Serial.println(filename);
    return;
  }

  // Skip the 54-byte BMP header
  bmpFile.seek(54);

  // Read and draw rows one at a time
  uint8_t rowBuffer[16];  // Buffer for a single row (128 pixels = 16 bytes)
  for (int y = 0; y < 64; y++) {
    bmpFile.read(rowBuffer, 16);
    for (int x = 0; x < 16; x++) {
      display.drawBitmap(x * 8, y, &rowBuffer[x], 8, 1, SSD1306_WHITE);  // Draw each byte
    }
  }

  bmpFile.close();
  display.display();
}*/



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.clearDisplay();
  Serial.println(F("Initializing OLED..."));
  display.println("Initializing OLED...");
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1); // Don't proceed, loop forever
  }
  display.println("OLED : OK");
  Serial.println(F("OLED initialized successfully."));

  if (!SD.begin(SD_CS_PIN)){
    Serial.println("SD card allocation failed ! ");
    while (1);
  }
  display.println("SD : OK");
  Serial.println("SD card & OLED initialized successfully.");
  display.display();
}


/*void loop() {
  if (millis() - lastFrameTime >= 67) {  // ~15 FPS
    char filename[32];
    sprintf(filename, "/converted/output%03d.bmp", frameNumber);
    drawFrame(filename);
    frameNumber = (frameNumber % totalFrames) + 1;  // Loop back to frame 1
    lastFrameTime = millis();
  }
}*/




void loop() {
  // put your main code here, to run repeatedly:
  // Maintain 15 FPS (67 ms per frame)
  Serial.print("Frame number: ");
  Serial.println(frameNumber);

  char filename[32];
  sprintf(filename, "/converted/output%03d.bmp", frameNumber);

  drawFrame(filename);

  frameNumber++;
  if (frameNumber > totalFrames) {
    frameNumber = 1;
  }

  delay(67); // Maintain ~15 FPS
}

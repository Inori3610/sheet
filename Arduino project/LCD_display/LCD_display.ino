#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd()





int value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Temperature : ");
  lcd.print(value);
  delay(1000);
}

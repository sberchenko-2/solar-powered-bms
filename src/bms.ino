#include "utils.h"
#include <LiquidCrystal_I2C.h>

// I2C addr found by I2C scan: https://playground.arduino.cc/Main/I2cScanner/
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Hello World!");
    lcd.setCursor(0, 1);
    lcd.print("  - UW Solar <3");
}

void loop() {
}
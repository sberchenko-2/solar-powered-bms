#include <SPI.h>
#include <Adafruit_GFX.h> 
#include <MCUFRIEND_kbv.h>
#include "voltmeter.h"
#include "display.h"

void setup(void) {
    setup_bms();
    setup_display();
    setup_battery();
}

void loop() {
    unsigned long curr = millis();
    float val = ((float)curr) / 10000.0 * 100.0;  // should take 10s to fill to 100%
    update_battery(val);

    float Vin = read_voltage();

    int ts = 15;
    /*
    tft.setTextColor(WHITE);
    tft.setCursor(50, tft.height() / 6 - ts);
    tft.print("Voltage: ");
    tft.setCursor(200, tft.height() / 6 - ts);
    tft.print(Vin);
    */

    if (val < 100) {
        tft.setCursor(70, 5 * tft.height() / 6 - ts);
        tft.print("Charging...");
    } else if (val > 100 && val < 101) {
        tft.setTextColor(BLACK);
        tft.setCursor(70, 5 * tft.height() / 6 - ts);
        tft.print("Charging...");
    } else {
        tft.setTextColor(WHITE);
        tft.setCursor(90, 5 * tft.height() / 6 - ts);
        tft.print("Charged!");
    }

    /*
    tft.setTextColor(BLACK);
    tft.setCursor(200, tft.height() / 6 - ts);
    tft.print(Vin);
    */
}
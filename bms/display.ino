#include "display.h"

// TFT is initially vertically and is then rotated, so width / height are swapped when we #include display.h
int WIDTH  = tft.height();
int HEIGHT = tft.width();

// Battery-outline vars
int battery_r = 3;
int battery_w = WIDTH  / 2;
int battery_h = HEIGHT / 3;
int battery_x = (WIDTH  - battery_w) / 2;
int battery_y = (HEIGHT - battery_h) / 2;

// Battery-inner vars
int BRD_SIZE = 10;  // Size of battery border in pixel
int inner_x = battery_x + BRD_SIZE;
int inner_y = battery_y + BRD_SIZE;
int inner_w = battery_w - 2 * BRD_SIZE;
int inner_h = battery_h - 2 * BRD_SIZE;

// Battery front vars
int front_x_pad = 5;
int front_y_pad = 10;
int front_r = 5;
int front_x = battery_x + battery_w + front_x_pad;
int front_y = battery_y + front_y_pad;
int front_w = 10;
int front_h = battery_y - 2 * front_y_pad;

void setup_display() {
    tft.begin(tft.readID());
    tft.setRotation(1);
    tft.fillScreen(BLACK);
    tft.setTextSize(3);
}

void setup_battery() {
    // Draw battery outline
    tft.fillRoundRect(battery_x, battery_y, battery_w, battery_h, battery_r, WHITE);

    // Draw battery front
    tft.fillRoundRect(front_x, front_y, front_w, front_h, front_r, WHITE);
    
    // Draw black inside 
    tft.fillRect(inner_x, inner_y, inner_w, inner_h, BLACK);
}

void update_battery(float prct) {
    // Battery-charge vars
    prct = prct > 100 ? 100 : prct;  // Ceil  battery charge
    prct = prct < 0   ? 0   : prct;  // floor battery charge
    prct /= 100;
    int charge_w = inner_w * prct;

    // Set color based on charge level
    int charge_c = tft.color565(255 * (1 - prct), 255 * prct, 0);

    // Draw battery charge level
    tft.fillRect(inner_x, inner_y, charge_w, inner_h, charge_c);
}
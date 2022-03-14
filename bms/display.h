/**
 * @file display.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#define LCD_CS A3       // Chip Select goes to Analog 3
#define LCD_CD A2       // Command/Data goes to Analog 2
#define LCD_WR A1       // LCD Write goes to Analog 1
#define LCD_RD A0       // LCD Read goes to Analog 0
#define LCD_RESET A4    // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

MCUFRIEND_kbv tft;

void setup_display();

void setup_battery();

void update_battery(float prct);

#endif // DISPLAY_H_
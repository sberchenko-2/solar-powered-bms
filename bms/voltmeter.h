/**
 * @file voltmeter.h
 * @author Sasha Berchenko
 * @brief Contains code to read voltage via BMS
 * @date 2022-03-13
 * 
 * Contains code to perform Battery Management System operations such as read voltage
 */

#ifndef VOLTMETER_H_
#define VOLTMETER_H_

/// Analog pin used to read voltage
#define BMS_PIN 15

/// Resistance of R1
float R1 = 2200;

/// Resistance of R2
float R2 = 2200;

/**
 * @brief Sets up the BMS
 */
void setup_bms();

/**
 * @brief Reads the voltage on BMS_PIN
 * 
 * An accurate reading is optained by comparing to interal 5V reference
 * 
 * @return float The voltage reading
 */
float read_voltage();

#endif // VOLTMETER_H_
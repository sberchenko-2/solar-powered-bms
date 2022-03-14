#include "voltmeter.h"

void setup_bms() {
    pinMode(BMS_PIN, INPUT);
}

float read_voltage() {
    int val = analogRead(BMS_PIN); 

    // Squash divide-by-zero warnings
    if (R2 == 0 || R1 == 0) {
        return -1;
    }
    
    // Calculate Voltage Out and Voltage In
    float Vout = (val * 5.00) / 1024.00; 
    float Vin = Vout / (R2/(R1+R2));    
    
     // squash low vals
    if (Vin < .1) {
        Vin = .0;  
    } 

    return Vin;
}
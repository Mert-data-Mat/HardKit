#pragma once
#include <Arduino.h>
#include <stdint.h>

namespace HardKit {

class Potentiometer {
public:
  // Read raw ADC value (0–1023)
  static int readRaw(uint8_t pin) {
    return analogRead(pin);
  }

  // Read voltage in millivolts (default Vref = 5000 mV)
  static float readMilliVolts(uint8_t pin, float vRef_mV = 5000.0f) {
    return (analogRead(pin) / 1023.0f) * vRef_mV;
  }

  // Map ADC reading 0–1023 to any range (e.g., 0–180)
  static float mapRange(uint8_t pin, float outMin, float outMax) {
    float val = analogRead(pin);
    return outMin + (val / 1023.0f) * (outMax - outMin);
  }
};

// Optional convenience wrappers so I can call functions directly instead of using blabla::readraw()
inline int   readRaw(uint8_t pin)                               { return Potentiometer::readRaw(pin); }
inline float readMilliVolts(uint8_t pin, float vRef_mV = 5000)  { return Potentiometer::readMilliVolts(pin, vRef_mV); }
inline float mapRange(uint8_t pin, float outMin, float outMax)  { return Potentiometer::mapRange(pin, outMin, outMax); }

} 

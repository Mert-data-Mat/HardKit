#pragma once
#include <Arduino.h>
#include <stdint.h>
//
// HardKit - Potentiometer Simple Module
//
// Provides basic analog reading and scaling helpers for potentiometers.
// Converts analog readings (0–1023) into voltage or custom mapped ranges.
//

namespace HardKit {

class PotentiometerSimple {
public:
  // Read raw ADC value (0–1023)
  static int readRaw(uint8_t pin) {
    return analogRead(pin);
  }

  // Read voltage in millivolts (default reference = 5000 mV)
  static float readMilliVolts(uint8_t pin, float vRef_mV = 5000.0f) {
    return (analogRead(pin) / 1023.0f) * vRef_mV;
  }

  // Map ADC reading from 0–1023 to any range (e.g., 0–180)
  static float mapRange(uint8_t pin, float outMin, float outMax) {
    float val = analogRead(pin);
    return map(val, 0, 1023, outMin, outMax);
  }
};

} // namespace HardKit

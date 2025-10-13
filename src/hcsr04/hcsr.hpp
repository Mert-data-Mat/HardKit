#pragma once
#include <Arduino.h>
#include <stdint.h>

namespace HardKit {

class HCSR04Simple {
public:
  void attach(uint8_t trigPin, uint8_t echoPin) {
    _trig = trigPin;
    _echo = echoPin;
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    digitalWrite(_trig, LOW); // ensure idle low
    delayMicroseconds(5);
  }

  // Returns true on success; false on timeout or out-of-range.
  // Typical range: ~2–400 cm.(Factory spec but I ll use 3 for the minimum value) timeout_ms default ~30 ms (~5 m roundtrip).
  bool readCm(uint16_t& out_cm, uint16_t timeout_ms = 30) {
    // 10 µs trigger pulse
    digitalWrite(_trig, LOW);  delayMicroseconds(2);
    digitalWrite(_trig, HIGH); delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    unsigned long dur_us = pulseIn(_echo, HIGH, (unsigned long)timeout_ms * 1000UL);
    if (dur_us == 0) return false; // timeout

    // HC-SR04: distance (cm) ≈ duration_us / 58.0  (round-trip to one-way)
    float cmf = dur_us / 58.0f;

    // basic sanity range (adjusted to min value 3 bc around 2.3 when i try the sensor get freaky)
    if (cmf < 3.0f || cmf > 400.0f) return false;

    out_cm = static_cast<uint16_t>(cmf + 0.5f); // round to nearest
    return true;
  }

private:
    uint8_t _trig = 255, _echo = 255;
};

} // namespace HardKit

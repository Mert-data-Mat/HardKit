//
// HardKit - Servo Simple Module
// v0.1.0
//
// Provides a small, clean wrapper around Arduino's Servo library.
// Lets you control servo angles in degrees easily and safely.
//
#pragma once
#include <Arduino.h>
#include <Servo.h>

namespace HardKit {

struct ServoConfig {
  float minDeg = 0.0f;     // minimum angle (degrees)
  float maxDeg = 360.0f;   // maximum angle (degrees)
  uint16_t minUs = 1000;   // PWM pulse width at minDeg
  uint16_t maxUs = 2000;   // PWM pulse width at maxDeg
};

class ServoSimple {
public:
  ServoSimple() = default;

  // attach the servo to a pin with optional config
  void attach(uint8_t pin, const ServoConfig &c = {}) {
    cfg = c;
    hw.attach(pin, cfg.minUs, cfg.maxUs);
  }

  // set servo angle in degrees (automatically clamped)
  void writeDeg(float deg) {
    if (deg < cfg.minDeg) deg = cfg.minDeg;
    if (deg > cfg.maxDeg) deg = cfg.maxDeg;
    hw.write(static_cast<int>(deg));
  }

  // directly write pulse width in microseconds (manual control)
  void writeUs(uint16_t us) {
    hw.writeMicroseconds(us);
  }

  // simple detach
  void detach() {
    hw.detach();
  }

private:
  Servo hw;          // Arduino's built-in Servo object
  ServoConfig cfg{}; // current config
};

}

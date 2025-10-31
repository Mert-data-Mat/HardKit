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
  float minDeg = 0.0f;     // minimum angle
  float maxDeg = 180.0f;   // most of the servos maximum angle (degrees)
  uint16_t minUs = 500;   // PWM pulse width at minDeg
  uint16_t maxUs = 2500;   // PWM pulse width at maxDeg / turned out 1000-2000 is not enough range for servo the use full capability.
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


private:
  Servo hw;          // Arduino's built-in Servo object
  ServoConfig cfg{}; // current config
};

}
// I also add a support for the 360 degree servos.

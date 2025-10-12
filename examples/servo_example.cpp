#include <HardKit.hpp>   // pulls in HardKit::Servo
using namespace HardKit;

ServoSimple s;

void setup() {
  s.attach(9);           // D9 = servo signal pin should be attached to D9.
}

void loop() {
  // Sweep up
  for (int deg = 0; deg <= 180; deg += 1) {
    s.writeDeg(deg);
    delay(10);           // Increasing the degree one by one to observe the smoothens of the servo.
  }
  // Sweep down
  for (int deg = 180; deg >= 0; deg -= 1) {
    s.writeDeg(deg);
    delay(10);          // Going back one by one
  }
}


/*
  HardKit - Servo Sweep Minimal Example
  -------------------------------------
  This example demonstrates basic servo movement using the HardKit library.

  Purpose:
  To verify that your servo is wired correctly and that the HardKit::ServoSimple
  module works as expected.

  Description:
  The servo gradually moves from 0° to 180° and then back to 0° in small steps.
  Each step waits 10 ms to create a smooth sweeping motion.

  Wiring:
  - Servo signal  → D9
  - Servo + (red) → 5V or external 5–6V supply
  - Servo GND     → GND
  - If using an external power supply for the servo,
    make sure to connect its GND to the Arduino GND.

  Notes:
  - If your servo vibrates or makes noise at the ends,
    reduce the motion range (e.g., sweep between 10° and 170°).
  - If your board resets during motion, power the servo
    from a separate 5–6V buck converter and share GNDs.
*/

#include <HardKit.hpp>   // pulls in HardKit::Servo
using namespace HardKit;

ServoSimple s;

void setup() { 
  s.attach(9);
}
void loop() {
  // Sweep up
  for (int deg = 0; deg <= 180; deg += 1) {
    s.writeDeg(deg);
    delay(30);           // Increasing the degree one by one to observe the smoothens of the servo.
  }
  // Sweep down
  for (int deg = 180; deg >= 0; deg -= 1) {
    s.writeDeg(deg);
    delay(30);          // Going back one by one
  }
}

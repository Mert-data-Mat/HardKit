
#include <Arduino.h>
#include <HardKit.hpp>
using namespace HardKit;

ServoSimple servo;
PotentiometerSimple pot;

void setup() {
  Serial.begin(9600);
  servo.attach(9);  // D9 → servo signal pin
}

void loop() {
  int raw = pot.readRaw(A0);
  float angle = pot.mapRange(A0, 0, 180);

  servo.writeDeg(angle);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Angle: ");
  Serial.println(angle);

  delay(50);
}

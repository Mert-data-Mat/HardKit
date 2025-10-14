#include <HardKit.hpp>
#include <Arduino.h>

using namespace HardKit;

PotentiometerSimple pot;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = readRaw(A0);
  float mv = readMilliVolts(A0);
  float angle = mapRange(A0, 0, 180);
  Serial.print("\nRaw: ");
  Serial.print(raw);
  Serial.print("\nVoltage: ");
  Serial.print(mv);
  Serial.print(" mV");
  Serial.print("\nAngle (mapped 0 to 180) :");
  Serial.print(angle);
  delay(1000);
}

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

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Voltage: ");
  Serial.print(mv);
  Serial.println(" mV");

  delay(100);
}

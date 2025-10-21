#include <HardKit.hpp>
using namespace HardKit;

Ens160Aht air;                      // create sensor object

void setup() {
  Serial.begin(115200);
  air.begin();                      // start both sensors
}

void loop() {
  Ens160Aht::Data d;                // make a box for results
  if (air.read(d)) {                // if data is ready
    Serial.print("T: "); Serial.print(d.tC - 3); //Subtracted 3 bc heat from the other sensors raw results are not accurate.
    Serial.print(" °C  H: "); Serial.print(d.rH);
    Serial.print("%  AQI: "); Serial.print(d.aqi); // AQI stands for Air Quality Index, 1 is better
    Serial.print("  TVOC: "); Serial.print(d.tvoc_ppb); //Total volatile organic compounds ??
    Serial.print(" ppb  eCO2: "); Serial.print(d.eco2_ppm); // 400 - 600 perfect | > 2000 very poor 
    Serial.println(" ppm");
  } else {
    Serial.println("Sensor not ready yet");
  }
  delay(1000);
}

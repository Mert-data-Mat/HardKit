#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include "ScioSense_ENS160.h"

namespace HardKit {

class Ens160Aht {
public:
  struct Data {
    float    tC        = 0.0;   // temperature (°C)
    float    rH        = 0.0;   // relative humidity (%)
    uint8_t  aqi       = 0;     // 1..5 (0 = not ready)
    uint16_t tvoc_ppb  = 0;     // ppb
    uint16_t eco2_ppm  = 0;     // ppm
  };

  // Call once in setup(). Returns true if both sensors initialized.
  bool begin(uint8_t ensAddr = ENS160_I2CADDR_1) {
    Wire.begin();

    _ens = ScioSense_ENS160(ensAddr);
    _ens.begin();                         // some forks have no return
    _ensOK = _ens.available();

    if (_ensOK) {
      _ens.setMode(ENS160_OPMODE_STD);    // standard mode
      delay(2000);                        // short warmup (full stability ~30–60 s)
    }

    _ahtOK = _aht.begin(&Wire);
    return _ensOK && _ahtOK;
  }

  bool available() const { return _ensOK && _ahtOK; }

  // Reads AHT (T/H), feeds ENS160 env data, then reads AQI/TVOC/eCO2.
  // Returns true if AQI is valid (>0).
  bool read(Data& out) {
    if (!available()) return false;

    sensors_event_t hum, temp;
    _aht.getEvent(&hum, &temp);
    out.tC = temp.temperature;
    out.rH = hum.relative_humidity;

    _ens.set_envdata(out.tC, out.rH);
    _ens.measure(true);                   // harmless if not required by your fork

    out.aqi      = _ens.getAQI();         // 1..5 (0 = not ready)
    out.tvoc_ppb = _ens.getTVOC();        // ppb
    out.eco2_ppm = _ens.geteCO2();        // ppm

    return out.aqi != 0;
  }

private:
  ScioSense_ENS160 _ens{ENS160_I2CADDR_1};
  Adafruit_AHTX0   _aht;
  bool _ensOK = false;
  bool _ahtOK = false;
};

}

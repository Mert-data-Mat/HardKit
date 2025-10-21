# 🧰 HardKit
**Modular Arduino Hardware Toolkit**

---

##  Overview
HardKit is a lightweight, modular library for Arduino designed to make testing and building hardware easy.  
It brings together servos, sensors, and other components under one simple, consistent interface.  

The goal is to **spend less time writing boilerplate code** and more time actually testing and creating things.  
Just plug in your hardware, include HardKit, and start experimenting.

---

##  Current Modules
| Module | Description |
|---------|--------------|
| **ServoSimple** | Control standard hobby servos with easy degree or microsecond commands. |
| **PotentiometerSimple** | Read analog values and convert them to voltage or angle. |
| **HC-SR04** | Measure distance with one simple call using an ultrasonic sensor. |
| **ENS160** | Read air quality, temperature, and humidity (ENS160 + AHT21 combo). |

These modules are already working in the library.  
I’m improving and expanding HardKit a little bit every day.

---

##  Installation
1. Copy the **HardKit** folder into your Arduino `libraries/` directory.  
2. Restart the Arduino IDE.  
3. Open any example from **File → Examples → HardKit**.

---

##  Design Goals
- Keep everything **simple and consistent** across all modules.  
- Require **minimal setup and wiring** — plug and go.  
- Provide **clean, readable examples** that show exactly how things work.  
- Make it **easy to expand** with new hardware later on.  

---

## 🔧 Next Goals
- Improve ENS160 calibration and stability  
- Add Hall sensor (RPM counter)  
- Add battery voltage monitor  
- Create combined “Hardware Test Bench” example  

---

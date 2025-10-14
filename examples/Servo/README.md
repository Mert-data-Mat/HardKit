
   HardKit - Servo Sweep Minimal Example
   -------------------------------------
   This example demonstrates basic servo movement using the HardKit library.
 
   Purpose:
   To verify that your servo is wired correctly and that the HardKit::ServoSimple
   module works as expected.
 
   Description:
   The servo gradually moves from 0° to 180° and then back to 0° in small steps.
   Each step waits 10 ms to create a smooth sweeping motion.
   I am using the cheap SG90 Servo from Aliexpress and it supports 180 degrees. If you are using something else you may wanna update the src file !
 
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
 

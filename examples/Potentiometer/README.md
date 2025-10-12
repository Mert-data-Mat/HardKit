HardKit - Potentiometer Read Serial Example
  -------------------------------------------
  This example reads values from a potentiometer using the HardKit library
  and prints them to the serial monitor.

  Purpose:
  To verify that the potentiometer input and analog reading functions work
  correctly through the HardKit::PotentiometerSimple module.

  Description:
  The potentiometer’s center pin (wiper) is connected to the analog input A0.
  Turning the knob changes the voltage between 0V and 5V.
  The code reads the raw ADC value, converts it to millivolts, and prints both.

  Wiring:
  - Potentiometer left pin   → GND
  - Potentiometer middle pin → A0
  - Potentiometer right pin  → 5V

  Notes:
  - Open the Serial Monitor (Ctrl+Shift+M) and set baud rate to 9600.
  - Rotate the knob slowly; you should see values changing smoothly.
  - If readings jump or flicker, check wiring and ensure a solid GND connection.

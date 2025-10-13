HardKit - Servo From Potentiometer Example
  ------------------------------------------
  This example demonstrates controlling a servo motor with a potentiometer
  using the HardKit library.

  Purpose:
  To verify that both the HardKit::ServoSimple and HardKit::PotentiometerSimple
  modules work correctly together.

  Description:
  The potentiometer’s analog value (0–1023) is read and mapped to a servo angle
  between 0° and 180°. Rotating the knob changes the servo’s position smoothly
  in real time.

  Wiring:
  - Potentiometer left pin   → GND
  - Potentiometer middle pin → A0
  - Potentiometer right pin  → 5V
  - Servo signal pin         → D9
  - Servo + (red)            → 5V or external 5–6V
  - Servo GND                → GND
  - If using external servo power, connect its GND to Arduino GND.

  Functions:
  - PotentiometerSimple::readRaw(pin)
      Reads the raw analog-to-digital value (0–1023).

  - PotentiometerSimple::mapRange(pin, outMin, outMax)
      Maps the potentiometer reading into a specific range (e.g., 0–180°).

  - ServoSimple::attach(pin)
      Attaches the servo signal line to a specified pin.

  - ServoSimple::writeDeg(deg)
      Moves the servo to the specified angle in degrees.

  Notes:
  - Open the Serial Monitor (Ctrl+Shift+M) at 9600 baud to see raw and angle data.
  - If the servo buzzes or jitters, reduce motion range (e.g., 10°–170°).
  - Ensure your potentiometer and servo share a common ground.

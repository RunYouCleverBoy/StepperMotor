#include <StepperMotor.h>

// Stepper monitor instantiation. Of course it can be instantiated with "new StepperMotor(stride, coil1, coil2, coil3, coil4)"
// I connected my cheap 28BYJ-48 stepper In1, 2, 3 and 4 to pin 2, 3, 4 and 5 respectively.
// In the spec it says: Stride Angle 5.625/64 degrees. That's all I had to copy in... The stride angle.
StepperMotor stepper(5.625/64, 2, 3, 4, 5);
void setup() {
  // Set RPM... As in Revolutions Per Minute.
  stepper.setRpm(10);
}

void loop() {
  // Step. In ANGLES, because we are human and we have machines to compute steps for us.
  // Step is blocky. To avoid heating, it will set all the pins to LOW when done.
  stepper.step(90);
  delay(1000);
  
  // 15 degrees, counter clockwise.
  stepper.step(-15);
  delay(1000);
}

#ifndef __STEPPER_MOTOR_H__
#define __STEPPER_MOTOR_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class StepperMotor {
public:
  StepperMotor(float stride, int c1, int c2, int c3, int c4);
  void setRpm(float rpm);
  void step(float angles);

  ~StepperMotor();

private:
  int phase;
  float stepsPerRevolution;
  float singleStepDelay;
  uint8_t *stateLut;
  uint8_t *coils;
  void iteration(bool cw);
};

#endif

#ifndef __STEPPER_MOTOR_H__
#define __STEPPER_MOTOR_H__

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
  byte *stateLut;
  byte *coils;
  void iteration(bool cw);
};

#endif


#include "StepperMotor.h"

StepperMotor::StepperMotor(float stride, int c1, int c2, int c3, int c4) {

  phase = 0;
  stepsPerRevolution = 360.0 / stride;
 
  coils = new uint8_t[4]{c1, c2, c3, c4};
  stateLut = new uint8_t[8] {
    0b0001,
    0b0011,
    0b0010,
    0b0110,
    0b0100,
    0b1100,
    0b1000,
    0b1001
  };

  for (int i = 0; i < 4; i++) {
    pinMode(coils[i], OUTPUT);
    digitalWrite(coils[i], LOW); 
  }
}


StepperMotor::~StepperMotor() {
  delete stateLut;
  for (int i=0 ; i<4; i++) {
    digitalWrite(coils[i], LOW);
  }

  delete coils;
}

void StepperMotor::setRpm(float rpm) {
  singleStepDelay = 1000000 * 60.0 / stepsPerRevolution / rpm;
}


void StepperMotor::step(float angles) {
  float steps = abs(stepsPerRevolution * angles / 360.0);
  for (float i = 0; i < steps; i++) {
    iteration(angles >= 0.0);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(coils[i], LOW);
  }
}

void StepperMotor::iteration(bool cw) {
  long phaseBeganAt = micros();
  uint8_t state = cw ? phase : 7-phase;
  for (int coil = 0; coil < 4; coil++) {
    digitalWrite(coils[coil], stateLut[state] & (1<<coil));
  }

  phase++;
  if (phase >= 8) {
    phase = 0;
  }

  while (micros() - phaseBeganAt < singleStepDelay);
}

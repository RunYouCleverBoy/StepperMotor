# StepperMotor
A library for stepper motor for Arduino... one that works.

Simply initialise, copy the stride (degrees per one step) from the datasheet, and the coil pins as you connected them, one by one. The first is for IN1.
Currently, it is highly optimised, as it was programmed for educational reasons...

Usage
=====
Constructor
-----------
```
StepperMotor(float stride, int coil1, int coil2, int coil3, int coil4)
```

stride - is the angle for each step. Copy that from the motor spec.
coil1 - is the pin that goes to IN1
coil2 - is the pin that goes to IN2
coil3 - is the pin that goes to IN3
coil4 - is the pin that goes to IN4

Setting the speed
-----------------
The speed is set in RPM - Revolutions per minute with 
```
setRpm(float rpm)
```

Rotating
--------
```
step(float degrees)
```

Spin the motor by n degrees CW. Of course CCW is supported, just by using degrees < 0.


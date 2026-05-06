#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "dji_motor.h"

extern DJIMotorInstance *m3508_motor;

void MotorControlAppInit();
void MotorControlAppTask();

#endif

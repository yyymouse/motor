#include "bsp_init.h"
#include "robot.h"

#include "dmmotor.h"
#include "robot_def.h"
#include "robot_task.h"
#include "robot_cmd.h"
#include "motor_control.h"


void RobotInit()
{  
    __disable_irq();

    BSPInit();
    RobotCMDInit();
    MotorControlAppInit();
    BuzzerInit();

    DMMotorControlInit();

    OSTaskInit();

    __enable_irq();
}

void RobotTask()
{
    RobotCMDTask();
    MotorControlAppTask();
}

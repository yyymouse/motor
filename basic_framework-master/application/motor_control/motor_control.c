#include "motor_control.h"
#include "dji_motor.h"
#include "dmmotor.h"
#include "message_center.h"
#include "general_def.h"
#include "robot_def.h"
#include "ins_task.h"

static Subscriber_t *Mc_sub
static Publisher_t *Mc_pub
static Gimbal_Upload_Data_s gimbal_upload_data;

static DJIMotorInstance *motor_gimbal_small_yaw, *motor_gimbal_pitch;
static DMMotorInstance *motor_gimbal_big_yaw;
void MotorControlAppInit()
{
    Motor_Init_Config_s m3508_config = {
        .motor_type = M3508,
        .can_init_config = {
            .can_handle = &hcan1,
            .tx_id = 1,
        },
        .controller_setting_init_config = {
            .angle_feedback_source = MOTOR_FEED,
            .outer_loop_type = SPEED_LOOP,
            .close_loop_type = SPEED_LOOP | CURRENT_LOOP,
            .speed_feedback_source = MOTOR_FEED,
            .motor_reverse_flag = MOTOR_DIRECTION_NORMAL,
        },
        .controller_param_init_config = {
            .current_PID = {
                .Improve = 0,
                .Kp = 1.0f,
                .Ki = 0.0f,
                .Kd = 0.0f,
                // .DeadBand = 0.0f,
                .MaxOut = 4000,
            },
            .speed_PID = {
                .Improve = 0,
                .Kp = 1.0f,
                .Ki = 0.0f,
                .Kd = 0.0f,
                .DeadBand = 0.0f,
                .Improve = PID_Integral_Limit | PID_Trapezoid_Intergral |PID_Derivative_On_Measurement,
                .IntegralLimit = 100,
                .MaxOut = 10000,
            },
        },

    };
    Motor_Init_Config_s dmmotor_t ={
        .motor_type  = DM4310,
        .can_init_config ={
            .can_handle = &hcan2,
            .id = 1,
        },
        .controller_param_init_config ={
            .angle_PID = {
                .Improve = 0,
                .Kp = 1.0f,
                .Ki = 1.0f,
                .Kd = 1.0f,
                .IntegralLimit = 1000.0f,
                .MaxOut = 1000.0f,
            },
        }

    }
    m3508_motor = DJIMotorInit(&m3508_config);
    motor_controlSub = SubRegister("motor_control", sizeof(Gimbal_Ctrl_Cmd_s));
    motor_controlPub = PubRegister("motor_control", sizeof(motor_control_cmd_s))
}

void MotorControlAppTask()
{

}

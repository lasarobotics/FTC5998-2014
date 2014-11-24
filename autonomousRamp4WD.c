#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftWheel1,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     leftWheel2,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C1_1,     rightWheel1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     rightWheel2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    back,                 tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    front,                tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define backDown 250
#define backUp 125
#define frontDown 200
#define frontUp 0
#define inSpeed 50
#define threshold 0
#define turnTime 550 //usually, chk battery tho

void stopMotors()
{
motor[leftWheel1] = 0;
motor[leftWheel2] = 0;
motor[rightWheel1] = 0;
motor[rightWheel2] = 0;
motor[flag] = 0;
}

void forward(int time)
{
motor[leftWheel1] = 100;
motor[leftWheel2] = 100;
motor[rightWheel1] = 100;
motor[rightWheel2] = 100;
wait1Msec(time);
stopMotors();
}
void forwardSlow(int time)
{
motor[leftWheel1] = 30;
motor[leftWheel2] = 30;
motor[rightWheel1] = 30;
motor[rightWheel2] = 30;
wait1Msec(time);
stopMotors();
}
void backward(int time)
{
motor[leftWheel1] = -50;
motor[leftWheel2] = -50;
motor[rightWheel1] = -50;
motor[rightWheel2] = -50;
wait1Msec(time);
stopMotors();
}
void turnR(int time){ //turns right (on a dime-on forward, the other backward) for as long as it is called
motor[leftWheel1]=50;
motor[leftWheel2]=50;

motor[rightWheel1]=-50;
motor[rightWheel2]=-50;
wait1Msec(time);
stopMotors();
}
void turnL(int time){//turns left (on a dime^) for as long as it is called
motor[leftWheel1]=-50;
motor[leftWheel2]=-50;

motor[rightWheel1]=50;
motor[rightWheel2]=50;
wait1Msec (time);
stopMotors();
}
void flagSpin(int time)
{
motor[flag] = 50;
wait1Msec(time);
stopMotors();
}
task main()
{
//goes off the ramp
forward(2500);
forwardSlow(600);
//drops front servo
wait1Msec(1000);
servo[front] = frontDown;
wait1Msec(3000);
backward(700);
turnR(turnTime);
forward(300);

//after waiting, the servo goes back up
servo[front] = frontUp;
//flagspin
flagSpin(1000);
}

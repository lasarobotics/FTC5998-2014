#pragma config(Hubs,  S3, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S3_C2_1,     Pull,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S3_C2_2,     Pulley,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    drop,                 tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    back2,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int pos = 10;
	while(true){
		eraseDisplay();
		nxtDisplayCenteredTextLine(3, "Pos: %d",pos);//shows power and encoder value (rotations)
		wait1Msec(200);
		//allows the user to move the lift based on button pushes
		if(nNxtButtonPressed == 1){ pos += 5; }
		if(nNxtButtonPressed == 2){ pos -= 5; }
		if(nNxtButtonPressed == 3){ pos = 125; }
		servo[drop] = pos;
		servo[servo2] = pos;
	}
}
//140 SECURE
//110 SMALL
//65 ALL

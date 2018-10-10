#pragma config(StandardModel, "RVW Fantastilaunch")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int defaultPause = 50;
void pause(int secs)
{
  motor[leftDrive] = 0;
  motor[rightDrive] = 0;
  motor[clawExtender] = 0;
  motor[clawWrist] = 0;
  motor[clawMotor] = 0;
  motor[clawArm] = 0;
  wait1Msec(secs);
}
void moveFoward1(int secs)
{
   motor[leftDrive] = 127;
   motor[rightDrive] = 127;
   wait1Msec(secs);
}
void moveBakward1(int secs)
{
	motor[leftDrive] = -127;
	motor[rightDrive] = -127;
	wait1Msec(secs);
}

void turnRight1(int secs)
{
 motor[rightDrive] = -127;
 motor[leftDrive] = 127;
  wait1Msec(secs);
}
void turnLeft1(int secs)
{
 motor[rightDrive] = 127;
 motor[leftDrive] = -127;
  wait1Msec(secs);
//  pause(1);
}
// sharan & Aryan - clawWrist > moveForward > clawMotor > clawArm
void pickUpCap()
{
// motor[clawArm] = 63;
// wait1Msec(20);
  motor[clawExtender] = 127;
 wait1Msec(500);
pause(500);
  motor[clawWrist]= -127;
 wait1Msec(800);
 pause(500);
// pause(defaultPause);
// motor[clawArm] = -63;
// wait1Msec(30);
 motor[clawMotor] = 127;
 wait1Msec(500);
 pause(500);
 motor[clawArm] = 127;
 wait1Msec(1700);
 pause(500);
 moveFoward1(1400);
 pause(500);
 turnLeft1(450);
 motor[clawMotor] = -127;
 wait1Msec(500);
 pause(500);
 // wait1Msec(1);
 // motor[clawArm] = -63;
}
void ReturntoRed()
{
	motor[clawArm] = -127;
	wait1Msec(1500);
	pause(500);
	motor[clawExtender] = -127;
	wait1Msec(800);
	motor[clawWrist] = 127;
	wait1Msec(800);
	pause(500);
	moveFoward1(2000);
	pause(500);
	turnLeft1(960);
	pause(500);
	moveBakward1(1000);
}
void shoot()
{
	turnLeft1(300);
	pause(500);
	moveFoward1(1300);
	pause(500);
	turnLeft1(400);
	pause(500);
	moveFoward1(150);
	pause(1000);
	motor(clawArm) = 127;
	wait1msec(500);
	pause(1000);
	motor(launchArm) = 64;
	wait1msec(150);
	pause(500);
	motor(LeftIntake) = -127;
	motor(RightIntake) = -127;
	wait1msec(1000)
}
void shoot2()
{
	motor(clawArm) = 127;
	wait1msec(600);
	pause(1000);
	motor(launchArm) = 64;
	wait1msec(250);
	pause(500);
	motor(LeftIntake) = -127;
	motor(RightIntake) = -127;
	wait1msec(1000)
}
void reset ()
{
	motor(clawArm) = -127;
	wait1msec(700);
	motor(launchArm) = -64;
	wait1msec(550);
}
task main()
{
  moveFoward1(1400);
  pause(500);
  pickUpCap();
  ReturntoRed();
	shoot();
	reset();
}

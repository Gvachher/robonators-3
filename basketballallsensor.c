#pragma config(Sensor, in2,    lineTracker,         sensorLineFollower)
#pragma config(Motor,  port2,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void flipCar()
{
	motor[rightMotor] = -127
	motor[leftMotor] = 127
	wait1Msec(1260);
}
void forward()
{
	motor[rightMotor]	= -127;
	motor[leftMotor] = -127;
}
void green()
{
	 while (SensorValue[lineTracker] > 700)
	  {
    motor[leftMotor] = 127;
		motor[rightMotor] = -127;
		wait1Msec(1260);
    }
    while (SensorValue[lineTracker] < 700)
    {
      motor[leftMotor]  = -127;
      motor[rightMotor] = -127;
    }
 	}
void passline()
{
    while (SensorValue[lineTracker] < 700)
    {
    	forward();
    }
    while (SensorValue[lineTracker] > 700)
    {
      forward();
    }
}
task main()
{

}

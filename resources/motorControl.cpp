#include <math.h>
#include "motorControl.hpp"

pwm::motorControl::motorControl(){}

pwm::motorControl::motorControl(float angle, int angleType)
{
	if(angleType == true)
	{
		angleDegrees = angle;
	}
	else
	{
		angleDegrees = angle*180/PI;
	}
}

pwm::motorControl::moveToAngle()
{
	if(angleDegrees > MAX_ANGLE_DEGREES || angleDegrees < MIN_ANGLE_DEGREES)
	{
		return false;
	}
	else
	{
		int index = angleDegrees*10;	//this is because 1 degrees = 10 microseconds and the table is in increments of 1 microsecond
		int pulseWidth = pulseWidths[index];
		/*OUTPUT PULSE WIDTH*/
		/*I am not familiar with the OS for the PWM, so I am not sure what lines are needed for this*/
		return true;
	}
}

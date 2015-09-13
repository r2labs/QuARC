#include <math.h>
#include "motorControl.hpp"


pwm::motorControl::motorControl(){}

pwm::motorControl::motorControl(float angle, int angleType)
{
	if(angleType == true)
	{
		angleRadians = angle;
	}
	else
	{
		angleRadians = angle*PI/180;
	}
}

pwm::motorControl::moveToAngle()
{
	if(angleRadians > MAX_ANGLE_RADIANS || angleRadians < MIN_ANGLE_RADIANS)
	{
		return false;
	}
	else
	{
		int index = angleRadians*45	//this conversion probably needs to be modified.
		int pulseWidth = pulseWidths[index];
		/*OUTPUT PULSE WIDTH*/
		/*I am not familiar with the OS for the PWM, so I am not sure what lines are needed for this*/
		return true;
	}
}

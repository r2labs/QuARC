#include <math.h>
#include "motorControl.hpp"


pwm::motorControl::motorControl(){}

//angleType == true means that the input angle is in degrees
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
	if(angleDegrees > 180 || angleDegrees < 0)
	{
		return false;
	}
	else
	{
		int index = angleDegrees*45	//this conversion probably needs to be modified.
		int pulseWidth = pulseWidths[index];
		/*OUTPUT PULSE WIDTH*/
		/*I am not familiar with the OS for the PWM, so I am not sure what lines are needed for this*/
		return true;
	}
}

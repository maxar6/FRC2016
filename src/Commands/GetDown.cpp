#include "GetDown.h"

GetDown::GetDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	pos = 0;
}

// Called just before this Command runs the first time
void GetDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GetDown::Execute()
{
	Robot::ramp->setMotor(1);
	Wait(.25);
	Robot::ramp->setMotor(0);
	pos = RobotMap::launcherdart->GetAnalogIn();
		if (pos < 890)
		{
			while (pos < 890)
			{
				pos = RobotMap::launcherdart->GetAnalogIn();
				Robot::launcher->setDart(0.50);
			}
		}
		else
		{
			Robot::launcher->setDart(0);
			Robot::ramp->setMotor(0);
		}
		Robot::launcher->setDart(0);
		Robot::ramp->setMotor(0);
}

// Make this return true when this Command no longer needs to run execute()
bool GetDown::IsFinished()
{
	pos = RobotMap::launcherdart->GetAnalogIn();
	if (pos<890)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void GetDown::End()
{
	Robot::launcher->setDart(0);
	Robot::ramp->setMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetDown::Interrupted()
{
	Robot::launcher->setDart(0);
	Robot::ramp->setMotor(0);
}

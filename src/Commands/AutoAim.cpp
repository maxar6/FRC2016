// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoAim.h"
#include "ActuateDartCommand.h"
#include <math.h>
double u, pos, target;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
AutoAim::AutoAim(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoAim::Initialize() {
	dartcommandbackward = new ActuateDartCommand(true);
	dartcommandforward = new ActuateDartCommand(false);
	//Refresh the variables
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	pos = RobotMap::launcherdart->GetAnalogIn();
}

// Called repeatedly when this Command is scheduled to run
void AutoAim::Execute() {
	//Correct the Aim to be within acceptable standards.
	if (pos < target - 15)
	{
		dartcommandbackward->Start();
	}
	else if (pos > target + 15)
	{
		dartcommandforward->Start();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAim::IsFinished() {
	//Refresh variables
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	pos = RobotMap::launcherdart->GetAnalogIn();
	//Check to make sure the pos value is within acceptable standards
    if (pos < target + 15 && pos > target - 15)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void AutoAim::End() {
	delete dartcommandforward;
	delete dartcommandbackward;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAim::Interrupted() {
	delete dartcommandforward;
	delete dartcommandbackward;
}

double AutoAim::GetTargetValue() {
	//Refresh Variables Except for pos
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	//Return Target Value
	return target;
}

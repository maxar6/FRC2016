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
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
AutoAim::AutoAim(): Command() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
<<<<<<< HEAD
	pos = RobotMap::launcherdart->GetAnalogIn();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	u = RobotMap::launcherUltrasonic->GetVoltage();
	dartcommandbackward = new ActuateDartCommand(true);
	dartcommandforward = new ActuateDartCommand(false);
=======
>>>>>>> origin/master
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoAim::Initialize() {
<<<<<<< HEAD
	//Get Commands to actuate the dart
	dartcommandbackward = new ActuateDartCommand(true);
	dartcommandforward = new ActuateDartCommand(false);
=======
>>>>>>> origin/master
	//Refresh the variables
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	pos = RobotMap::launcherdart->GetAnalogIn();
}

// Called repeatedly when this Command is scheduled to run
void AutoAim::Execute() {
	//Correct the Aim to be within acceptable standards.
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	pos = RobotMap::launcherdart->GetAnalogIn();
	if (pos < target - 3)
	{
<<<<<<< HEAD
		while (pos < target - 3)
		{
			u = RobotMap::launcherUltrasonic->GetVoltage();
			target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
			pos = RobotMap::launcherdart->GetAnalogIn();

			SmartDashboard::PutNumber("Dart Position: ", pos);
			SmartDashboard::PutNumber("Target value: ", target);
			Robot::launcher->setDart(-0.5);
		}
=======
		Robot::launcher->setDart(0.5);
>>>>>>> origin/master
	}
	else if (pos > target + 3)
	{
<<<<<<< HEAD
		while (pos > target + 3)
		{
			u = RobotMap::launcherUltrasonic->GetVoltage();
			target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
			pos = RobotMap::launcherdart->GetAnalogIn();

			SmartDashboard::PutNumber("Dart Position: ", pos);
			SmartDashboard::PutNumber("Target value: ", target);
			Robot::launcher->setDart(0.5);
		}
=======
		Robot::launcher->setDart(-0.5);
>>>>>>> origin/master
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAim::IsFinished() {
<<<<<<< HEAD
	if (pos <  + 3 && pos > target - 3)
=======
	//Refresh variables
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	pos = RobotMap::launcherdart->GetAnalogIn();
	//Check to make sure the pos value is within acceptable standards
    if (pos <= target + 15 && pos >= target - 15)
	{
>>>>>>> origin/master
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void AutoAim::End() {
<<<<<<< HEAD
	Robot::launcher->setDart(0);
=======
>>>>>>> origin/master
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAim::Interrupted() {
}

double AutoAim::GetTargetValue() {
	//Get Values
	u = RobotMap::launcherUltrasonic->GetVoltage();
	target = ((-0.0102 * pow((u * 42.0919), 2)) + (3.0804 * (u * 42.0919)) + 210.79);
	//Return Target Value
	return target;
}

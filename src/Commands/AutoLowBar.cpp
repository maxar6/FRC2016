// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoLowBar.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/CommandGroup.h"
#include "Commands/TurnToGyroCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoLowBar::AutoLowBar(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	pos = RobotMap::launcherdart->GetAnalogIn();
	done = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoLowBar::Initialize() {
	pos = RobotMap::launcherdart->GetAnalogIn();
	SetInterruptible(false);
}

// Called repeatedly when this Command is scheduled to run

void AutoLowBar::Execute() {

	pos = RobotMap::launcherdart->GetAnalogIn();
	if (pos > 320)
	{
		while (pos < 850)
		{
			pos = RobotMap::launcherdart->GetAnalogIn();
			Robot::launcher->setDart(-0.75);
		}
	}
	Robot::launcher->setDart(0);
	Robot::ramp->setMotor(-0.5);
	Wait(.3);
	Robot::ramp->setMotor(0);
	Command* Drive = new AutoDriveCommand(-0.6, 4, 0);
	if (Drive != NULL) Drive->Start();
	Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();
	Drive = new TurnToGyroCommand(180, 2, 2);
	if (Drive != NULL) Drive->Start();
	Drive = new AutoDriveCommand(0,0,0);
	if (Drive != NULL) Drive->Start();
	done = 1;

}

// Make this return true when this Command no longer needs to run execute()
bool AutoLowBar::IsFinished() {
	return (done == 1);
}

// Called once after isFinished returns true
void AutoLowBar::End() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLowBar::Interrupted() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();
}

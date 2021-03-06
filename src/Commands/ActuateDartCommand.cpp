// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ActuateDartCommand.h"
#include "AutoAim.h"
//#include "LauncherSuicideWatch.h"
#include <math.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ActuateDartCommand::ActuateDartCommand(bool moveForward): Command() {
    m_moveForward = moveForward;
    pos = RobotMap::launcherdart->GetAnalogIn();
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher.get());
	ultra = 0;
	target = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ActuateDartCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ActuateDartCommand::Execute() {
	pos = RobotMap::launcherdart->GetAnalogIn(); //Retrieve new POT value

	if (m_moveForward)
	{
		if (pos < 900) //Make sure the robot does not kill itself while going up
			Robot::launcher->setDart(0.50); //Move dart up
	}
	else
	{
		if (pos > 300) //Make sure the robot does not kill itself while going down
			Robot::launcher->setDart(-0.50); //Move dart down
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ActuateDartCommand::IsFinished() {
	if (m_moveForward)
		return !Robot::oi->getButtonDartForward();
	else
		return !Robot::oi->getButtonDartBackward();
}

// Called once after isFinished returns true
void ActuateDartCommand::End() {
	Robot::launcher->setDart(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActuateDartCommand::Interrupted() {
	Robot::launcher->setDart(0);
}

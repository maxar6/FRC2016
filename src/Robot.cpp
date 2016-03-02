// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/DistanceOverTimeCG.h"
#include <Commands/Scheduler.h>
#include "Robot.h"
#include <RobotBase.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <memory>
//See issue Autonomous
#include "Commands/AutoDriveCommand.h"
#include "Commands/AutoAim.h"
#include "Commands/AutoLowBar.h"
#include "Commands/AutoRoughTerrain.h"
#include "Commands/AutoMoat.h"
#include <string>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<Launcher> Robot::launcher;
std::shared_ptr<Ramp> Robot::ramp;
std::shared_ptr<VISION> Robot::vISION;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    launcher.reset(new Launcher());
    ramp.reset(new Ramp());
    vISION.reset(new VISION());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// START DO NOT TOUCH THIS
	oi.reset(new OI());
	// END DO NOT TOUCH THIS

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousPlaceholder());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//CameraServer::GetInstance()->SetQuality(50);
	//CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	// START FRESHMAN DO NOT TOUCH THIS
	DoTCommand = new DistanceOverTimeCG();
	driveTrain->CalibrateGyro();
	chooserChooser = new SendableChooser();
	defenseChooser = new SendableChooser();

	chooserChooser->AddDefault("Position One", oneChooser);
	chooserChooser->AddObject("Position Two", twoChooser);
	chooserChooser->AddObject("Position Three", threeChooser);
	chooserChooser->AddObject("Position Four", fourChooser);
	chooserChooser->AddObject("Position Five", fiveChooser);
	chooserChooser->AddObject("No Movement", nomoveChooser);

	defenseChooser->AddDefault("LowBar", new AutoLowBar());
	defenseChooser->AddObject("Rock Wall", rockwallChooser);
	defenseChooser->AddObject("Rough Terrain", new AutoRoughTerrain());
	defenseChooser->AddObject("Moat", new AutoMoat());
	defenseChooser->AddObject("Porticulis", porticulisChooser);
	defenseChooser->AddObject("Chivel De Frise", chivedefriseChooser);
	defenseChooser->AddObject("Ramparts", rampartsChooser);
	defenseChooser->AddObject("No Movement", nomoveChooser);



	SmartDashboard::PutData("Field Location", chooserChooser);
	SmartDashboard::PutData("Defense on Field", defenseChooser);
	//END FRESHMAN DO NOT TOUCH THIS
  }
/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	SmartDashboard::PutData("Field Location", (SendableChooser*) chooserChooser->GetSelected());
	SmartDashboard::PutData("Defense on Field", (SendableChooser*) defenseChooser->GetSelected());
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

	/*	autonomousCommand.reset((Command*)((SendableChooser*)
				chooserChooser->GetSelected())->GetSelected());
		if (autonomousCommand.get() != nullptr)
			autonomousCommand->Start();
	*/
	//DoTCommand->Start();
	//Start Actual command. Will only run once per time play.

	/*Comented out for Case Switch
	Command* Drive = new AutoDriveCommand(1, .5, 0);
	if (Drive != NULL) Drive->Start();
	Drive = new AutoDriveCommand(1, 0, 90);
	if (Drive != NULL) Drive->Start();
	*/

	autoDefense = (Command *) defenseChooser->GetSelected();
	autoPosition = (Command *) chooserChooser->GetSelected();
	autoDefense->Start();


}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);


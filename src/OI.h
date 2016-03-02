// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> opJoystick;
	std::shared_ptr<JoystickButton> lowerRamp;
	std::shared_ptr<JoystickButton> launch;
	std::shared_ptr<JoystickButton> launcherWheelBackward;
	std::shared_ptr<JoystickButton> launcherWheelForward;
	std::shared_ptr<JoystickButton> dartBackward;
	std::shared_ptr<JoystickButton> dartForward;
	std::shared_ptr<JoystickButton> raiseRamp;
	std::shared_ptr<Joystick> driverjoystick;
	std::shared_ptr<JoystickButton> dartAim;

	double ultra;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getdriverjoystick();
	std::shared_ptr<Joystick> getopJoystick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	bool getButtonLWForward();
	bool getButtonLWBackward();
	bool getButtonDartForward();
	bool getButtonDartBackward();
};

#endif

/*
 * AutoLowBar.h
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */

#ifndef SRC_COMMANDS_AUTOLOWBAR_H_
#define SRC_COMMANDS_AUTOLOWBAR_H_

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoLowBar: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	AutoLowBar();
	void GetDownBitch();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	double pos, done;
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
};




#endif /* SRC_COMMANDS_AUTOLOWBAR_H_ */
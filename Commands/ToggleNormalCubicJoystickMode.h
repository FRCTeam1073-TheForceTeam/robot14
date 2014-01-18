/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */

#ifndef TOGGLENORMALCUBICJOYSTICKMODE_H
#define TOGGLENORMALCUBICJOYSTICKMODE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"

class ToggleNormalCubicJoystickMode: public Command {
public:
	ToggleNormalCubicJoystickMode();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
	bool isCubic;
	ChangeJoystickModeCommand* normalJoysticks;
	ChangeJoystickModeCommand* cubicJoysticks;
};

#endif

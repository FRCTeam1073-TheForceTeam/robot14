/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */


#ifndef AUTONOMOUSDRIVECOMMAND_H
#define AUTONOMOUSDRIVECOMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"

class AutonomousDriveCommand: public Command {
public:
	AutonomousDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	static const float timeoutDflt = 3.5f;
private:
	float timeval;
	static const bool rangeFinderDefault = true;
	float autonomousValue;
	bool useRangeFinder;
	float initialTime;
	float currentTime;
	float timeInMethod;
};


#endif

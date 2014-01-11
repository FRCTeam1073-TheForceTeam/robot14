/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */


#ifndef COMPRESS_H
#define COMPRESS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"

class Compress: public Command {
public:
	Compress();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

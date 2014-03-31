/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */


#ifndef COLLECTORFEEDWITHTIMEOUTCOMMAND_H
#define COLLECTORFEEDWITHTIMEOUTCOMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"

class CollectorFeedWithTimeoutCommand: public Command {
public:
	CollectorFeedWithTimeoutCommand(bool dir=true, double timeout=0.1);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	bool dir;
};

#endif

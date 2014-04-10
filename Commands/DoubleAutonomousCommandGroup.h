/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */



#ifndef DOUBLEAUTONOMOUSCOMMANDGROUP_H
#define DOUBLEAUTONOMOUSCOMMANDGROUP_H

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DoubleAutonomousCommandGroup: public CommandGroup {
public:	
	DoubleAutonomousCommandGroup();
private:
	double waitTimeAfterFirstShot;
	double waitTimeCollectBall;
	bool spinCollector;
};

#endif

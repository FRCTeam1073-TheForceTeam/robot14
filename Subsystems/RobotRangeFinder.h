/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef ROBOTRANGEFINDER_H
#define ROBOTRANGEFINDER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class RobotRangeFinder: public Subsystem {
private:
	static int maxFarShootingRangeCM;
	static int minFarShootingRangeCM;
	static int maxNearShootingRangeCM;
	static int minNearShootingRangeCM;
	static int autonomousRangeCM;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	StallableAnalogEncoder* ultrasonicSensor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	bool InRange();
	bool IdealAutonomousRange();
	int GetDistance();
	RobotRangeFinder();
	void InitDefaultCommand();
};
#endif

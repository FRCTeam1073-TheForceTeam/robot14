/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class Collector: public Subsystem {
private:
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SmartCANJaguar* rightRoller;
	SmartCANJaguar* leftRoller;
	Servo* angleAdjuster;
	DigitalInput* highLimit;
	DigitalInput* lowLimit;
	StallableAnalogEncoder* elevationEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Collector();
	void InitDefaultCommand();
	void Run();
	bool IsMaxHeight();
	bool IsMinHeight();
	bool CanMoveElevatorUp();
	bool CanMoveElevatorDown();
	void Elevate(bool dir);
	void Collect(bool dir);
private:
	bool CanMoveElevator(bool dir);
};
#endif

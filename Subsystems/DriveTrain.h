/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */


#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"

class DriveTrain : public Subsystem {
private:

public:
	SmartCANJaguarSeries* left;
	SmartCANJaguarSeries* right;
	DriveTrain();
	void InitDefaultCommand();
};

#endif

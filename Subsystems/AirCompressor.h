/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef AIRCOMPRESSOR_H
#define AIRCOMPRESSOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class AirCompressor: public Subsystem {
private:
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Compressor* compressor;
	DigitalInput* lowPressureSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	AirCompressor();
	void InitDefaultCommand();
	bool IsHighPressure();
	bool IsLowPressure();
	
};
#endif
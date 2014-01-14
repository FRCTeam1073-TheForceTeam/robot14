/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "AirCompressor.h"
#include "../Robotmap.h"
AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressor = RobotMap::airCompressorCompressor;
	lowPressureSwitch = RobotMap::airCompressorLowPressureSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressor->Start();
}
    
void AirCompressor::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// might be useful for the dashboard, is our masterqe
bool AirCompressor::IsHighPressure() {
	return LimitPressed(compressor->GetPressureSwitchValue());
}
bool AirCompressor::IsLowPressure() {
	return LimitPressed(lowPressureSwitch);
}

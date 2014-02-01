/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "AirCompressor.h"
#include "../Robotmap.h"
const int lowPressureLimit = 60;
AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressor = RobotMap::airCompressorCompressor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressor = RobotMap::airCompressorCompressor;
	compressor->Start();
}
void AirCompressor::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

bool AirCompressor::IsLowPressure() {
	float PSI = RobotMap::launcherLowPressureSwitch->GetPressurePSI();
	if (PSI <= lowPressureLimit){
		return true;
	}		
	else 
		return false;
}
float AirCompressor::GetPressurePSI() {
	float PSI = RobotMap::launcherLowPressureSwitch->GetPressurePSI();
	return PSI;
}

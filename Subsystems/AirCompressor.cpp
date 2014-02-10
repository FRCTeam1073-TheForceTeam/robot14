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
	//printf("\n\nTURNED OFF COMPRESSOR\n\n");
	//BEGIN DEBUG CODE
	//willCompress=2;
	//END DEBUG CODE
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
//BEGIN DEBUG CODE
/*void AirCompressor::Compress() {
	if(willCompress%2==0){
		compressor->Start();
	}
	else{
		compressor->Stop();
	}
	willCompress++;
	if(willCompress==1000){
		willCompress=2;
	}
}*/
//END DEBUG CODE

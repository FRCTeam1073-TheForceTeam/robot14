/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "RobotRangeFinder.h"
#include "../Robotmap.h"
static const float VoltsPerCM = 0.0049;
static const float MaxShootingRangeCM = 228.6; // 7.5 ft 90 in 228.6 cm
RobotRangeFinder::RobotRangeFinder() : Subsystem("RobotRangeFinder") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ultrasonicSensor = RobotMap::robotRangeFinderUltrasonicSensor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void RobotRangeFinder::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
bool RobotRangeFinder::InRange() {
	if(GetDistance() <= MaxShootingRangeCM){
		return true;
	}
	else{
		return false;
	}
}
int RobotRangeFinder::GetDistance() {
	float voltage = ultrasonicSensor ->GetVoltage();
	printf("Voltage: %f %d cm\n", voltage, (int)(voltage/VoltsPerCM));
	return (int)(voltage/VoltsPerCM);
}

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "RobotRangeFinder.h"
#include "../Robotmap.h"
#include "../Robot.h"
static const float VoltsPerCM = 0.0049;
static const float MaxShootingRangeCmDflt = 228.6; // 7.5 ft 90 in 228.6 cm
static const float MinShootingRangeCmDflt = 91.4;   // 3 ft (temporary value)
float RobotRangeFinder::MinShootingRangeCM = 0.0;
float RobotRangeFinder::MaxShootingRangeCM = 0.0;

RobotRangeFinder::RobotRangeFinder() : Subsystem("RobotRangeFinder") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ultrasonicSensor = RobotMap::robotRangeFinderUltrasonicSensor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	MaxShootingRangeCM = Robot::prefs->GetFloat("MaxShootingRangeCm", MaxShootingRangeCmDflt);
	MinShootingRangeCM = Robot::prefs->GetFloat("MinShootingRangeCm", MinShootingRangeCmDflt);	
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
	if((GetDistance() <= MaxShootingRangeCM) && (GetDistance() >= MinShootingRangeCM)) {
		return true;
	}
	else{
		return false;
	}
}
int RobotRangeFinder::GetDistance() {
	float voltage = ultrasonicSensor ->GetVoltage();
	// printf("Voltage: %f %d cm\n", voltage, (int)(voltage/VoltsPerCM));
	return (int)(voltage/VoltsPerCM);
}

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "RobotRangeFinder.h"
#include "../Robotmap.h"
#include "../Robot.h"
static const float VoltsPerCM = 0.0049;
static const int MaxShootingRangeCmDflt = 213; // 7ft
static const int MinShootingRangeCmDflt = 137;   // 4.5 ft 
static const int AutonomousRangeCmDflt = 183;//6 ft
int RobotRangeFinder::maxShootingRangeCM = 0;
int RobotRangeFinder::minShootingRangeCM = 0;
int RobotRangeFinder::autonomousRangeCM = 0;
RobotRangeFinder::RobotRangeFinder() : Subsystem("RobotRangeFinder") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ultrasonicSensor = RobotMap::robotRangeFinderUltrasonicSensor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	maxShootingRangeCM = Robot::prefs->GetInt("maxShootingRangeCM", MaxShootingRangeCmDflt);
	minShootingRangeCM = Robot::prefs->GetInt("minShootingRangeCM", MinShootingRangeCmDflt);
	autonomousRangeCM = Robot::prefs->GetInt("autonomousRangeCM", AutonomousRangeCmDflt);
	printf("recorded Max: %d\tRecordedMin: %d\tAutonomous: %d\n", maxShootingRangeCM, minShootingRangeCM,autonomousRangeCM);

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
	if((GetDistance() <= maxShootingRangeCM) && (GetDistance() >= minShootingRangeCM)) {
		return true;
	}
	return false;
}
bool RobotRangeFinder::IdealAutonomousRange() {
	const int dist = GetDistance();
	return dist <= autonomousRangeCM;
}
int RobotRangeFinder::GetDistance() {
	float voltage = ultrasonicSensor->GetVoltage();
	// printf("Voltage: %f %d cm\n", voltage, (int)(voltage/VoltsPerCM));
	return (int)(voltage/VoltsPerCM);
}

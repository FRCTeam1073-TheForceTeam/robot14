/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Collector.h"
#include "../Robotmap.h"
#include "../Robot.h"
Collector::Collector() : Subsystem("Collector") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftRoller = RobotMap::collectorLeftRoller;
	rightRoller = RobotMap::collectorRightRoller;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//DEBUG realSpeed=0.00;
}
void Collector::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Collector::Collect(bool feedIn){
	//false = purge, true = collect
	if(feedIn){
		leftRoller->Set(-1.0f);
		rightRoller->Set(1.0f);
	}
	else {
		leftRoller->Set(1.0f);
		rightRoller->Set(-1.0f);
	}
}
void Collector::StopRollers(){
	leftRoller->Set(0.0f);
	rightRoller->Set(0.0f);
}
//BEGIN DEBUG CODE
/*void Collector::SetSpeed(float speed){
	realSpeed=speed;
	leftRoller->Set(realSpeed, Talon::kPeriodMultiplier_1X);
	rightRoller->Set(realSpeed,Talon::kPeriodMultiplier_1X);
}
float Collector::GetSpeed(){
	return realSpeed;
}*/
//END DEBUG CODE

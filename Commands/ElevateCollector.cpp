/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "ElevateCollector.h"
ElevateCollector::ElevateCollector(bool up) {
	Construct(up);
}
ElevateCollector::ElevateCollector(){
	Construct(true);
}
void ElevateCollector::Construct(bool up){
	this->goUp = up;
	Requires(Robot::elevator);
}
// Called just before this Command runs the first time
void ElevateCollector::Initialize() {
	if(goUp){
		Robot::elevator->SetSetpoint(Robot::elevator->GetSetpoint() + .1);
	}
	else{
		Robot::elevator->SetSetpoint(Robot::elevator->GetSetpoint() - .1);
	}
}
void ElevateCollector::Execute() {
	// part of the Stallable interface
	Robot::elevator->elevationEncoder->ProcessVoltageData();
}
bool ElevateCollector::IsFinished() {
	return Robot::elevator->NotOKToMove();
}
void ElevateCollector::End() {}
void ElevateCollector::Interrupted() { End(); }

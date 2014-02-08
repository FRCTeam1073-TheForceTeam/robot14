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
	Requires(Robot::collector);
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
// Called repeatedly when this Command is scheduled to run
void ElevateCollector::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool ElevateCollector::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void ElevateCollector::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevateCollector::Interrupted() { End(); }

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Collect.h"
Collect::Collect(bool dir) {
	Construct(dir);
}
Collect::Collect(){
	Construct(true);
}
void Collect::Construct(bool dir){
	this->dir = dir;
	Requires(Robot::collector);
}
void Collect::Initialize() {
	Robot::collector->Collect(dir);
}
// Called repeatedly when this Command is scheduled to run
void Collect::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool Collect::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void Collect::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Collect::Interrupted() {
}

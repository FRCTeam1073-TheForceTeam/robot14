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
void Collect::Execute() {
	
}
bool Collect::IsFinished() {
	return false;
}

void Collect::End() {
	Robot::collector->StopRollers();
}
void Collect::Interrupted() { End(); }

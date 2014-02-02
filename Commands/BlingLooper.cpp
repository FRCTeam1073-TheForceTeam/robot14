/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "BlingLooper.h"

BlingLooper::BlingLooper(){
	Requires(Robot::bling);
}

void BlingLooper::Initialize() {

}
void BlingLooper::Execute() {
	Robot::bling->Execute();
	
}
bool BlingLooper::IsFinished() {
	return false;
}
void BlingLooper::End() {
	
}
void BlingLooper::Interrupted() { End(); }

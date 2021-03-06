/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "ElevateCollectorUp.h"
ElevateCollectorUp::ElevateCollectorUp() {
	Requires(Robot::elevator);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void ElevateCollectorUp::Initialize() {}
void ElevateCollectorUp::Execute() {
	Robot::elevator->IncrementSetPoint(true);
}
bool ElevateCollectorUp::IsFinished() {	return false;}
void ElevateCollectorUp::End() {
	Robot::elevator->HoldPosition();
}
void ElevateCollectorUp::Interrupted() {End();}

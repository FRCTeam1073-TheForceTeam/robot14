/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "CollectToggle.h"
CollectToggle::CollectToggle()  : Invertable() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::collector);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void CollectToggle::Initialize() {
	Invert();
	if (IsInverted())
		Robot::collector->Collect(true);
	else
		Robot::collector->StopRollers();
}
void CollectToggle::Execute() {}
bool CollectToggle::IsFinished() {return true;}
void CollectToggle::End() {}
void CollectToggle::Interrupted() { End(); }
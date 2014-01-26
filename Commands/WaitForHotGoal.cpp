/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "WaitForHotGoal.h"
WaitForHotGoal::WaitForHotGoal() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(waitval);
}
// Called just before this Command runs the first time
void WaitForHotGoal::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void WaitForHotGoal::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool WaitForHotGoal::IsFinished() {
	bool isHot= Robot :: vision-> IsHot();
	return isHot || IsTimedOut();
	
}
// Called once after isFinished returns true
void WaitForHotGoal::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForHotGoal::Interrupted() {
}

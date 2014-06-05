/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "autoCollector.h"
autoCollector::autoCollector() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::collector);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void autoCollector::Initialize() {
	puts("Testing the Collector...\n");
	Wait(1);
}
// Called repeatedly when this Command is scheduled to run
void autoCollector::Execute() {
	puts("Collecting...\n");
	Robot::collector->Collect(true);
	Wait(1);
	puts("Purging...\n");
	Robot::collector->Collect(false);
	Wait(0.5);
	Robot::collector->autoStopRollers();
}
// Make this return true when this Command no longer needs to run execute()
bool autoCollector::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void autoCollector::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoCollector::Interrupted() {
}

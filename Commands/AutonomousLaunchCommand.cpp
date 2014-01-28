/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "AutonomousLaunchCommand.h"
AutonomousLaunchCommand::AutonomousLaunchCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(shootertimeval);
}
// Called just before this Command runs the first time
void AutonomousLaunchCommand::Initialize() {
	printf(" Launching Ball");
	if(!RobotMap::disableautonomous){
		Robot::launcher->OpenTank();
	}
}
// Called repeatedly when this Command is scheduled to run
void AutonomousLaunchCommand::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousLaunchCommand::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void AutonomousLaunchCommand::End() {
	Robot::launcher->CloseTank();
	printf(" Closing Solenoid");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousLaunchCommand::Interrupted() {
}
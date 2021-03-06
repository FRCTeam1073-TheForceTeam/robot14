/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "CatchMode.h"
CatchMode::CatchMode() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void CatchMode::Initialize() {
	i = 1;
}
// Called repeatedly when this Command is scheduled to run
void CatchMode::Execute() {
	if(i == 1){
		i++;
		Robot::launcher->OpenTank();
		printf("CatchMode open tank");
	}
	else if(i == 2){
		i++;
		Robot::launcher->CloseTank();
		printf("CatchMode close tank");
	}
	else if(i == 20){
		i = 1;
		printf("CatchMode reset count");
	}
	else{
		i++;
	}
}
// Make this return true when this Command no longer needs to run execute()
bool CatchMode::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void CatchMode::End() {
	Robot::launcher->CloseTank();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CatchMode::Interrupted() {
	End();
}

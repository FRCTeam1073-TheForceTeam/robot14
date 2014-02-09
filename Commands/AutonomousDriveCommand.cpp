/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "AutonomousDriveCommand.h"
AutonomousDriveCommand::AutonomousDriveCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::robotRangeFinder);
	SetTimeout(timeval); //timeval will need to be adjusted for the new robot
	useRangeFinder = true; //change this when ready to try rangefinder
}
// Called just before this Command runs the first time
void AutonomousDriveCommand::Initialize() {
	printf("Driving Forward for 2.5 Seconds \n");
} 
// Called repeatedly when this Command is scheduled to run
void AutonomousDriveCommand::Execute() {
	if(useRangeFinder && Robot::robotRangeFinder->InRange()){ //when set to true, will allow the rangefinder to stop the robot
		autonomousValue = 0;
	}
	else{
		autonomousValue = 0.82;
	} //
	Robot::driveTrain->MecanumDriveAction(0, autonomousValue, 0);
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousDriveCommand::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void AutonomousDriveCommand::End() {
	Robot::driveTrain->StopMotors();
	Robot::driveTrain->MecanumDriveAction(0,0,0);//use both because ramping needs zeros to stop
	printf(" Stopping after 2.5 Seconds \n");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDriveCommand::Interrupted() {
	End();
}

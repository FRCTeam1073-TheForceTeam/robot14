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
	timeval = Robot::prefs->GetFloat("autonomousDriveTimeout", timeoutDflt);
	SetTimeout(timeval); //timeval will need to be adjusted for the new robot
	useRangeFinder = true; //change this when ready to try rangefinder
}
// Called just before this Command runs the first time
void AutonomousDriveCommand::Initialize() {
	initialTime = Timer::GetFPGATimestamp();
	printf("Driving Forward for %f Seconds\n", timeval);
} 
// Called repeatedly when this Command is scheduled to run
void AutonomousDriveCommand::Execute() {
	currentTime = Timer::GetFPGATimestamp();
	timeInMethod = currentTime - initialTime; 
	
	if(useRangeFinder && Robot::robotRangeFinder->InRange()){ //when set to true, will allow the rangefinder to stop the robot
		printf("Autonomous drive:  now in range\n");
		autonomousValue = 0;
	}
	else{
		//autonomousValue = 0.82;     // Linear Drive, use if sinusoidal not working/not configured yet
		printf("Autonomous drive: moving forward\n");
		//sinusoidal scaling below
		autonomousValue = sin((3.141592654 * timeInMethod)/3); //currently set to run for 3 seconds, needs to be configured still (longer or shorter...)
	} 
	
	//printf("Current Drive Value: %f  Current Time in method: %f\n", autonomousValue, timeInMethod); //prints drive value
	Robot::driveTrain->MecanumDriveAction(0, autonomousValue, 0);
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousDriveCommand::IsFinished() {
	bool isInRange = ( useRangeFinder ? Robot::robotRangeFinder->InRange() : false);
	bool isTimeout = IsTimedOut();
	printf("isInRange = %s, isTimeout = %s\n", isInRange ? "true" : "false",
				isTimeout ? "true" : "false");
	
	return isInRange || IsTimedOut();
}
// Called once after isFinished returns true
void AutonomousDriveCommand::End() {
	Robot::driveTrain->StopMotors();
	Robot::driveTrain->MecanumDriveAction(0,0,0);//use both because ramping needs zeros to stop
	printf("Stopping after %f Seconds\n", timeval);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousDriveCommand::Interrupted() {
	End();
}

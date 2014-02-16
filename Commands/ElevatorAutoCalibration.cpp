/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */


#include "ElevatorAutoCalibration.h"

ElevatorAutoCalibration::ElevatorAutoCalibration() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ElevatorAutoCalibration::Initialize() {
	initialTime = Timer::GetFPGATimestamp();
	sequenceID = 0;
	printf("Starting Auto-Calibration of Elevator Constants");
	Robot::elevator->HoldPosition();
	
}

// Called repeatedly when this Command is scheduled to run
void ElevatorAutoCalibration::Execute() {
	currentTime = Timer::GetFPGATimestamp();
	timeInMethod = currentTime - initialTime;
	
	if (sequenceID == 0)
	{	
		if (timeInMethod < 3)
		{
			Robot::elevator->IncrementSetPoint(true);
		}
		else
		{
			Robot::elevator->HoldPosition();
			Robot::elevator->SetElevatorUp(RobotMap::elevatorElevationEncoder->GetAverageVoltage());
			sequenceID = 1;
			initialTime = Timer::GetFPGATimestamp();
		}
	}
	else if (sequenceID == 1)
	{
		if (timeInMethod < 3)
		{
			Robot::elevator->IncrementSetPoint(false);
		}
		else
		{
			Robot::elevator->HoldPosition();
			Robot::elevator->SetElevatorDown(RobotMap::elevatorElevationEncoder->GetAverageVoltage());
			sequenceID = 2;
			initialTime = Timer::GetFPGATimestamp();
		}
	}
	else if (sequenceID == 2)
	{
		Robot::elevator->HoldPosition();
		Robot::elevator->SetElevatorShootPos((Robot::elevator->GetElevatorUp()-Robot::elevator->GetElevatorDown())*(0.75)+Robot::elevator->GetElevatorDown());
		sequenceID = 3;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorAutoCalibration::IsFinished() {
	return sequenceID == 3;
}

// Called once after isFinished returns true
void ElevatorAutoCalibration::End() {
	Robot::elevator->HoldPosition();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorAutoCalibration::Interrupted() {
	End();
}

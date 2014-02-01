/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/Drive.h"
#define high DoubleSolenoid::kForward
#define off DoubleSolenoid::kOff
#define low DoubleSolenoid::kReverse
const float EXECUTE_INTVL = 20; //ms
const float FULL_RAMP_TIME = 1000; //ms
const float ONE_RAMP_MAX = EXECUTE_INTVL / FULL_RAMP_TIME;
const float TWIST_CONSTANT = 0.8f;
static const float MECANUM_CONSTANT = 1.4142; //square root of 2, since it's going to be used a lot

#define absMin(a,b) (fabs(b)<fabs(a) ? (b) : (a))
DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rightBack = RobotMap::driveTrainRightBack;
	leftBack = RobotMap::driveTrainLeftBack;
	rightFront = RobotMap::driveTrainRightFront;
	leftFront = RobotMap::driveTrainLeftFront;
	gyro = RobotMap::driveTrainGyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	isFieldOrientation = false; 
	oldX = oldY = oldTwist = 0.0;
}
    
void DriveTrain::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void DriveTrain::ToggleOrientation(){
	isFieldOrientation = !isFieldOrientation; 	
}
bool DriveTrain::IsFieldOrientation(){
	return isFieldOrientation;
}
void DriveTrain::MecanumDriveAction(float joystickX, float joystickY, float joystickTwist) {
	
	//Ramp
		float newX, newY, newTwist;
		if(fabs(joystickX) > fabs(oldX)){
			newX = absMin(joystickX, oldX + ONE_RAMP_MAX);
		}
		else newX = joystickX;
		
		if(fabs(joystickY) > fabs(oldY)){
			newY = absMin(joystickY, oldY + ONE_RAMP_MAX);
		}
		else newY = joystickY;
		
		if(fabs(joystickTwist) > fabs(oldTwist)){
			newTwist = absMin(joystickTwist, oldTwist + ONE_RAMP_MAX);
		}
		else newTwist = joystickTwist;
		
		oldX = newX;
		oldY = newY;
		oldTwist = newTwist;
	//Ramp Done
	
	//TODO Needs adjustment to scaling and possibly other things
	
	double joyAngle = atan2(newX, newY);
	float joystickMagnitude = sqrt((newX * newX) + (newY * newY));
	if(newTwist < 0.05 && newTwist > -0.05){
		newTwist = 0.0;
	}
	float ccTwist = newTwist * TWIST_CONSTANT;
	float twist = -newTwist * TWIST_CONSTANT;
	double actAngle = joyAngle; 
	if (isFieldOrientation) {
		float robAngle = (gyro->GetAngle())*(PI/180.0f);
		actAngle -= robAngle;
	}
	
	float leftFrontVal = -1 * (ccTwist + joystickMagnitude*(cos(actAngle)+sin(actAngle)));
	float rightFrontVal = (twist + joystickMagnitude*(cos(actAngle)-sin(actAngle)));
	float leftBackVal= -1 * (ccTwist + joystickMagnitude*(cos(actAngle)-sin(actAngle)));
	float rightBackVal = (twist + joystickMagnitude*(cos(actAngle)+sin(actAngle)));
	
	SmartCANJaguar::SyncMask DriveSyncGroup = SmartCANJaguar::kGroup1;
	leftFront->Set(leftFrontVal, DriveSyncGroup);
	rightFront->Set(rightFrontVal, DriveSyncGroup);
	leftBack->Set(leftBackVal, DriveSyncGroup);
	rightBack->Set(rightBackVal, DriveSyncGroup);
	SmartCANJaguar::UpdateSyncGroup(DriveSyncGroup);
}
void DriveTrain::StopMotors(){
	leftFront->Set(0);
	rightFront->Set(0);
	leftBack->Set(0);
	rightBack->Set(0);
	}

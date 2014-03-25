/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include "../OI.h"
#define high DoubleSolenoid::kForward
#define off DoubleSolenoid::kOff
#define low DoubleSolenoid::kReverse
const float EXECUTE_INTVL = 20; //ms
const float FULL_RAMP_TIME = 1000; //ms
const float ONE_RAMP_MAX = EXECUTE_INTVL / FULL_RAMP_TIME;
const float TWIST_CONSTANT = 0.8f;
#define absMin(a,b) (fabs(b)<fabs(a) ? (b) : (a))
DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rightBack = RobotMap::driveTrainRightBack;
	leftBack = RobotMap::driveTrainLeftBack;
	rightFront = RobotMap::driveTrainRightFront;
	leftFront = RobotMap::driveTrainLeftFront;
	gyro = RobotMap::driveTrainGyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rightBack->SetPID(1,0,0);
	leftBack->SetPID(1,0,0);
	rightFront->SetPID(1,0,0);
	leftFront->SetPID(1,0,0);
	isFieldOrientation = false; 
	oldX = oldY = oldTwist = 0.0;
}
    
void DriveTrain::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void DriveTrain::ToggleForwardDirection()
{
	Robot::oi->getDriveStick()->ToggleInvertXAxis();
	Robot::oi->getDriveStick()->ToggleInvertYAxis();
}
void DriveTrain::ToggleOrientation(){
	isFieldOrientation = !isFieldOrientation; 	
}
bool DriveTrain::IsFieldOrientation(){
	return isFieldOrientation;
}
void DriveTrain::MecanumDriveAction(float joystickX, float joystickY, float joystickTwist) {
		
	//start of ramping
	float newX, newY, newTwist;
	if(fabs(joystickX) > fabs(oldX)){
		if(joystickX < 0){
			newX = absMin(joystickX, oldX - ONE_RAMP_MAX);
		}
		else newX = absMin(joystickX, oldX + ONE_RAMP_MAX);
	}
	else newX = joystickX;
	
	if(fabs(joystickY) > fabs(oldY)){
		if(joystickY < 0){
			newY = absMin(joystickY, oldY - ONE_RAMP_MAX);
		}
		else newY = absMin(joystickY, oldY + ONE_RAMP_MAX);
	}
	else newY = joystickY;
	
	if(fabs(joystickTwist) > fabs(oldTwist)){
		if(joystickTwist < 0){
			newTwist = absMin(joystickTwist, oldTwist - ONE_RAMP_MAX);
		}
		else newTwist = absMin(joystickTwist, oldTwist + ONE_RAMP_MAX);
	}
	else newTwist = joystickTwist;

	//lower speed / current draw of high gear
	
		
	oldX = newX;
	oldY = newY;
	oldTwist = newTwist;
	//Ramp Done

	
	/*float newX = joystickX;
	float newY = joystickY;
	float newTwist = joystickTwist;
	//cheap ramping fix above, delete when ramping works 
	printf("Joystick Y Value: %f \n", newY);
	*/
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
	leftFront->Set(leftFrontVal*30, DriveSyncGroup);
	rightFront->Set(rightFrontVal*30, DriveSyncGroup);
	leftBack->Set(leftBackVal*30, DriveSyncGroup);
	rightBack->Set(rightBackVal*30, DriveSyncGroup);
	SmartCANJaguar::UpdateSyncGroup(DriveSyncGroup); 
	//printf("LeftFront Value: %f, Right Front Value: %f, Left Back Val: %f, Right Back Val: %f \n", leftFrontVal, rightFrontVal, leftBackVal, rightBackVal);
}
/*float DriveTrain::ReturnGyroScaled(){  //returns a gyro value scaled similiarly to that of the joystick twist, so a full rotation (360 degrees) = 1 
	float gyroDegrees = (gyro->GetAngle()/(3.141592654));
	float gyroScaled = gyroDegrees/360; 
}
*/
void DriveTrain::StopMotors(){
	SmartCANJaguar::SyncMask DriveSyncGroup = SmartCANJaguar::kGroup1;
	leftFront->Set(0);
	rightFront->Set(0);
	leftBack->Set(0);
	rightBack->Set(0);
	SmartCANJaguar::UpdateSyncGroup(DriveSyncGroup);
}

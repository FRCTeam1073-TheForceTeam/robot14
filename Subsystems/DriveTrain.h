/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class DriveTrain : public Subsystem {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SmartCANJaguar* rightBack;
	SmartCANJaguar* leftBack;
	SmartCANJaguar* rightFront;
	SmartCANJaguar* leftFront;
	SmartGyro* gyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveTrain();
	void InitDefaultCommand();
	void MecanumDriveAction(float joyX, float joyY, float joystickTwist);
	void StopMotors();
	void ToggleOrientation();
	bool IsFieldOrientation(); 
private:
	int rampIteration;
	double DriveRamp(float magnitude);
	bool isFieldOrientation;
};
#endif

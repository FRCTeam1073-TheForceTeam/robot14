/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/Drive.h"

#define high DoubleSolenoid::kForward
#define off DoubleSolenoid::kOff
#define low DoubleSolenoid::kReverse

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rightBack = RobotMap::driveTrainRightBack;
	leftBack = RobotMap::driveTrainLeftBack;
	rightFront = RobotMap::driveTrainRightFront;
	leftFront = RobotMap::driveTrainLeftFront;
	doubleSolenoid = RobotMap::driveTrainDoubleSolenoid;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    lowGear = true;
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::SwitchGear() {
	if (lowGear) {
		doubleSolenoid->Set(high);
	}
	else {
		doubleSolenoid->Set(low);
	}
	lowGear = !lowGear;
}

bool DriveTrain::IsLowGear() {
	return lowGear;
}
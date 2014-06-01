/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class Elevator: public Subsystem {
	//BEGIN DEBUG CODE
	//private:
	//float angleSpeed;
	//END DEBUG CODE
private:
	static double elevatorUp;// = 2.563;
	static double elevatorDown;// = 1.43;
	static double elevatorShootPos;// = 2.42;
	static double setpointConstant;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* angleAdjuster;
	StallableAnalogEncoder* elevationEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Elevator();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void GoToShootPosition();
	void GoToMaxPosition();
	void GoToMinPosition();
	void HoldPosition();
	//BEGIN DEBUG CODE
	//void SetAngleSpeed(float swag);
	//float GetAngleSpeed();
	//END DEBUG CODE
	void IncrementSetPoint(bool up);
	double GetElevatorUp();
	double GetElevatorDown();
	double GetElevatorShootPos();
	void SetElevatorUp(double encoderVal);
	void SetElevatorDown(double encoderVal);
	void SetElevatorShootPos();	
	
	void autoDown();
	void autoUp();
	bool isAngleAdjusterReady;
	void autoStopArm();
};
#endif

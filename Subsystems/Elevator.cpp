#include "Elevator.h"
#include "../Robot.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
static const double elevatorUpDft = 3.24;
static const double elevatorDownDft = 2.02;
static const double elevatorShootPosDft = 1.74;
double Elevator::elevatorUp = 0.0;
double Elevator::elevatorDown = 0.0;
double Elevator::elevatorShootPos = 0.0;
double Elevator::setpointConstant = 1.0;
float elevatorUpSpeed = 0.0;
#define ELEVATORUP "ElevatorMax"
#define ELEVATORDOWN "ElevatorMin"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
Elevator::Elevator() : Subsystem("Elevator") {
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	angleAdjuster = RobotMap::elevatorAngleAdjuster;
	elevationEncoder = RobotMap::elevatorElevationEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	
	//DEBUG angleSpeed=0.00;
	
	elevatorUp = Robot::prefs->GetFloat(ELEVATORUP, elevatorUpDft);	
	elevatorDown = Robot::prefs->GetFloat(ELEVATORDOWN, elevatorDownDft);
	elevatorUpSpeed = Robot::prefs->GetFloat("DiagUp", 0.4);
	SetElevatorShootPos();
	setpointConstant = Robot::prefs->GetFloat("setpointConstant", setpointConstant);
	HoldPosition();
}
double Elevator::ReturnPIDInput() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return elevationEncoder->GetAverageVoltage();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}
void Elevator::UsePIDOutput(double output) {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
	angleAdjuster->PIDWrite(output);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}
void Elevator::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Elevator::GoToShootPosition(){
	angleAdjuster->Set(-1 * setpointConstant);
}
void Elevator::GoToMaxPosition(){
	angleAdjuster->Set(setpointConstant);
}
void Elevator::GoToMinPosition(){
	angleAdjuster->Set(-1 * setpointConstant);
}
void Elevator::IncrementSetPoint(bool up) {
	angleAdjuster->Set(setpointConstant * (up ? 1 : -1));
}
void Elevator::HoldPosition() {
	// fall back, just cut power
	angleAdjuster->Set(0.0f);
}
void Elevator::SetElevatorDown(double encoderVal){
	elevatorDown = encoderVal; 
	Robot::prefs->PutFloat(ELEVATORDOWN, encoderVal);
	Robot::prefs->Save();
}
void Elevator::SetElevatorUp(double encoderVal){
	elevatorUp = encoderVal; 
	Robot::prefs->PutFloat(ELEVATORUP, encoderVal);
	Robot::prefs->Save();
}
void Elevator::SetElevatorShootPos(){
	
	if (GetElevatorUp() < GetElevatorDown())
	{
		//zero crossing
		double shootPos = ((GetElevatorUp() + 5.0)-GetElevatorDown())*(0.95)+GetElevatorDown();
		if (shootPos >= 5.0)
			shootPos -= 5.0;
		elevatorShootPos = shootPos;
	}
	else
		elevatorShootPos = (GetElevatorUp()-GetElevatorDown())*(0.95)+GetElevatorDown();
}
double Elevator::GetElevatorDown(){return elevatorDown;}
double Elevator::GetElevatorUp(){return elevatorUp;}
double Elevator::GetElevatorShootPos(){return elevatorShootPos;}


//END DEBUG CODE
void Elevator::autoDown(){
	angleAdjuster->Set(-0.6);
}
void Elevator::autoUp(){
	angleAdjuster->Set(elevatorUpSpeed);
}
void Elevator::autoStopArm(){
	float angleSpeed = angleAdjuster->Get();
	if((-.3f>angleSpeed)&&(angleSpeed>-.7f))
		isAngleAdjusterReady=true;
	if((.3f<angleSpeed)&&(angleSpeed<.7f)&&!isAngleAdjusterReady)
		isAngleAdjusterReady=true;
	angleAdjuster->Set(0);
}

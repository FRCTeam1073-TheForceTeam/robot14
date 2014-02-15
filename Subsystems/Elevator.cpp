#include "Elevator.h"
#include "../Robot.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
static const double elevatorUpDft = 4.337;
static const double elevatorDownDft = 3.283;
static const double elevatorShootPosDft = 4.157;
double Elevator::elevatorUp = 0.0;
double Elevator::elevatorDown = 0.0;
double Elevator::elevatorShootPos = 0.0;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
Elevator::Elevator() : PIDSubsystem("Elevator", 1.0, 0.0, 0.0) {
	SetAbsoluteTolerance(0.2);
	GetPIDController()->SetContinuous(false);
	LiveWindow::GetInstance()->AddActuator("Elevator", "PIDSubsystem Controller", GetPIDController());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	angleAdjuster = RobotMap::elevatorAngleAdjuster;
	elevationEncoder = RobotMap::elevatorElevationEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	if(Robot::GetWhichRobot() == Robot::atlasRobot){
		Enable();
		printf("In Elevator Method: PID Enabled");
	}
	else{
		Disable();
		printf("In Elevator Method: PID Disabled");
	}	
	//DEBUG angleSpeed=0.00;
	
	elevatorUp = Robot::prefs->GetFloat("ElevationMax", elevatorUpDft);	
	elevatorDown = Robot::prefs->GetFloat("ElevationMin", elevatorDownDft);	
	elevatorShootPos = Robot::prefs->GetFloat("ElevationShootPos", elevatorShootPosDft);
	
	SetSetpoint(elevatorShootPos);
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
void Elevator::GoToShootPosition(){SetSetpoint(elevatorShootPos);}
void Elevator::GoToMaxPosition(){SetSetpoint(elevatorUp);}
void Elevator::GoToMinPosition(){SetSetpoint(elevatorDown);}
#define SETPOINT_CONSTANT .3 // TODO make this less jagged
void Elevator::IncrementSetPoint(bool up) {
	SetSetpoint(GetSetpoint() + (up ? SETPOINT_CONSTANT : -1 * SETPOINT_CONSTANT));
}
void Elevator::HoldPosition() {SetSetpoint(elevationEncoder->GetAverageVoltage());}
void Elevator::SetElevatorDown(double encoderVal){elevatorDown = encoderVal;}
void Elevator::SetElevatorUp(double encoderVal){elevatorUp = encoderVal;}
void Elevator::SetElevatorShootPos(double encoderVal){elevatorShootPos = encoderVal;}
double Elevator::GetElevatorDown(){return elevatorDown;}
double Elevator::GetElevatorUp(){return elevatorUp;}
double Elevator::GetElevatorShootPos(){return elevatorShootPos;}
void Elevator::TogglePIDEnabled(){
	if (GetPIDController()->IsEnabled()) Disable();
	else Enable();
}
//BEGIN DEBUG CODE
/*void Elevator::SetAngleSpeed(float swag){
	angleSpeed=swag;
	angleAdjuster->Set(angleSpeed);
}
float Elevator::GetAngleSpeed(){
	return angleSpeed;
}*/
//END DEBUG CODE

#include "Elevator.h"
#include "../Robot.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

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
	SetSetpoint(ELEVATOR_UP);
	lastManualDirectionUp = true;
	if(Robot::GetWhichRobot() == Robot::atlasRobot){
		Enable();
		printf("In Elevator Method: PID Enabled");
	}
	else{
		Disable();
		printf("In Elevator Method: PID Disabled");
	}	
	//DEBUG angleSpeed=0.00;
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

void Elevator::GoToShootPosition(){SetSetpoint(ELEVATOR_SHOOTPOS);}
void Elevator::GoToMaxPosition(){SetSetpoint(ELEVATOR_UP);}
void Elevator::GoToMinPosition(){SetSetpoint(ELEVATOR_DOWN);}
bool Elevator::NotOKToMove() {
	return elevationEncoder->IsStall();
}
#define SETPOINT_CONSTANT .3 // TODO make this less jagged
void Elevator::IncrementSetPoint(bool up) {
	bool delta = up != lastManualDirectionUp;
	if (delta) puts("Oh, rats! We are currently having a delta. Fooey!!!");
	if(!(NotOKToMove()) || up != lastManualDirectionUp){
		float f = GetSetpoint() + (up ? SETPOINT_CONSTANT : -1 * SETPOINT_CONSTANT);
		printf("%f\n", f);
		SetSetpoint(f);
	}
	else puts("stall");
	lastManualDirectionUp = up;
}
void Elevator::HoldPosition() {SetSetpoint(elevationEncoder->GetAverageVoltage());}
//BEGIN DEBUG CODE
/*void Elevator::SetAngleSpeed(float swag){
	angleSpeed=swag;
	angleAdjuster->Set(angleSpeed);
}
float Elevator::GetAngleSpeed(){
	return angleSpeed;
}*/
//END DEBUG CODE

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Dashboard14.h"
#include "../Robotmap.h"
#include "../Commands/SendToDashboard.h"
Dashboard14::Dashboard14() : Subsystem("Dashboard14") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Dashboard14::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new SendToDashboard());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Dashboard14::SendData()
{
	SmartDashboard::PutNumber("Battery", DriverStation::GetInstance()->GetBatteryVoltage());
	SmartDashboard::PutNumber("TimeCounterWidget", DriverStation::GetInstance()->GetMatchTime());
	
}

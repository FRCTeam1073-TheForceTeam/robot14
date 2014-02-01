/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Dashboard14.h"
#include "../Robot.h"
#include "../RobotMap.cpp"
#include "../Robot.cpp"
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
	// this code doesn't do anything
	// the code starts doing stuff again here
	//SmartDashboard::PutNumber("PSI Gauge", Robot::airCompressor->GetPressurePSI);
	SmartDashboard::PutBoolean("Gear Shifter", Robot::shifter->IsLowGear());
	
	//if(Robot::airCompressor->IsHighPressure /* && good distance*/)
	//{
	//	SmartDashboard::PutNumber("Shooter Ready", 1);
	//}
	//else if(Robot:: airCompressor->IsHighPressure /* && !good distance*/)
	//{
	//	SmartDashboard::PutNumber("Shooter Ready", 0);
	//}
	//else if(Robot::airCompressor->IsLowPressure /* && good distance*/)
	//{
	//	SmartDashboard::PutNumber("Shooter Ready", -1);
	//}
	//else
	//{
	//	SmartDashboard::PutNumber("Shooter Ready", -2);
	//}
	
	
}

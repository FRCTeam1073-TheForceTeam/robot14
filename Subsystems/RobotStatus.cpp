/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "RobotStatus.h"
#include "../Robotmap.h"
#include "../Robot.h"
RobotStatus::RobotStatus() : Subsystem("RobotStatus") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void RobotStatus::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void RobotStatus::SetError(StatusCode code){
	switch (code){
	case LAUNCHER_READY:
		Robot::bling->SetColor(Bling::GREEN);
		printf("RobotStatus: Launcher Ready\n");
		break;
	case LAUNCHER_UNREADY:
		Robot::bling->SetColor(Bling::ORANGE);
		printf("RobotStatus: Launcher Unready\n");
		break;
	case LAUNCHER_ERROR:
		Robot::bling->SetColor(Bling::RED);
		printf("RobotStatus: Launcher Error\n");
	default:
		printf("RobotStatus: Unknown Error: %d\n", code);
	}
	
}
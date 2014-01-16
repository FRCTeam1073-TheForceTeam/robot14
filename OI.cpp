/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Drive.h"
#include "Commands/LauchBall.h"
#include "Commands/PickUpBall.h"
#include "Commands/SwitchGear.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new SmartJoystick(2);
	
	driveStick = new SmartJoystick(1);
	
	switchGearButton = new JoystickButton(driveStick, 1);
	switchGearButton->WhenPressed(new SwitchGear());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("Lauch Ball", new LauchBall());
	SmartDashboard::PutData("SwitchGear", new SwitchGear());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
SmartJoystick* OI::getOperatorStick() {
	return operatorStick;
}
SmartJoystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

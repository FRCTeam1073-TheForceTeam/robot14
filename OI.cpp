/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Collect.h"
#include "Commands/Drive.h"
#include "Commands/ElevateCollector.h"
#include "Commands/LaunchBall.h"
#include "Commands/SwitchGear.h"
#include "Commands/ToggleDriveOrientation.h"
#include "Commands/ToggleNormalCubicJoystickMode.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new SmartJoystick(2);
	
	collectorDownButton = new JoystickButton(operatorStick, 10);
	collectorDownButton->WhileHeld(new ElevateCollector(false));
	collectorUpButton = new JoystickButton(operatorStick, 9);
	collectorUpButton->WhileHeld(new ElevateCollector(true));
	collectButton = new JoystickButton(operatorStick, 7);
	collectButton->WhileHeld(new Collect(true));
	purgeButton = new JoystickButton(operatorStick, 8);
	purgeButton->WhileHeld(new Collect(false));
	launchBallButton = new JoystickButton(operatorStick, 1);
	launchBallButton->WhileHeld(new LaunchBall());
	driveStick = new SmartJoystick(1);
	
	toggleDriveMode = new JoystickButton(driveStick, 3);
	toggleDriveMode->WhenPressed(new ToggleDriveOrientation());
	toggleJoystickMode = new JoystickButton(driveStick, 2);
	toggleJoystickMode->WhenPressed(new ToggleNormalCubicJoystickMode());
	switchGearButton = new JoystickButton(driveStick, 1);
	switchGearButton->WhenPressed(new SwitchGear());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("Collect", new Collect());
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("Launch Ball", new LaunchBall());
	SmartDashboard::PutData("SwitchGear", new SwitchGear());
	SmartDashboard::PutData("ToggleNormalCubicJoystickMode", new ToggleNormalCubicJoystickMode());
	SmartDashboard::PutData("ToggleDriveOrientation", new ToggleDriveOrientation());
	SmartDashboard::PutData("ElevateCollector", new ElevateCollector());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveStick->ToggleInvertYAxis();
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
SmartJoystick* OI::getOperatorStick() {
	return operatorStick;
}
SmartJoystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommmandGroup.h"
#include "Commands/AutonomousDriveCommand.h"
#include "Commands/AutonomousLaunchCommand.h"
#include "Commands/Collect.h"
#include "Commands/Drive.h"
#include "Commands/ElevateCollector.h"
#include "Commands/LaunchBall.h"
#include "Commands/SendToDashboard.h"
#include "Commands/ShiftHighGear.h"
#include "Commands/ShiftLowGear.h"
#include "Commands/ToggleDriveOrientation.h"
#include "Commands/ToggleForwardDirection.h"
#include "Commands/WaitForHotGoal.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new SmartJoystick(2);
	
	collectorDownButton = new JoystickButton(operatorStick, 10);
	collectorDownButton->WhileHeld(new ElevateCollector());
	collectorUpButton = new JoystickButton(operatorStick, 9);
	collectorUpButton->WhileHeld(new ElevateCollector());
	collectButton = new JoystickButton(operatorStick, 7);
	collectButton->WhileHeld(new Collect());
	purgeButton = new JoystickButton(operatorStick, 8);
	purgeButton->WhileHeld(new Collect());
	launchBallButton = new JoystickButton(operatorStick, 1);
	launchBallButton->WhileHeld(new LaunchBall());
	driveStick = new SmartJoystick(1);
	
	forwardDirectionButton = new JoystickButton(driveStick, 2);
	forwardDirectionButton->WhenPressed(new ToggleForwardDirection());
	toggleDriveMode = new JoystickButton(driveStick, 3);
	toggleDriveMode->WhenPressed(new ToggleDriveOrientation());
	highGear = new JoystickButton(driveStick, 10);
	highGear->WhenPressed(new ShiftHighGear());
	lowGear = new JoystickButton(driveStick, 9);
	lowGear->WhenPressed(new ShiftLowGear());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("ShiftLowGear", new ShiftLowGear());
	SmartDashboard::PutData("ShiftHighGear", new ShiftHighGear());
	SmartDashboard::PutData("Collect", new Collect());
	SmartDashboard::PutData("Launch Ball", new LaunchBall());
	SmartDashboard::PutData("ToggleDriveOrientation", new ToggleDriveOrientation());
	SmartDashboard::PutData("ElevateCollector", new ElevateCollector());
	SmartDashboard::PutData("AutonomousDriveCommand", new AutonomousDriveCommand());
	SmartDashboard::PutData("AutonomousCommmandGroup", new AutonomousCommmandGroup());
	SmartDashboard::PutData("WaitForHotGoal", new WaitForHotGoal());
	SmartDashboard::PutData("AutonomousLaunchCommand", new AutonomousLaunchCommand());
	SmartDashboard::PutData("ToggleForwardDirection", new ToggleForwardDirection());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveStick->ToggleInvertYAxis();
	driveStick->SetJoystickMode(SmartJoystick::cubic);
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
SmartJoystick* OI::getOperatorStick() {
	return operatorStick;
}
SmartJoystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

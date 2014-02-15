/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommmandGroup.h"
#include "Commands/AutonomousDeElevateCommand.h"
#include "Commands/AutonomousDriveCommand.h"
#include "Commands/AutonomousLaunchCommand.h"
#include "Commands/CollectorFeed.h"
#include "Commands/CollectorPurge.h"
#include "Commands/Drive.h"
#include "Commands/ElevateCollectorToBottom.h"
#include "Commands/ElevateCollectorToShooter.h"
#include "Commands/ElevateCollectorToTop.h"
#include "Commands/ElevateCollectorUp.h"
#include "Commands/ElevatorCollectorDown.h"
#include "Commands/LaunchBall.h"
#include "Commands/SendToDashboard.h"
#include "Commands/ShiftHighGear.h"
#include "Commands/ShiftLowGear.h"
#include "Commands/TestNextRobotStatus.h"
#include "Commands/ToggleDriveOrientation.h"
#include "Commands/ToggleForwardDirection.h"
#include "Commands/WaitForHotGoal.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	throttle = new SmartJoystick(3);
	
	operatorStick = new SmartJoystick(2);
	
	collectorToShooterButton = new JoystickButton(operatorStick, 2);
	collectorToShooterButton->WhenPressed(new ElevateCollectorToShooter());
	collectorToBottomButton = new JoystickButton(operatorStick, 7);
	collectorToBottomButton->WhenPressed(new ElevateCollectorToBottom());
	collectorDownButton = new JoystickButton(operatorStick, 9);
	collectorDownButton->WhileHeld(new ElevatorCollectorDown());
	collectorUpButton = new JoystickButton(operatorStick, 10);
	collectorUpButton->WhileHeld(new ElevateCollectorUp());
	collectButton = new JoystickButton(operatorStick, 12);
	collectButton->WhileHeld(new CollectorFeed());
	purgeButton = new JoystickButton(operatorStick, 11);
	purgeButton->WhileHeld(new CollectorPurge());
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
	SmartDashboard::PutData("ElevateCollectorUp", new ElevateCollectorUp());
	SmartDashboard::PutData("ElevatorCollectorDown", new ElevatorCollectorDown());
	SmartDashboard::PutData("ElevateCollectorToShooter", new ElevateCollectorToShooter());
	SmartDashboard::PutData("ElevateCollectorToTop", new ElevateCollectorToTop());
	SmartDashboard::PutData("ElevateCollectorToBottom", new ElevateCollectorToBottom());
	SmartDashboard::PutData("CollectorFeed", new CollectorFeed());
	SmartDashboard::PutData("CollectorPurge", new CollectorPurge());
	SmartDashboard::PutData("ShiftLowGear", new ShiftLowGear());
	SmartDashboard::PutData("ShiftHighGear", new ShiftHighGear());
	SmartDashboard::PutData("Launch Ball", new LaunchBall());
	SmartDashboard::PutData("ToggleDriveOrientation", new ToggleDriveOrientation());
	SmartDashboard::PutData("AutonomousDriveCommand", new AutonomousDriveCommand());
	SmartDashboard::PutData("AutonomousCommmandGroup", new AutonomousCommmandGroup());
	SmartDashboard::PutData("WaitForHotGoal", new WaitForHotGoal());
	SmartDashboard::PutData("AutonomousLaunchCommand", new AutonomousLaunchCommand());
	SmartDashboard::PutData("ToggleForwardDirection", new ToggleForwardDirection());
	SmartDashboard::PutData("TestNextRobotStatus", new TestNextRobotStatus());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveStick->ToggleInvertYAxis();
	driveStick->SetJoystickMode(SmartJoystick::cubic);
	float dcc = 0;
	if ((dcc = Robot::prefs->GetFloat("DriveCubicConstant", 0)) != 0)
		driveStick->SetCubicConstant(dcc);
	throttle->ToggleInvertZAxis();
	
	//BEGIN DEBUG CODE
		/*
		arcadeDriveButton = new JoystickButton(driveStick, 5);
		arcadeDriveButton->WhenPressed(new driveArcarde());
		collectSlowerButton = new JoystickButton(driveStick, 11);
		collectSlowerButton->WhenPressed(new collectSlower());
		collectFasterButton = new JoystickButton(driveStick, 12);
		collectFasterButton->WhenPressed(new collectFaster());
		angleDownButton = new JoystickButton(driveStick, 9);
		angleDownButton->WhenPressed(new angleDown());
		angleUpButton = new JoystickButton(driveStick, 10);
		angleUpButton->WhenPressed(new angleUp());
		shiftButton = new JoystickButton(driveStick, 8);
		shiftButton->WhenPressed(new shift());
		lauchBall = new JoystickButton(driveStick, 6);
		lauchBall->WhenPressed(new launch());
		mecanumDriveButton = new JoystickButton(driveStick, 4);
		mecanumDriveButton->WhenPressed(new drive());
		compressButton = new JoystickButton(driveStick, 2);
		compressButton->WhenPressed(new compress());
	    */
		//END DEBUG CODE
	
	
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
SmartJoystick* OI::getThrottle() {
	return throttle;
}
SmartJoystick* OI::getOperatorStick() {
	return operatorStick;
}
SmartJoystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

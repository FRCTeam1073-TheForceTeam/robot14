/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommmandGroup.h"
#include "Commands/AutonomousDeElevateCommand.h"
#include "Commands/AutonomousDriveCommand.h"
#include "Commands/AutonomousHoldElevatorPos.h"
#include "Commands/AutonomousLaunchCommand.h"
#include "Commands/CatchMode.h"
#include "Commands/CollectToggle.h"
#include "Commands/CollectorFeed.h"
#include "Commands/CollectorFeedWithTimeoutCommand.h"
#include "Commands/CollectorOff.h"
#include "Commands/CollectorPurge.h"
#include "Commands/Drive.h"
#include "Commands/DumbDriveForwardUntilTimeout.h"
#include "Commands/ElevateCollectorToBottom.h"
#include "Commands/ElevateCollectorToShooter.h"
#include "Commands/ElevateCollectorToTop.h"
#include "Commands/ElevateCollectorUp.h"
#include "Commands/ElevatorAutoCalibration.h"
#include "Commands/ElevatorCollectorDown.h"
#include "Commands/ElevatorOff.h"
#include "Commands/LaunchBall.h"
#include "Commands/SendToDashboard.h"
#include "Commands/ShiftHighGear.h"
#include "Commands/ShiftLowGear.h"
#include "Commands/TalonCalibrateNegative.h"
#include "Commands/TalonCalibratePositive.h"
#include "Commands/TestNextRobotStatus.h"
#include "Commands/ToggleDriveOrientation.h"
#include "Commands/ToggleForwardDirection.h"
#include "Commands/WaitForHotGoal.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new SmartJoystick(2);
	
	catchModeButton = new JoystickButton(operatorStick, 8);
	catchModeButton->WhileHeld(new CatchMode());
	collectorToShooterButton = new JoystickButton(operatorStick, 2);
	collectorToShooterButton->WhenPressed(new ElevateCollectorToShooter());
	collectorDownButton2 = new JoystickButton(operatorStick, 3);
	collectorDownButton2->WhileHeld(new ElevatorCollectorDown());
	collectorDownButton = new JoystickButton(operatorStick, 4);
	collectorDownButton->WhileHeld(new ElevatorCollectorDown());
	collectorUpButton2 = new JoystickButton(operatorStick, 5);
	collectorUpButton2->WhileHeld(new ElevateCollectorUp());
	collectorUpButton = new JoystickButton(operatorStick, 6);
	collectorUpButton->WhileHeld(new ElevateCollectorUp());
	collectButtonToggle = new JoystickButton(operatorStick, 11);
	collectButtonToggle->WhenPressed(new CollectToggle());
	collectButtonHold = new JoystickButton(operatorStick, 9);
	collectButtonHold->WhileHeld(new CollectorFeed());
	purgeButton = new JoystickButton(operatorStick, 12);
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
	SmartDashboard::PutData("CollectorFeed", new CollectorFeed());
	SmartDashboard::PutData("CollectorPurge", new CollectorPurge());
	SmartDashboard::PutData("Launch Ball", new LaunchBall());
	SmartDashboard::PutData("TestNextRobotStatus", new TestNextRobotStatus());
	SmartDashboard::PutData("TalonCalibratePositive", new TalonCalibratePositive());
	SmartDashboard::PutData("TalonCalibrateNegative", new TalonCalibrateNegative());
	SmartDashboard::PutData("ElevatorAutoCalibration", new ElevatorAutoCalibration());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	testDiag = new JoystickButton(driveStick, 11);
	driveStick->ToggleInvertYAxis();
	driveStick->SetJoystickMode(SmartJoystick::cubic);
	float dcc = 0;
	if ((dcc = Robot::prefs->GetFloat("DriveCubicConstant", 0)) != 0)
		driveStick->SetCubicConstant(dcc);
	
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
SmartJoystick* OI::getOperatorStick() {
	return operatorStick;
}
SmartJoystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
JoystickButton* OI::getCatchModeButton(){ return catchModeButton;}
JoystickButton* OI::getCollectorToShooterButton(){ return collectorToShooterButton;}
JoystickButton* OI::getCollectorDownButton2(){ return collectorDownButton2;}
JoystickButton* OI::getCollectorDownButton(){ return collectorDownButton;}
JoystickButton* OI::getCollectorUpButton2(){ return collectorUpButton2;}
JoystickButton* OI::getCollectorUpButton(){ return collectorUpButton;}
JoystickButton* OI::getCollectButtonToggle(){ return collectButtonToggle;}
JoystickButton* OI::getCollectButtonHold(){ return collectButtonHold;}
JoystickButton* OI::getPurgeButton(){ return purgeButton;}
JoystickButton* OI::getLaunchBallButton(){ return launchBallButton;}

JoystickButton* OI::getForwardDirectionButton(){ return forwardDirectionButton;}
JoystickButton* OI::getToggleDriveMode(){ return toggleDriveMode;}
JoystickButton* OI::getHighGear(){ return highGear;}
JoystickButton* OI::getLowGear(){ return lowGear;}
JoystickButton* OI::getDiagButton(){ return testDiag;}

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SmartJoystick* operatorStick;
	JoystickButton* catchModeButton;
	JoystickButton* collectorToShooterButton;
	JoystickButton* collectorDownButton2;
	JoystickButton* collectorDownButton;
	JoystickButton* collectorUpButton2;
	JoystickButton* collectorUpButton;
	JoystickButton* collectButtonToggle;
	JoystickButton* collectButtonHold;
	JoystickButton* purgeButton;
	JoystickButton* launchBallButton;
	SmartJoystick* driveStick;
	JoystickButton* forwardDirectionButton;
	JoystickButton* toggleDriveMode;
	JoystickButton* highGear;
	JoystickButton* lowGear;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//BEGIN DEBUG CODE
	/*JoystickButton* arcadeDriveButton;
	JoystickButton* collectSlowerButton;
	JoystickButton* collectFasterButton;
	JoystickButton* angleDownButton;
	JoystickButton* angleUpButton;
	JoystickButton* shiftButton;
	JoystickButton* lauchBall;
	JoystickButton* mecanumDriveButton;
	JoystickButton* compressButton;*/
	//END DEBUG CODE
public:
	OI();
 
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	SmartJoystick* getDriveStick();
	SmartJoystick* getOperatorStick();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};
#endif

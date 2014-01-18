/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "ToggleNormalCubicJoystickMode.h"
ToggleNormalCubicJoystickMode::ToggleNormalCubicJoystickMode() {
	isCubic = false;
	ChangeJoystickModeCommand::AddSmartJoystickPointers(1, Robot::oi->getDriveStick());
	normalJoysticks = new ChangeJoystickModeCommand(SmartJoystick::normal);
	cubicJoysticks = new ChangeJoystickModeCommand(SmartJoystick::cubic);
	
}
void ToggleNormalCubicJoystickMode::Initialize() {
	if (isCubic)  normalJoysticks->Start();
	else cubicJoysticks->Start();
	isCubic = !isCubic;
}
void ToggleNormalCubicJoystickMode::Execute() {}
bool ToggleNormalCubicJoystickMode::IsFinished() {return true;}
void ToggleNormalCubicJoystickMode::End() {}
void ToggleNormalCubicJoystickMode::Interrupted() {}

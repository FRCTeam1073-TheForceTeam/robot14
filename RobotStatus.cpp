#include "RobotStatus.h"
RobotStatus::LAUNCHER_STATUS RobotStatus::launcherStatus = LAUNCHER_NOT_READY;
RobotStatus::SHIFTING_STATUS RobotStatus::shiftingStatus = SHIFTER_HIGH;
RobotStatus::AUTONOMOUS_STATUS RobotStatus::autonomousStatus = AUTONOMOUS_DRIVING;
bool RobotStatus::error = true;
void RobotStatus::RobotStatusInit() {
	autonomousStatus = AUTONOMOUS_DRIVING;
	launcherStatus = LAUNCHER_NOT_READY;
	shiftingStatus = SHIFTER_LOW;
	error = false;
}
RobotStatus::LAUNCHER_STATUS RobotStatus::GetLaunhcerStatus() {return launcherStatus;}
RobotStatus::SHIFTING_STATUS RobotStatus::GetShiftingStatus() {return shiftingStatus;}
RobotStatus::AUTONOMOUS_STATUS RobotStatus::GetAutonomousStatus() {return autonomousStatus;}
bool RobotStatus::IsError() {return error;}

void RobotStatus::SetLauncherStatus(LAUNCHER_STATUS launcherStatus) {
	RobotStatus::launcherStatus = launcherStatus;
	RobotStatus::UpdateBling();
}

void RobotStatus::SetShiftingStatus(SHIFTING_STATUS shiftingStatus) {
	RobotStatus::shiftingStatus = shiftingStatus;
	RobotStatus::UpdateBling();
}

void RobotStatus::SetAutonomousStatus(AUTONOMOUS_STATUS autonomousStatus) {
	RobotStatus::autonomousStatus = autonomousStatus;
	RobotStatus::UpdateBling();
}

void RobotStatus::SetError(bool error) {
	RobotStatus::error = error;
	RobotStatus::UpdateBling();
}

void RobotStatus::UpdateBling() {
	
}

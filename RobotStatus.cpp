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
	Bling::PATTERN p = Bling::OFF;
	if (error) {p = Bling::RED_BLINKING;}
	else if (Robot::getInstance().IsAutonomous()) {
		switch (autonomousStatus) {
		case AUTONOMOUS_DRIVING:
			p = Bling::PURPLE_BLINKING;
			break;
		case AUTONOMOUS_WAIT:
			p = Bling::PURPLE_SOLID;
			break;
		case AUTONOMOUS_SHOOT:
			p = Bling::RAINBOW_EXPLOSION;
			break;
		case AUTONOMOUS_DONE:
			p = Bling::RAINBOW_EXPLOSION;
			break;
		}
	}
	else{
			if (launcherStatus == LAUNCHER_SHOOTING) {
			p = Bling::RAINBOW_EXPLOSION;
		}
		else if (launcherStatus == LAUNCHER_READY) {
			if (shiftingStatus == SHIFTER_LOW) p = Bling::GREEN_BLINKING;
			else p = Bling::GREEN_SOLID;
		}
		else if (launcherStatus == LAUNCHER_READY) {
			if (shiftingStatus == SHIFTER_LOW) p = Bling::BLUE_BLINKING;
			else p = Bling::BLUE_SOLID;
		}
	}
	Robot::bling->SetPattern(p);
}

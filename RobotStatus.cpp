#include "RobotStatus.h"
RobotStatus::LAUNCHER_STATUS RobotStatus::launcherStatus = LAUNCHER_NOT_READY;
RobotStatus::SHIFTING_STATUS RobotStatus::shiftingStatus = SHIFTER_HIGH;
RobotStatus::AUTONOMOUS_STATUS RobotStatus::autonomousStatus = AUTONOMOUS_DRIVING;
bool RobotStatus::error = true;
void RobotStatus::RobotStatusInit() {
	autonomousStatus = AUTONOMOUS_PREMATCH;
	launcherStatus = LAUNCHER_NOT_READY;
	shiftingStatus = SHIFTER_LOW;
	error = false;
	UpdateBling();
}
RobotStatus::LAUNCHER_STATUS RobotStatus::GetLauncherStatus() {return launcherStatus;}
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

/* Each time it is called, this method goes to the next logical status, eventually cycling
 * through all possible statuses in priority order autonomous, launcher, shifter, error
 */

#define NEXT_SHIFT_STATUS (SHIFTING_STATUS)(((int) shiftingStatus + 1) % (int) SHIFTER_LAST)
#define NEXT_AUTO_STATUS (AUTONOMOUS_STATUS)(((int) autonomousStatus + 1) % (int) AUTONOMOUS_LAST)
#define NEXT_LAUNCHER_STATUS (LAUNCHER_STATUS)(((int) launcherStatus + 1) % (int) LAUNCHER_LAST)

void RobotStatus::NextStatus(){
	if (autonomousStatus != (AUTONOMOUS_LAST - 1)) {
		autonomousStatus = NEXT_AUTO_STATUS;
		UpdateBling();
		return;
	}
    
    if (error) {
        error = false;
        if (shiftingStatus != (SHIFTER_LAST - 1)) {
            shiftingStatus = NEXT_SHIFT_STATUS;
        }
        else if (launcherStatus != (LAUNCHER_LAST - 1)) {
            shiftingStatus = NEXT_SHIFT_STATUS;
            launcherStatus = NEXT_LAUNCHER_STATUS;
        }
        
    }
    else error = true;
/*    DriverStationLCD *lcd = DriverStationLCD::GetInstance();
    lcd->PrintfLine(DriverStationLCD::kUser_Line1, "autoStatus %d, shiftStatus %d, launchStatus %d, error %d", autonomousStatus,
    		shiftingStatus, launcherStatus, error);
    lcd->UpdateLCD(); */
	UpdateBling();
    
    if ((NEXT_AUTO_STATUS == AUTONOMOUS_PREMATCH) && (NEXT_LAUNCHER_STATUS == LAUNCHER_NOT_READY) &&
        (NEXT_SHIFT_STATUS == SHIFTER_LOW) && error)
        RobotStatusInit();
}

void RobotStatus::UpdateBling() {
	Bling::PATTERN p =  Bling::OFF;
	/*
	printf("Auto Status: %d, Shifter Status: %d Launcher Status: %d Error: %d\n", autonomousStatus,
			shiftingStatus, launcherStatus, error ? 1 : 0);
	*/
	if (error) {
		p = Bling::RED_BLINKING;
	}
	else if (Robot::getInstance().IsDisabled()) {
		p = Bling::RAINBOW_EXPLOSION;
	}
	else if (Robot::getInstance().IsAutonomous() || autonomousStatus != TELEOP) {
		switch (autonomousStatus) {
		case AUTONOMOUS_PREMATCH:
			p = Bling::RAINBOW_EXPLOSION;
			break;
		case AUTONOMOUS_DRIVING:
			p = Bling::PURPLE_SOLID;
			break;
		case AUTONOMOUS_WAIT:
			p = Bling::PURPLE_BLINKING;
			break;
		case AUTONOMOUS_SHOOT:
			p = Bling::RAINBOW_EXPLOSION;
			break;
		case TELEOP:
			p = Bling::RAINBOW_EXPLOSION;
			break;
		case AUTONOMOUS_LAST: break;
		default:
			p = Bling::RED_BLINKING;
		}
	}
	else {		// must be in teleop mode
		if (launcherStatus == LAUNCHER_SHOOTING) {
			p = Bling::RAINBOW_EXPLOSION;
		}
		else if (launcherStatus == LAUNCHER_READY) {
			if (shiftingStatus == SHIFTER_LOW) p = Bling::GREEN_BLINKING;
			else p = Bling::GREEN_SOLID;
		}
		else if (launcherStatus == LAUNCHER_NOT_READY) {
			if (shiftingStatus == SHIFTER_LOW) p = Bling::BLUE_BLINKING;
			else p = Bling::BLUE_SOLID;
		}
	}
	//printf("Set pattern called with %d\n", p);
	Robot::bling->SetPattern(p); 
}

/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef ROBOT_STATUS_H
#define ROBOT_STATUS_H
#include "Robot.h"
#include "Subsystems/Bling.h"
class RobotStatus {
public:
		
	typedef enum LAUNCHER_STATUS {
		LAUNCHER_NOT_READY, LAUNCHER_READY, LAUNCHER_SHOOTING, LAUNCHER_LAST
	};
	
	typedef enum SHIFTING_STATUS {
		SHIFTER_LOW, SHIFTER_HIGH, SHIFTER_LAST
	};
	
	typedef enum AUTONOMOUS_STATUS {
		AUTONOMOUS_PREMATCH, AUTONOMOUS_DRIVING, AUTONOMOUS_WAIT, AUTONOMOUS_SHOOT, TELEOP, AUTONOMOUS_LAST
	};
	
	static void RobotStatusInit();
	
	static LAUNCHER_STATUS GetLauncherStatus();
	static SHIFTING_STATUS GetShiftingStatus();
	static AUTONOMOUS_STATUS GetAutonomousStatus();
	static bool IsError();
	
	static void SetLauncherStatus(LAUNCHER_STATUS launcherStatus);
	static void SetShiftingStatus(SHIFTING_STATUS shiftingStatus);
	static void SetAutonomousStatus(AUTONOMOUS_STATUS autonomousStatus);
	static void SetError(bool error);
	static void NextStatus(void);
	
private:
	static LAUNCHER_STATUS launcherStatus;
	static SHIFTING_STATUS shiftingStatus;
	static AUTONOMOUS_STATUS autonomousStatus;
	static bool error;
	static void UpdateBling();
};
#endif

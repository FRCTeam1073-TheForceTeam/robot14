/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef _ROBOT_H
#define _ROBOT_H
#define DIGITAL_JUMPER_14 14
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "RobotStatus.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommmandGroup.h"
#include "Subsystems/AirCompressor.h"
#include "Subsystems/Bling.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Dashboard14.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Launcher.h"
#include "Subsystems/RobotRangeFinder.h"
#include "Subsystems/Shifter.h"
#include "Subsystems/Vision.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// BEGIN DEBUG CODE
//#include "Subsystems/DataSending.h"
//END DEBUG CODE
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Bling* bling;
	static DriveTrain* driveTrain;
	static Launcher* launcher;
	static Collector* collector;
	static Shifter* shifter;
	static AirCompressor* airCompressor;
	static Vision* vision;
	static Dashboard14* dashboard14;
	static RobotRangeFinder* robotRangeFinder;
	static Elevator* elevator;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//BEGIN DEBUG CODE
	//static DataSending* dataSending;
	//END DEBUG CODE
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	static enum WhatRobot_t {atlasRobot, mobileBase2014} whatRobot;
	static WhatRobot_t GetWhichRobot();
private:
	static DigitalInput *jumper14;
};
#endif

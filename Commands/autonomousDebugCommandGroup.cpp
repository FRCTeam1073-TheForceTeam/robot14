/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "autoCollector.h"
#include "autoElevator.h"
#include "autoDriveTrain.h"
#include "autoLauncher.h"
#include "autoShiftToHigh.h"
#include "autoShiftToLow.h"
#include "autonomousDebugCommandGroup.h"
#include "isRobotReady.h"
autonomousDebugCommandGroup::autonomousDebugCommandGroup() {
	AddSequential(new autoLauncher());
	AddSequential(new autoShiftToLow());
	AddSequential(new autoDriveTrain());
	AddSequential(new autoShiftToHigh());
	AddSequential(new autoDriveTrain());
	AddSequential(new autoShiftToLow());
	AddSequential(new autoElevator());
	AddSequential(new autoCollector());
	AddSequential(new isRobotReady());
}

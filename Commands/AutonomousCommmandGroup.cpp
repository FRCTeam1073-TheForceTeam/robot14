/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */



#include "AutonomousCommmandGroup.h"
#include "AutonomousDriveCommand.h"
#include "WaitForHotGoal.h"
#include "AutonomousLaunchCommand.h"
#include "AutonomousDeElevateCommand.h"
#include "ShiftLowGear.h"
#include "ShiftHighGear.h"
#include "ElevateCollectorToBottom.h"
#include "ElevateCollectorToTop.h"
#include "CollectToggle.h"
#include "ElevatorOff.h"
AutonomousCommmandGroup::AutonomousCommmandGroup() {
	AddParallel(new ElevateCollectorToBottom());
	AddParallel(new CollectToggle());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new ElevatorOff());
	AddParallel(new CollectToggle());
	AddSequential(new ShiftLowGear());
	AddSequential(new AutonomousDriveCommand());
	AddSequential(new AutonomousLaunchCommand());
	AddSequential(new WaitCommand(1));
	AddSequential(new CollectToggle());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new ElevateCollectorToTop());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new AutonomousDeElevateCommand());
	AddSequential(new AutonomousLaunchCommand());
	AddSequential(new ShiftLowGear());
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}

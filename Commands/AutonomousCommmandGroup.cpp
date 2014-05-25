/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */



#include "AutonomousCommmandGroup.h"
#include "AutonomousDriveCommand.h"
#include "WaitForHotGoal.h"
#include "AutonomousLaunchCommand.h"
#include "AutonomousDeElevateCommand.h"
#include "ShiftLowGear.h"
#include "ShiftHighGear.h"
#include "AutonomousHoldElevatorPos.h"
#include "ElevatorOff.h"
AutonomousCommmandGroup::AutonomousCommmandGroup() {
	AddSequential(new AutonomousDeElevateCommand());
	AddSequential(new ShiftLowGear());
	AddSequential(new AutonomousDriveCommand());
	AddSequential(new AutonomousHoldElevatorPos());
	AddSequential(new WaitForHotGoal());
	AddSequential(new AutonomousLaunchCommand());
	AddSequential(new ElevatorOff());
	AddSequential(new ShiftLowGear());
	//test commit
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

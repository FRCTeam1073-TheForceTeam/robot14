/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "autoLauncher.h"
autoLauncher::autoLauncher() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	//set all the variables to false in the beggining
	Robot::driveTrain->isDriveTrainReady=false;
	Robot::elevator->isAngleAdjusterReady=false;
	Robot::collector->isCollectorReady=false;
	Robot::launcher->isCompressorReady=false;
	Robot::launcher->isLaucherReady=false;
}
// Called just before this Command runs the first time
void autoLauncher::Initialize() {
	puts("Testing the Laucher and Compressor...\n");
	Wait(1);
}
// Called repeatedly when this Command is scheduled to run
void autoLauncher::Execute() {
	if((bool)RobotMap::launcherCompressor->GetPressureSwitchValue()){
		puts("Not testing the laucher subsystem due to pressure already exists...\n");
	}
	else{//assume there is no air in the compressor and the valve is closed
		puts("Adding a small amount for the Laucher...\n");
		Robot::launcher->compressor->Start();
		Wait(2);
		Robot::launcher->compressor->Stop();
		puts("Lauching the Ball without air...\n");
		Robot::launcher->OpenTank();
		Wait(0.1);
		Robot::launcher->autoStopLauch();
		puts("Waiting for enough compressor for the shifters...\n");
		Robot::launcher->compressor->Start();
		Wait(5);
		Robot::launcher->canCompress();
	}
}
// Make this return true when this Command no longer needs to run execute()
bool autoLauncher::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void autoLauncher::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoLauncher::Interrupted() {
}

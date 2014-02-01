/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
RobotStatus* Robot::robotStatus = 0;
DriveTrain* Robot::driveTrain = 0;
Launcher* Robot::launcher = 0;
Collector* Robot::collector = 0;
Shifter* Robot::shifter = 0;
AirCompressor* Robot::airCompressor = 0;
Vision* Robot::vision = 0;
Dashboard14* Robot::dashboard14 = 0;
OI* Robot::oi = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
void Robot::RobotInit() {
	
	printf("\n\nFRC2014 " __DATE__ " " __TIME__ "\n\n" __FILE__ "\n\n");
	
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	robotStatus = new RobotStatus();
	driveTrain = new DriveTrain();
	launcher = new Launcher();
	collector = new Collector();
	shifter = new Shifter();
	airCompressor = new AirCompressor();
	vision = new Vision();
	dashboard14 = new Dashboard14();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// keep this here
	oi = new OI();
	lw = LiveWindow::GetInstance();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommmandGroup();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }
	
void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);

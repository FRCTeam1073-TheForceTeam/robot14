/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
bool RobotMap::disableautonomous = true;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SmartCANJaguar* RobotMap::driveTrainRightBack = NULL;
SmartCANJaguar* RobotMap::driveTrainLeftBack = NULL;
SmartCANJaguar* RobotMap::driveTrainRightFront = NULL;
SmartCANJaguar* RobotMap::driveTrainLeftFront = NULL;
SmartGyro* RobotMap::driveTrainGyro = NULL;
Compressor* RobotMap::launcherCompressor = NULL;
Solenoid* RobotMap::launcherSolenoidLeft = NULL;
Solenoid* RobotMap::launcherSolenoidRight = NULL;
SpeedController* RobotMap::collectorLeftRoller = NULL;
SpeedController* RobotMap::collectorRightRoller = NULL;
DoubleSolenoid* RobotMap::shifterDoubleSolenoid = NULL;
StallableAnalogEncoder* RobotMap::robotRangeFinderUltrasonicSensor = NULL;
SmartCANJaguar* RobotMap::elevatorAngleAdjuster = NULL;
StallableAnalogEncoder* RobotMap::elevatorElevationEncoder = NULL;
StallableAnalogEncoder* RobotMap::dataSendingBatteryCurrent = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
AnalogPressureTransducer* RobotMap::launcherPressureSwitch = NULL;
SPI* RobotMap::bling = NULL;
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveTrainRightBack = new SmartCANJaguar(4,SmartCANJaguar::kCurrent);
	
	
	driveTrainLeftBack = new SmartCANJaguar(3,SmartCANJaguar::kCurrent);
	
	
	driveTrainRightFront = new SmartCANJaguar(5,SmartCANJaguar::kCurrent);
	
	
	driveTrainLeftFront = new SmartCANJaguar(2,SmartCANJaguar::kCurrent);
	
	
	driveTrainGyro = new SmartGyro(1, 1);
	lw->AddSensor("Drive Train", "Gyro", driveTrainGyro);
	driveTrainGyro->SetSensitivity(0.007);
	launcherCompressor = new Compressor(1, 1, 1, 1);
	
	
	launcherSolenoidLeft = new Solenoid(1, 1);
	lw->AddActuator("Launcher", "SolenoidLeft", launcherSolenoidLeft);
	
	launcherSolenoidRight = new Solenoid(1, 4);
	lw->AddActuator("Launcher", "SolenoidRight", launcherSolenoidRight);
	
	collectorLeftRoller = new Talon(1, 2);
	lw->AddActuator("Collector", "Left Roller", (Talon*) collectorLeftRoller);
	
	collectorRightRoller = new Talon(1, 3);
	lw->AddActuator("Collector", "Right Roller", (Talon*) collectorRightRoller);
	
	shifterDoubleSolenoid = new DoubleSolenoid(1, 2, 3);      
	
	
	robotRangeFinderUltrasonicSensor = new StallableAnalogEncoder(1, 4);
	lw->AddSensor("RobotRangeFinder", "UltrasonicSensor", robotRangeFinderUltrasonicSensor);
	
	elevatorAngleAdjuster = new SmartCANJaguar(6);
	
	
	elevatorElevationEncoder = new StallableAnalogEncoder(1, 2);
	lw->AddSensor("Elevator", "Elevation Encoder", elevatorElevationEncoder);
	
	dataSendingBatteryCurrent = new StallableAnalogEncoder(1, 5);
	lw->AddSensor("DataSending", "BatteryCurrent", dataSendingBatteryCurrent);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//BEGIN DEBUG CODE
	//dataSendingBatteryCurrent = new StallableAnalogEncoder(1, 5);
	//END DEBUG CODE
	// init quad encoders?
			
	
	driveTrainGyro->SetGyroMode(SmartGyro::radians);
	// don't have hardware
	launcherPressureSwitch = new AnalogPressureTransducer(1, 3);
	bling = new SPI(new DigitalOutput(1,3), new DigitalOutput(1,2));
}

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
Solenoid* RobotMap::launcherSolenoid = NULL;
DigitalInput* RobotMap::collectorHighLimit = NULL;
DigitalInput* RobotMap::collectorLowLimit = NULL;
SpeedController* RobotMap::collectorLeftRoller = NULL;
SpeedController* RobotMap::collectorRightRoller = NULL;
SmartCANJaguar* RobotMap::collectorAngleAdjuster = NULL;
DoubleSolenoid* RobotMap::shifterDoubleSolenoid = NULL;
Compressor* RobotMap::airCompressorCompressor = NULL;
StallableAnalogEncoder* RobotMap::robotRangeFinderUltrasonicSensor = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
AnalogPressureTransducer* RobotMap::launcherLowPressureSwitch = NULL;
SPI* RobotMap::bling = NULL;
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveTrainRightBack = new SmartCANJaguar(4);
	
	
	driveTrainLeftBack = new SmartCANJaguar(3);
	
	
	driveTrainRightFront = new SmartCANJaguar(5);
	
	
	driveTrainLeftFront = new SmartCANJaguar(2);
	
	
	driveTrainGyro = new SmartGyro(1, 1);
	lw->AddSensor("Drive Train", "Gyro", driveTrainGyro);
	driveTrainGyro->SetSensitivity(0.007);
	launcherSolenoid = new Solenoid(1, 1);
	lw->AddActuator("Launcher", "Solenoid", launcherSolenoid);
	
	collectorHighLimit = new DigitalInput(1, 13);
	lw->AddSensor("Collector", "High Limit", collectorHighLimit);
	
	collectorLowLimit = new DigitalInput(1, 14);
	lw->AddSensor("Collector", "Low Limit", collectorLowLimit);
	
	collectorLeftRoller = new Talon(1, 2);
	lw->AddActuator("Collector", "Left Roller", (Talon*) collectorLeftRoller);
	
	collectorRightRoller = new Talon(1, 3);
	lw->AddActuator("Collector", "Right Roller", (Talon*) collectorRightRoller);
	
	collectorAngleAdjuster = new SmartCANJaguar(6);
	
	
	shifterDoubleSolenoid = new DoubleSolenoid(1, 2, 3);      
	
	
	airCompressorCompressor = new Compressor(1, 1, 1, 1);
	
	
	robotRangeFinderUltrasonicSensor = new StallableAnalogEncoder(1, 4);
	lw->AddSensor("RobotRangeFinder", "UltrasonicSensor", robotRangeFinderUltrasonicSensor);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrainGyro->SetGyroMode(SmartGyro::radians);
	// don't have hardware
	launcherLowPressureSwitch = new AnalogPressureTransducer(1, 3);
	bling = new SPI(new DigitalOutput(1,3), new DigitalOutput(1,2));
}

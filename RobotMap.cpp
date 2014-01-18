/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SmartCANJaguar* RobotMap::driveTrainRightBack = NULL;
SmartCANJaguar* RobotMap::driveTrainLeftBack = NULL;
SmartCANJaguar* RobotMap::driveTrainRightFront = NULL;
SmartCANJaguar* RobotMap::driveTrainLeftFront = NULL;
SmartGyro* RobotMap::driveTrainGyro = NULL;
DoubleSolenoid* RobotMap::launcherDoubleSolenoid = NULL;
DoubleSolenoid* RobotMap::shifterDoubleSolenoid = NULL;
Compressor* RobotMap::airCompressorCompressor = NULL;
DigitalInput* RobotMap::airCompressorLowPressureSwitch = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
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
	launcherDoubleSolenoid = new DoubleSolenoid(1, 3, 4);      
	
	
	shifterDoubleSolenoid = new DoubleSolenoid(1, 1, 2);      
	
	
	airCompressorCompressor = new Compressor(1, 1, 1, 1);
	
	
	airCompressorLowPressureSwitch = new DigitalInput(1, 2);
	lw->AddSensor("AirCompressor", "LowPressureSwitch", airCompressorLowPressureSwitch);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrainGyro->SetGyroMode(SmartGyro::radians);
}

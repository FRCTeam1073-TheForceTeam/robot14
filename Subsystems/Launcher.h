/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef LAUNCHER_H
#define LAUNCHER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class Launcher: public Subsystem {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Compressor* compressor;
	Solenoid* solenoidLeft;
	Solenoid* solenoidRight;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	AnalogPressureTransducer* pressureTransducer;
	Launcher();
	void InitDefaultCommand();
	void OpenTank();
	void CloseTank();
	bool IsBadPressure();
	bool AreTanksOpen();
	bool isCompressorReady;
	bool isLaucherReady;
	void canCompress();
	void autoStopLauch();
	bool isTransducerReady();
	void Compress();
	//BEGIN DEBUG CODE
	//void Launch();
	//END DEBUG CODE
private:
	static int pressureLimit;
	int willCompress;
};
#endif

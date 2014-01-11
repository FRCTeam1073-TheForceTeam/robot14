/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Shifter.h"
#include "../Robotmap.h"
#include "../Commands/Compress.h"

#define high DoubleSolenoid::kForward
#define off DoubleSolenoid::kOff
#define low DoubleSolenoid::kReverse

Shifter::Shifter() : Subsystem("Shifter") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressor = RobotMap::shifterCompressor;
	pressureSwitch = RobotMap::shifterPressureSwitch;
	doubleSolenoid = RobotMap::shifterDoubleSolenoid;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    lowGear = false;
}
    
void Shifter::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Compress());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Shifter::StartCompressing() {
	compressor->Set(Relay::kForward);
}

void Shifter::StopCompressing() {
	compressor->Set(Relay::kOff);
}

bool Shifter::IsCompressed() {
	// Let WPILibExtensions handle the pull up resistor logic
	return LimitPressed(pressureSwitch);
}

void Shifter::SwitchGears() {
	if(lowGear) {
		doubleSolenoid->Set(high);
	}
	else {
		doubleSolenoid->Set(low);
	}
	lowGear = !lowGear;
}

bool Shifter::IsLowGear() {
	return lowGear;
}
/* FIRST Team 1073's RobaotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Shifter.h"
#include "../Robotmap.h"
#define high DoubleSolenoid::kForward
#define off DoubleSolenoid::kOff
#define low DoubleSolenoid::kReverse
Shifter::Shifter() : Subsystem("Shifter") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	doubleSolenoid = RobotMap::shifterDoubleSolenoid;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    lowGear = false;
}
    
void Shifter::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Shifter::SetLowGear() { Set(true); }
void Shifter::SetHighGear() { Set(false); }
void Shifter::Set(bool lowGear) {
	this->lowGear = lowGear;
	doubleSolenoid->Set(lowGear ? high : low);
	printf("Your current gear is");
	puts(lowGear ? "low" : "high");
}
bool Shifter::IsLowGear() {
	return lowGear;
}

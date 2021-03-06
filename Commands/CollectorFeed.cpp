/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "CollectorFeed.h"
CollectorFeed::CollectorFeed() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::collector);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void CollectorFeed::Initialize() {Robot::collector->Collect(true);}
void CollectorFeed::Execute() {}
bool CollectorFeed::IsFinished() {return false;}
void CollectorFeed::End() {
	Robot::collector->StopRollers();
}
void CollectorFeed::Interrupted() {End();}

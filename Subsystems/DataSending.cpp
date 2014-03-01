/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "DataSending.h"
#include "../Robotmap.h"
#include "../Robot.h"
#define INCHES_CONSTANT (1024.0/5.0*2.54)
#define AMPS_CONSTANT (71.43)
#define PSI_CONSTANT (22.22222)
#define ENCODER_CONSTANT (6.2857)
DataSending::DataSending() : Subsystem("DataSending") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	batteryCurrent = RobotMap::dataSendingBatteryCurrent;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	count=0;
	t2=t1=t3=1;
	RobotMap::driveTrainLeftFront->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	RobotMap::driveTrainLeftFront->ConfigEncoderCodesPerRev(1000);
	RobotMap::driveTrainLeftBack->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	RobotMap::driveTrainLeftBack->ConfigEncoderCodesPerRev(1000);
	RobotMap::driveTrainRightFront->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	RobotMap::driveTrainRightFront->ConfigEncoderCodesPerRev(1000);
	RobotMap::driveTrainRightBack->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	RobotMap::driveTrainRightBack->ConfigEncoderCodesPerRev(1000);
	InitializeBackGroundTask();//wake the zombie
}
void DataSending::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	//printf("You are now sending data\n");
}
void DataSending::SendTheData(){
	t1 = Timer::GetFPGATimestamp();//start the timer!
	downTime=t1-t2;
	strIndex = 0;
	Dashboard &dash = DriverStation::GetInstance()->GetHighPriorityDashboardPacker();
	DriverStation *drive = DriverStation::GetInstance();
	Send(drive->GetBatteryVoltage());//battery info
	Send((batteryCurrent->GetVoltage()-2.5)*AMPS_CONSTANT);
	GetJoystickInfo();//joystick info
	GetJagInfo();//jaguar info
	Send((bool)RobotMap::launcherSolenoidLeft->Get());//solenoid info
	Send((bool)RobotMap::launcherSolenoidRight->Get());
	Send(RobotMap::shifterDoubleSolenoid->Get());
	Send((bool)RobotMap::launcherCompressor->GetPressureSwitchValue());//sensor info
	Send(RobotMap::robotRangeFinderUltrasonicSensor->GetVoltage()*INCHES_CONSTANT);
	Send(RobotMap::driveTrainGyro->GetAngle());
	Send(RobotMap::elevatorElevationEncoder->GetVoltage());
	Send(RobotMap::launcherPressureSwitch->GetVoltage()*PSI_CONSTANT);//transducer1
	Send(RobotMap::collectorLeftRoller->Get()*-1);//talon info
	Send(RobotMap::collectorRightRoller->Get());
	Send(count++);//number of packets
	t2=Timer::GetFPGATimestamp();//how long did that take?
	totalExeucted=t2-t1;
	percentCPU=totalExeucted/downTime;
	Send(totalExeucted,4);
	Send(downTime,4);
	Send(percentCPU,4);
	Send(drive->GetMatchTime());
	dash.AddString(strBuffer);
	dash.Finalize();
	UpdateUserLCD();
}
void DataSending::Send(double f, int digits)
{
	char buff[20];
	int len = sprintf(buff, "%.*f,", digits, f);
	if(strIndex+len < MaxBuffer){
		strcpy(strBuffer+strIndex, buff);
		strIndex += len;
	}
}
void DataSending::Send(bool b)
{
	int len = 2;
	if(strIndex+len < MaxBuffer){
		if(b)	strcpy(strBuffer+strIndex, "1,");
		else	strcpy(strBuffer+strIndex, "0,");
		strIndex += len;
	}
}
void DataSending::Send(int i)
{
	char buff[20];
	int len = sprintf(buff, "%d,", i);
	if(strIndex+len < MaxBuffer){
		strcpy(strBuffer+strIndex, buff);
		strIndex += len;
	}
}
void DataSending::Send(char *s)
{
	char buff[81];
	int len = sprintf(buff, "%s,", s);
	if(strIndex+len < MaxBuffer){
		strcpy(strBuffer+strIndex, buff);
		strIndex += len;
	}
}
void DataSending::UpdateUserLCD(){
	char line1[200];
	char line2[200];
	char line3[200];
	char line4[200];
	char line5[200];
	string setting = "Shifter is "+GetGearSetting();
	string driveMode = "Drive mode Mecanum";//+Robot::driveTrain->GetDriveMode();
	strcpy(line1,setting.c_str());
	strcpy(line2,driveMode.c_str());
	if((bool)RobotMap::launcherCompressor->GetPressureSwitchValue())sprintf(line3,"Sufficent Pressure");
	else sprintf(line3,"Insufficient Pressure");
	sprintf(line4,"Elevation voltage is %f",RobotMap::elevatorElevationEncoder->GetVoltage());
	sprintf(line5, "Battery Current is %f Amps",((batteryCurrent->GetVoltage()-2.5)*AMPS_CONSTANT));
	DriverStationLCD *lcd = DriverStationLCD::GetInstance();
	lcd->PrintfLine(DriverStationLCD::kUser_Line1, "%s",line1);
	lcd->PrintfLine(DriverStationLCD::kUser_Line2, "%s",line2);
	lcd->PrintfLine(DriverStationLCD::kUser_Line3, "%s",line3);
	lcd->PrintfLine(DriverStationLCD::kUser_Line4, "%s",line4);
	lcd->PrintfLine(DriverStationLCD::kUser_Line5, "%s",line5);
	lcd->UpdateLCD();
}
void DataSending::GetJagInfo(){
	Send(RobotMap::driveTrainLeftFront->Get());
	Send(RobotMap::driveTrainLeftFront->GetOutputVoltage());
	Send(RobotMap::driveTrainLeftFront->GetOutputCurrent());
	Send(RobotMap::driveTrainLeftFront->GetPosition()*ENCODER_CONSTANT);
	Send(RobotMap::driveTrainLeftFront->GetBusVoltage());
	Send(RobotMap::driveTrainLeftFront->GetTemperature());
	Send((int)RobotMap::driveTrainLeftFront->GetFaults());
	
	Send(RobotMap::driveTrainRightFront->Get());
	Send(RobotMap::driveTrainRightFront->GetOutputVoltage());
	Send(RobotMap::driveTrainRightFront->GetOutputCurrent());
	Send(RobotMap::driveTrainRightFront->GetPosition()*ENCODER_CONSTANT);
	Send(RobotMap::driveTrainRightFront->GetBusVoltage());
	Send(RobotMap::driveTrainRightFront->GetTemperature());
	Send((int)RobotMap::driveTrainRightFront->GetFaults());
	
	Send(RobotMap::driveTrainLeftBack->Get());
	Send(RobotMap::driveTrainLeftBack->GetOutputVoltage());
	Send(RobotMap::driveTrainLeftBack->GetOutputCurrent());
	Send(RobotMap::driveTrainLeftBack->GetPosition()*ENCODER_CONSTANT);
	Send(RobotMap::driveTrainLeftBack->GetBusVoltage());
	Send(RobotMap::driveTrainLeftBack->GetTemperature());
	Send((int)RobotMap::driveTrainLeftBack->GetFaults());
	
	Send(RobotMap::driveTrainRightBack->Get());
	Send(RobotMap::driveTrainRightBack->GetOutputVoltage());
	Send(RobotMap::driveTrainRightBack->GetOutputCurrent());
	Send(RobotMap::driveTrainRightBack->GetPosition()*ENCODER_CONSTANT);
	Send(RobotMap::driveTrainRightBack->GetBusVoltage());
	Send(RobotMap::driveTrainRightBack->GetTemperature());
	Send((int)RobotMap::driveTrainRightBack->GetFaults());
	
	Send(RobotMap::elevatorAngleAdjuster->Get());
	Send(RobotMap::elevatorAngleAdjuster->GetOutputVoltage());
	Send(RobotMap::elevatorAngleAdjuster->GetOutputCurrent());
	Send(RobotMap::elevatorAngleAdjuster->GetBusVoltage());
	Send(RobotMap::elevatorAngleAdjuster->GetTemperature());
	Send(RobotMap::elevatorAngleAdjuster->GetForwardLimitOK());
	Send(RobotMap::elevatorAngleAdjuster->GetReverseLimitOK());
	Send((int)RobotMap::elevatorAngleAdjuster->GetFaults());
}
void DataSending::GetJoystickInfo(){
	Send(Robot::oi->getDriveStick()->GetX());
	Send(Robot::oi->getDriveStick()->GetY());
	Send(Robot::oi->getDriveStick()->GetZ());
	Send(Robot::oi->getOperatorStick()->GetX());
	Send(Robot::oi->getOperatorStick()->GetY());
}
const float periodicIntervalSec = .05f;
int
BackroundFunction(...)
{
	Wait(1.0);  //wait a second to make sure everything is ready
	while (1)  // No stopping the Zombie, Life before Autonomous....
	{
		Wait(periodicIntervalSec);		// Wait 50ms for a 20Hz update rate...
		Robot::dataSending->SendTheData();
	}
}
SEM_ID BackgroundSemaphore = 0;
Task *BackgroundTask;
void
DataSending::InitializeBackGroundTask()
{
	printf("Initiation ocurred\n");
	BackgroundTask = new Task("BackGroundTask", BackroundFunction );
	BackgroundSemaphore = semMCreate(SEM_DELETE_SAFE | SEM_INVERSION_SAFE); // synchronize access to multi-value registers
	BackgroundTask->Start();
	printf("This robot is currently being monitered\n");
}
string DataSending::GetGearSetting(){
	if(RobotMap::shifterDoubleSolenoid->Get()==DoubleSolenoid::kForward){
		return "low";
	}
	if(RobotMap::shifterDoubleSolenoid->Get()==DoubleSolenoid::kReverse){
		return "high";
	}
	if(RobotMap::shifterDoubleSolenoid->Get()==DoubleSolenoid::kOff){
		return "off";
	}
	return 0;
}

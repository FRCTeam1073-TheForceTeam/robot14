/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Bling.h"
#include "../Robotmap.h"
#include "../Robot.h"
#include "../Arduino.h"
const int NumPixels = 64;
Bling::Bling() : Subsystem("Bling") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	blong = RobotMap::bling;
	RBE_R = 128;
	RBE_G = 128;
	RBE_B = 128;
	blong->SetSampleDataOnFalling();
	blong->SetBitsPerWord(8);
	blong->SetMSBFirst();
	blong->SetClockActiveLow();
	blong->ApplyConfig();
	pattern = OFF;
	wasBlinking = false;
	Bling::InitializeBackgroundTask();
	
}
void Bling::SetPattern(PATTERN pattern){
	this->pattern = pattern;
}
void Bling::Execute()
{
	ClearStrip();
	switch (pattern){
	case OFF:
		break;
	case BLUE_SOLID:
		SetColor(0,0,127);
		break;
	case BLUE_BLINKING:
		Blink(0,0,127);
		break;
	case GREEN_SOLID:
		SetColor(0,127,0);
		break;
	case GREEN_BLINKING:
		Blink(0,127,0);
		break;
	case RAINBOW_EXPLOSION:
		RainbowExplosion();
		break;
	case RED_BLINKING:
		Blink(127,0,0);
		break;
	case PURPLE_SOLID:
		SetColor(127,0,127);
		break;
	case PURPLE_BLINKING:
		Blink(127,0,127);
		break;
	default:
		printf("ERROR: in Bling.cpp execute switch\n");
	}
}
const float blingNice = 0.5f;
int BlingBgFunction(...)
{
	Wait(1.0);  //wait a second to make sure everything is ready
	while (1)  // No stopping the Zombie, Life before Autonomous....
	{
		Wait(blingNice);
		Robot::bling->Execute();
	}
}
SEM_ID BlingSemaphore = 0;
static Task* BlingTask;	
void Bling::InitializeBackgroundTask() {
	printf("Bling background task initialized\n");
	BlingTask = new Task("BlingTask", BlingBgFunction, 150); // lowered from default of 101
	BlingSemaphore = semMCreate(SEM_DELETE_SAFE | SEM_INVERSION_SAFE); // synchronize access to multi-value registers
	BlingTask->Start();
	printf("Bling Flame On!\n");
}
void Bling::DispClear()
{
	DispColor(0, 0, 0);
}
void Bling::DispColor(int r, int g, int b)
{
	if (r < 128 && g < 128 && b < 128)
	{
		blong->Write(128+g);
		blong->Write(128+r);
		blong->Write(128+b);
		// printf("called SPI write %d %d %d\n",128+R,128+G,128+B);
	}
	
}
// Found to be necessary to get some algorithms to work.
void Bling::SetStrip(){
	blong->Write(0);
}
void Bling::RainbowExplosion(){
  for(int i = 0; i<33; i++){
    ClearStrip();
    LightNth(64 -i, 0, 127, 0);
    LightNth(i, 127, 0, 0);
    delay(50);
  }
  for (int i=0; i<=24; i++) {
    DispClear();
  }
  delay(20);
  for (int i=0; i<=14; i++) {
    DispColor(127, 127, 127);
  }
  delay(20);
  for(int i=0;i<=33;i++){ 
    for(int j=0;j<=32-i;j++){
      DispClear();
    }
    delay(20);
    for(int k=0;k<i;k++){
      RainbowColor((i -k)*11);
      DispColor(RBE_R, RBE_G, RBE_B);
    }
    delay(20);
    for(int l=0;l<i;l++){
      RainbowColor((i + l)*3);
      DispColor(RBE_R, RBE_G, RBE_B);
    }
    delay(20);
  ClearStrip();
  }
  delay(20);
}
void Bling::RainbowColor(int pos) {
	  //pos is the position on the Rainbow
	  //There are 384 colors
	  switch(pos / 128) {
	    case 0:
	      RBE_R = 127 - (pos%128);
	      RBE_G = pos%128;
	      RBE_B = 0;
	      break;
	    case 1:
	      RBE_G = 127 - (pos%128);
	      RBE_B = pos%128;
	      RBE_R = 0;
	      break;
	    case 2:
	      RBE_B = 127 - (pos%128);
	      RBE_R = pos%128;
	      RBE_G = 0;
	      break;
	  }
	}
void Bling::LightNth(int n, int r, int g, int b) {
  if (n > num_pixels) {
    return;
  }
  for(int i=0; i<=n-1; i++) {
    DispClear();
    //DispColor(0,127,127);
  }
  DispColor(r, g, b);
  
  SetStrip();
}
void Bling::ClearStrip() {
  for(int i=0; i<=num_pixels; i++) {
    DispClear();
  }
  SetStrip();
}
void Bling::Blink(int r, int g, int b, int interval){
	if (wasBlinking) {
		ClearStrip();
	}
	else {
		SetColor(r,g,b);
	}
	delay(interval); // might want to change
	wasBlinking = !wasBlinking;
}
void Bling::SetColor(int r, int g, int b){
  for(int i = 0; i < num_pixels; i++){
    DispColor(r, g, b);
  }
}

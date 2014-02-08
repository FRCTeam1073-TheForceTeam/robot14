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
	blong->SetSampleDataOnFalling();
	blong->SetBitsPerWord(8);
	blong->SetMSBFirst();
	blong->SetClockActiveLow();
	blong->ApplyConfig();
	forCounter = 0;
	iCounter = 0;
	code = RAINBOWEXPLOSION;
	Bling::InitializeBackgroundTask();
}
    
void Bling::InitDefaultCommand() {
}
void Bling::SetColor(BlingColor colorCode){
	code = colorCode;	
}
void Bling::RainbowExplosion()
{
	printf("This be getting da call\n");
	if (forCounter == 0)
	{
		puts("for counter is 0");
	    ClearStrip();
	    LightNth(NumPixels - iCounter, 0, 127, 0);
	    LightNth(iCounter, 127, 0, 0);
	    iCounter++;
	    if (iCounter == NumPixels / 2)
	    {
	    	iCounter = 0;
	    	
	    }
	    forCounter = 1;
	}
	else if (forCounter == 1)
	{
		printf("forCounter = 1\n");
		 for (int i=0; i<=24; i++) {
		    PixelOff();
		  }
		  for (int i=0; i<=14; i++) {
		    PixelColor(127, 127, 127);
		  }
		  forCounter=2;
		  
	}
	else if(forCounter == 2){	
		int R, G, B;
		
	printf("forCounter = 2\n");
	    for(int j=0;j<=32-iCounter;j++){
	      PixelOff();
	    }
	    for(int k=0;k<iCounter;k++){
	      RainbowColor((iCounter - k)*11,&R,&G,&B);
	      PixelColor(R, G, B);
	    }
	    for(int l=0;l<iCounter;l++){
	      RainbowColor((iCounter + l)*3,&R, &G, &B);
	      PixelColor(R, G, B);
	      
	    }
	    iCounter++;
	    if (iCounter == NumPixels / 2){
	    	
	   	    
	   	    	iCounter = 0;
	   	    	
	    }
	    forCounter = 3;
	}
	else if(forCounter == 3){
		printf("This works");
		ClearStrip();
		forCounter = 4;
	}
	else if(forCounter == 4){
		iCounter++;
		if (iCounter == 25){
			    	
			   	    iCounter = 0;
			   	   
		}
		 forCounter = 0;
	
	}
}
	
void Bling::Execute()
{
	//printf(".\n");
	switch (code){
	case RAINBOWEXPLOSION:
		//RainbowExplosion();
		ClearStrip();
		TurnMeOn();
		//printf("THis be executing hard\n");
		break;
	default:
		printf("ERROR: in BLing.cpp execute switch");
	}
}
const float blingNice = 0.001f;
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
	BlingTask = new Task("BlingTask", BlingBgFunction);
	BlingSemaphore = semMCreate(SEM_DELETE_SAFE | SEM_INVERSION_SAFE); // synchronize access to multi-value registers
	BlingTask->Start();
	printf("Bling Flame On!\n");
}
void Bling::LightNth(int ledNumber, int red, int green, int blue)
{
	for (int i = 0; i < ledNumber - 1; i++)
	{
		PixelOff();
	}
	PixelColor(red,green,blue);
}
void Bling::PixelOff()
{
	blong->Write(128);
	blong->Write(128);
	blong->Write(128);
}
void Bling::PixelColor(int R, int G, int B)
{
	if (R < 128 && G < 128 && B < 128)
	{
		blong->Write(128+G);
		blong->Write(128+R);
		blong->Write(128+B);
		// printf("called SPI write %d %d %d\n",128+R,128+G,128+B);
	}
	
}
void Bling::ClearStrip()
{
	for (int i = 0; i < NumPixels; i++)
	{
		PixelOff();
	}
	blong->Write(0);
		
}
void Bling::RainbowColor(int pos, int* R, int* G, int* B) {
  //pos is the position on the rainbow
  //There are 384 colors
  switch(pos / 128) {
    case 0:
      *R = 127 - (pos%128);
      *G = pos%128;
      *B = 0;
      break;
    case 1:
      *G = 127 - (pos%128);
      *B = pos%128;
      *R = 0;
      break;
    case 2:
      *B = 127 - (pos%128);
      *R = pos%128;
      *G = 0;
      break;
  }
}
void Bling::TurnMeOn(){
	puts("in turn me on");
	const int val = 0xF3 - 128;
	for (int i = 0; i < 2; i++)
		PixelColor(val,0,0);
	Wait(.005);
	
}

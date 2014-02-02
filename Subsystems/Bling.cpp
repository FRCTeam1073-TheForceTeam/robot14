/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#include "Bling.h"
#include "../Robotmap.h"
<<<<<<< HEAD
Bling::Bling() : Subsystem("Bling") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
=======
#include "../Commands/BlingLooper.h"

const int NumPixels = 64;

Bling::Bling() : Subsystem("Bling") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	blong = RobotMap::bling;
	blong->SetBitsPerWord(8);
	blong->SetMSBFirst();
	blong->ApplyConfig();
	forCounter = 0;
	iCounter = 0;
	code = RAINBOWEXPLOSION;
>>>>>>> ba6c2689cfed43166c6b33e70b8ef43da936d342
}
    
void Bling::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
<<<<<<< HEAD
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
=======
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new BlingLooper());
>>>>>>> ba6c2689cfed43166c6b33e70b8ef43da936d342
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
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
		TurnMeOn();
		//printf("THis be executing hard\n");
		break;
	default:
		printf("ERROR: in BLing.cpp execute switch");
	}
			
	
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
		printf("called SPI write %d %d %d\n",128+R,128+G,128+B);
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
		PixelColor(127,127,127);
	
}



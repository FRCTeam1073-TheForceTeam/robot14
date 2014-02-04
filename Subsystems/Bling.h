/* FIRST Team 1073's RobotBuilder (0.0.2) for WPILibExtensions ---
Do not mix this code with any other version of RobotBuilder! */
#ifndef BLING_H
#define BLING_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class Bling: public Subsystem {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Bling();
	void InitDefaultCommand();
	typedef enum Color
	{
		RAINBOWEXPLOSION,
		GREEN,
		ORANGE,
		RED
	} BlingColor;
	void SetColor(BlingColor colorCode);
	void Execute();
private:
	SPI* blong;
	void RainbowExplosion();
	BlingColor code;
	int forCounter;
	int iCounter;
	void LightNth(int ledNumber, int red, int green, int blue);
	void PixelOff();
	void ClearStrip();
	void PixelColor(int R, int G, int B);
	void RainbowColor(int pos, int* R, int* G, int* B);
	void TurnMeOn();
};
#endif

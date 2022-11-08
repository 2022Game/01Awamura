#pragma once
#include "CCharacter.h"

#define UE "0193_6.png" //è„
#define SHITA "0193_7.png" //â∫
#define MIGI "0193_9.png" //âE
#define HIDARI "0193_8.png" //ç∂
#define TEXTURE1 "image.png"

class CYZ 
{
public:
	CYZ();
	void Update();
	static int Now1();
	static int Now2();
	static int Now3();
	static int sNow1;
	static int sNow2;
	static int sNow3;
private:	
	int mInvincible2;
};
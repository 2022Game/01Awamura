#pragma once
#include "CCharacter.h"
#include "stdlib.h"

#define UE "0193_6.png" //��
#define SHITA "0193_7.png" //��
#define MIGI "0193_9.png" //�E
#define HIDARI "0193_8.png" //��
#define TEXTURE1 "image.png"
//#define RAND_MAX 

class CYZ 
{
public:
	//int rand(void);
	//void srand(unsigned int seed);
	CYZ();
	void Update();
	static int Now1();
	static int Now2();
	static int Now3();
	static int sNow1;
	static int sNow2;
	static int sNow3;
	static void Now1(int now1);
	static void Now2(int now1);
	static void Now3(int now1);
	static int ue;
	static int si;
	static int hi;
	static int mi;
	static int ue1;
	static int si1;
	static int hi1;
	static int mi1;
	static int RRR;
private:	
	CFont mFont;
};
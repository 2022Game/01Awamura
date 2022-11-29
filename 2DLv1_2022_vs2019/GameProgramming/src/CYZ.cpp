#include "CApplication.h"
#include "CGame.h"
#include "CApplication.h"
#include "CBlock.h"
#include "CPlayer2.h"
#include "CEnemy2.h"
#include "CPoint.h"
#include "CCamera.h"
#include "main.h"
#include "CYue.h"
#include "CYshita.h"
#include "CYmigi.h"
#include "CYhidari.h"
#include "CZkau.h"
#include "CZkas.h"
#include "CBlock1.h"
#include "CBlock2.h"
#include "CYZ.h"
#include "stdlib.h"
#include "stdio.h"
#include "CUi.h"
#include "time.h"

#define NOW1 0
#define NOW2 0
#define NOW3 0

int CYZ::sNow1 = 0;

void CYZ::Now1(int now1)
{
	sNow1 = now1;
}

void CYZ::Now2(int now1)
{
	sNow2 = now1;
}

void CYZ::Now3(int now1)
{
	sNow3 = now1;
}

int CYZ::Now1()
{
	return sNow1;
}

int CYZ::sNow2 = 0;

int CYZ::Now2()
{
	return sNow2;
}

int CYZ::sNow3 = 0;

int CYZ::Now3()
{
	return sNow3;
}

int CYZ::ue = 0;
int CYZ::ue1 = 0;
int CYZ::ue2 = 0;
int CYZ::si = 0;
int CYZ::si1 = 0;
int CYZ::si2 = 0;
int CYZ::hi = 0;
int CYZ::hi1 = 0;
int CYZ::hi2 = 0;
int CYZ::mi = 0;
int CYZ::mi1 = 0;
int CYZ::mi2 = 0;
int CYZ::RRR = 0;


//int CYZ::rand(void)
//{
//	return RAND_MAX;
//}
//
//void CYZ::srand(unsigned int seed)
//{
//}

CYZ::CYZ()
{
	CApplication::Texture6()->Load(MU);
	CApplication::Texture4()->Load(MIGI);
	CApplication::Texture2()->Load(UE);
	CApplication::Texture3()->Load(SHITA);
	CApplication::Texture5()->Load(HIDARI);
	CApplication::Texture()->Load(TEXTURE1);
	mFont.Load("FontWhite.png", 1, 64);
	srand((unsigned int)time(NULL));
}

//ã‰º‚Ì·‚Í‚R‚Q
void CYZ::Update(void)
{
	if(CZkabe::sNow != sNow2)
	{
		sNow2 = CZkabe::sNow;
		if (sNow3 != sNow2)
		{
			sNow1++;
		}
	}
	//‚‚³‚W‚O`‚T‚Q‚W
	//•
	//migi753.0f
	//hida47.0f
	//shita‚S‚W

	if (sNow1 == 0)
	{
		mFont.Draw(275, 300, 18, 36, "GO!");
		if (sNow3 == sNow2)
		{
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = 10000;
		}
	}
	if (sNow1 == 1)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
			//sNow1 = 59;
		}
	}
	if (sNow1 == 2)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
	}
		}
	if (sNow1 == 3)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 4)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 5)
	{
		mFont.Draw(275, 300, 18, 36, "SPEED UP");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 6)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 7)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 8)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 9)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 10)
	{
		mFont.Draw(275, 300, 18, 36, "SPEED UP");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 11)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 12)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 13)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 14)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 15)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 16)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 17)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 18)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 19)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 20)
	{
		mFont.Draw(275, 300, 18, 36, "SPEED UP");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 21)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 22)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 23)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 24)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 25)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 26)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 27)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 28)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 29)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 30)
	{
		mFont.Draw(275, 300, 18, 36, "SPEED UP");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 31)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 32)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 33)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 34)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 35)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 36)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 37)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 38)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 39)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 40)
	{
		mFont.Draw(275, 300, 18, 36, "SPEED UP");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 41)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 42)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 43)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 44)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 45)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 46)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 47)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 48)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 49)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 50)
	{
		mFont.Draw(250, 300, 18, 36, "SPEED MAX");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 51)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 52)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 53)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 54)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 55)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 56)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 57)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 58)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 59)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 60)
	{
		mFont.Draw(250, 300, 18, 36, "S M A L L");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 61)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 62)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 63)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 64)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 65)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 66)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 67)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 68)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 69)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 70)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 71)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 72)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 73)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 74)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 75)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 76)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 77)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 78)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 79)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 80 + rand() % 642;
			si = 80 + rand() % 642;
			hi = 80 + rand() % 448;
			mi = 80 + rand() % 448;
			ue1 = 80 + rand() % 642;
			si1 = 80 + rand() % 642;
			hi1 = 80 + rand() % 448;
			mi1 = 80 + rand() % 448;
			ue2 = 80 + rand() % 642;
			si2 = 80 + rand() % 642;
			hi2 = 80 + rand() % 448;
			mi2 = 80 + rand() % 448;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 80)
	{
		mFont.Draw(250, 300, 18, 36, "B  I  G");
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 16.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 16.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 16.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 81)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 82)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 83)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 84)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 85)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 86)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 87)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 88)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 89)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 90)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			/*CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));*/
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 91)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			/*CApplication::CharacterManager()->Add(
				new CZkau(ue2, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si2, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi2, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi2, 600.0f, 32.0f,
					CApplication::Texture()));*/
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			/*CApplication::CharacterManager()->Add(
				new CYue(ue2, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si2, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi2, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi2, 16.0f, 16.0f,
					CApplication::Texture5()));*/
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 92)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 93)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 94)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 95)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 96)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 97)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 98)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			CApplication::CharacterManager()->Add(
				new CYue(ue, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYue(ue1, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(si1, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, hi1, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, mi1, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 99)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(ue, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(ue1, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(si1, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, hi1, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, mi1, 600.0f, 32.0f,
					CApplication::Texture()));
			ue = 96 + rand() % 608;
			si = 96 + rand() % 608;
			hi = 96 + rand() % 416;
			mi = 96 + rand() % 416;
			ue1 = 96 + rand() % 608;
			si1 = 96 + rand() % 608;
			hi1 = 96 + rand() % 416;
			mi1 = 96 + rand() % 416;
			ue2 = 96 + rand() % 608;
			si2 = 96 + rand() % 608;
			hi2 = 96 + rand() % 416;
			mi2 = 96 + rand() % 416;
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 100)
	{
		if (sNow3 != sNow2)
		{
		}
	}
}
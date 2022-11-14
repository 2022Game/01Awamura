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

CYZ::CYZ()
{
	CApplication::Texture4()->Load(MIGI);
	CApplication::Texture2()->Load(UE);
	CApplication::Texture3()->Load(SHITA);
	CApplication::Texture5()->Load(HIDARI);
	CApplication::Texture()->Load(TEXTURE1);
}

//ã‰º‚Ì·‚Í‚R‚Q
void CYZ::Update()
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
		if (sNow3 == sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 96.0f, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 512.0f, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = 10000;
		}
	}
	if (sNow1 == 1)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, 96.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, 512.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			//Y
			CApplication::CharacterManager()->Add(
				new CYshita(400.0f, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(400.0f, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 304.0f, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 304.0f, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 2)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, 298.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, 298.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(401.0f, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(401.0f, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			//mpZkas1 = new CZkas1(401.0f, -1300.0f, 16.9f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkas1);
			//mpZkas1 = new CZkas1(401.0f, -1300.0f, 16.9f, 300.0f, 0, 45, 68, 100, &mTexture);
	//mCharacterManager.Add(mpZkas1);
			CApplication::CharacterManager()->Add(
				new CYshita(400.0f, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(250.0f, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYue(550.0f, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			sNow3 = sNow2;
	}
		}
	if (sNow1 == 3)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkas(401.0f, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(550.0f, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(250.0f, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			//y
			CApplication::CharacterManager()->Add(
				new CYue(250.0f, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYshita(550.0f, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f,154.0f, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 454.0f, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 4)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkau(250.0f, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(500.0f, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, 138.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, 470.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CYshita(200.0f, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYshita(600.0f, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(400.0f, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 96.0f, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 512.0f, 16.0f, 16.0f,
					CApplication::Texture5()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 304.0f, 16.0f, 16.0f,
					CApplication::Texture4()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 5)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CZkas(600.0f, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkas(200.0f, -300.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkau(400.0f, 900.0f, 32.0f, 300.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkah(-600.0f, 304.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, 96.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			CApplication::CharacterManager()->Add(
				new CZkam(1395.0f, 512.0f, 600.0f, 32.0f,
					CApplication::Texture()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 6)
	{
		if (sNow3 != sNow2)
		{

		}
	}
}
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
	CApplication::Texture4()->Load(MIGI);
	CApplication::Texture2()->Load(UE);
	CApplication::Texture3()->Load(SHITA);
	CApplication::Texture5()->Load(HIDARI);
	CApplication::Texture()->Load(TEXTURE1);
	mFont.Load("FontWhite.png", 1, 64);
}

//ã‰º‚Ì·‚Í‚R‚Q
void CYZ::Update(void)
{
	srand((unsigned int)time(NULL));
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
				new CYshita(400, 48.0f, 16.0f, 16.0f,
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
		mFont.Draw(275, 300, 18, 36, "SPEED UP");
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
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 7)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 8)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 9)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
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
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 11)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 12)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 13)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 14)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 15)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 16)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 17)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 18)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 19)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
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
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 21)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 22)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 23)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 24)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 25)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 26)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 27)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 28)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 29)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
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
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 31)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 32)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 33)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 34)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 35)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 36)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 37)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 38)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 39)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
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
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 41)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 42)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 43)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 44)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 45)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 46)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 47)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 48)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 49)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
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
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 51)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 52)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 53)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 54)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 55)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 56)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 57)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 58)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 59)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 60)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 61)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 62)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 63)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 64)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 65)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 66)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 67)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 68)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 69)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 70)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 71)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 72)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 73)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 74)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 75)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 76)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 77)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 78)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 79)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 80)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 81)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 82)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 83)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 84)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 85)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 86)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 87)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 88)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 89)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 90)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 91)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 92)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 93)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 94)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 95)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 96)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 97)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 98)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 99)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
	if (sNow1 == 100)
	{
		if (sNow3 != sNow2)
		{
			CApplication::CharacterManager()->Add(
				new CYshita(81 + rand() % 641, 48.0f, 16.0f, 16.0f,
					CApplication::Texture2()));
			CApplication::CharacterManager()->Add(
				new CYue(81 + rand() % 641, 560.0f, 16.0f, 16.0f,
					CApplication::Texture3()));
			CApplication::CharacterManager()->Add(
				new CYhidari(47.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture4()));
			CApplication::CharacterManager()->Add(
				new CYmigi(753.0f, 80 + rand() % 448, 16.0f, 16.0f,
					CApplication::Texture5()));
			sNow3 = sNow2;
		}
	}
}
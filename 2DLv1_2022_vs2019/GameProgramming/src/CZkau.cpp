#include "CZkau.h"
#include "CApplication.h"

#define KABE  0.0f, 45.0f, 68.0f, 100.0f
#define SE_PA "res\\da1.wav"
#define SE_PA1 "res\\‘ÅŒ‚3.wav"
#define SE_PA2 "res\\‘åƒpƒ“ƒ`.wav"
#define SE_PA3 "res\\’†ƒpƒ“ƒ`.wav"
#define SE_PA4 "res\\‘å–C1.mp3"
#define SE_PA5 "res\\‘å–C2.mp3"

CZkau::CZkau(float x, float y, float w, float h,  CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt,KABE);
	mState = EState::EMOVE;
	mTag = ETag::EKABEY;
	mSound.Load(SE_PA1);
}

void CZkau::Update()
{
	float y;
	switch (mState)
	{
	case EState::EMOVE:
		if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 9)
		{
			y = Y() - 10;
			Y(y);
		}
		if (CYZ::sNow1 >= 10 && CYZ::sNow1 <= 19)
		{
			y = Y() - 12;
			Y(y);
		}
		if (CYZ::sNow1 >= 20 && CYZ::sNow1 <= 29)
		{
			y = Y() - 14;
			Y(y);
		}
		if (CYZ::sNow1 >= 30 && CYZ::sNow1 <= 39)
		{
			y = Y() - 16;
			Y(y);
		}
		if (CYZ::sNow1 >= 40 && CYZ::sNow1 <= 49)
		{
			y = Y() - 18;
			Y(y);
		}
		if (CYZ::sNow1 >= 50 && CYZ::sNow1 <= 99)
		{
			y = Y() - 20;
			Y(y);
		}
		break;
	case EState::EBACK:
		if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 4)
		{
			y = Y() + 8;
			Y(y);
		}
		if (CYZ::sNow1 >= 5 && CYZ::sNow1 <= 9)
		{
			y = Y() + 10;
			Y(y);
		}
		if (CYZ::sNow1 >= 10 && CYZ::sNow1 <= 19)
		{
			y = Y() + 12;
			Y(y);
		}
		if (CYZ::sNow1 >= 20 && CYZ::sNow1 <= 29)
		{
			y = Y() + 14;
			Y(y);
		}
		if (CYZ::sNow1 >= 30 && CYZ::sNow1 <= 39)
		{
			y = Y() + 16;
			Y(y);
		}
		if (CYZ::sNow1 >= 40 && CYZ::sNow1 <= 49)
		{
			y = Y() + 18;
			Y(y);
		}
		if (CYZ::sNow1 >= 50 && CYZ::sNow1 <= 99)
		{
			y = Y() + 20;
			Y(y);
		}
		if (y > 900.0f)
		{
			mEnabled = false;
		}
	}
}

void CZkau::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CZkau::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCKKK:
		if (CRectangle::Collision(o, &x, &y))
		{
		//	X(X() + x);
			Y(Y() + y);
			mState = EState::EBACK;
			if (CYZ::sNow1 >= 51 && CYZ::sNow1 <= 99)
			{
				mSound.Play();
			}
		}
	}
}
#include "CZkah.h"
#include "CApplication.h"

#define KABE  0.0f, 45.0f, 68.0f, 100.0f
#define SE_PA "res\\da1.wav"
#define SE_PA1 "res\\‘ÅŒ‚3.wav"
#define SE_PA2 "res\\‘åƒpƒ“ƒ`.wav"
#define SE_PA3 "res\\’†ƒpƒ“ƒ`.wav"
#define SE_PA4 "res\\‘å–C1.mp3"
#define SE_PA5 "res\\‘å–C2.mp3"

CZkah::CZkah(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, KABE);
	mState = EState::EMOVE;
	mTag = ETag::EKABEX;
	mSound.Load(SE_PA1);
}

void CZkah::Update()
{
		float x;
		switch (mState)
		{
		case EState::EMOVE:
			if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 9)
			{
				x = X() + 20;
				X(x);
			}
			if (CYZ::sNow1 >= 10 && CYZ::sNow1 <= 19)
			{
				x = X() + 22;
				X(x);
			}
			if (CYZ::sNow1 >= 20 && CYZ::sNow1 <= 29)
			{
				x = X() + 24;
				X(x);
			}
			if (CYZ::sNow1 >= 30 && CYZ::sNow1 <= 39)
			{
				x = X() + 26;
				X(x);
			}
			if (CYZ::sNow1 >= 40 && CYZ::sNow1 <= 49)
			{
				x = X() + 28;
				X(x);
			}
			if (CYZ::sNow1 >= 50 && CYZ::sNow1 <= 99)
			{
				x = X() + 30;
				X(x);
			}
			break;
		case EState::EBACK:
			if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 4)
			{
				x = X() - 8;
				X(x);
			}
			if (CYZ::sNow1 >= 5 && CYZ::sNow1 <= 9)
			{
				x = X() - 10;
				X(x);
			}
			if (CYZ::sNow1 >= 10 && CYZ::sNow1 <= 19)
			{
				x = X() - 12;
				X(x);
			}
			if (CYZ::sNow1 >= 20 && CYZ::sNow1 <= 29)
			{
				x = X() - 14;
				X(x);
			}
			if (CYZ::sNow1 >= 30 && CYZ::sNow1 <= 39)
			{
				x = X() - 16;
				X(x);
			}
			if (CYZ::sNow1 >= 40 && CYZ::sNow1 <= 49)
			{
				x = X() - 18;
				X(x);
			}
			if (CYZ::sNow1 >= 50 && CYZ::sNow1 <= 99)
			{
				x = X() - 20;
				X(x);
			}
			if (x < -600.0f)
			{
				mEnabled = false;
			}
		}
}

void CZkah::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CZkah::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			//Y(Y() + y);
			mState = EState::EBACK;
			if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 10)
			{
				mSound.Play();
			}
		}
	}
}
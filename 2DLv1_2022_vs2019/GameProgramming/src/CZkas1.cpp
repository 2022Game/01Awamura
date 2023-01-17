#include "CZkas1.h"
#include "CApplication.h"

#define KABE  0.0f, 45.0f, 68.0f, 100.0f

CZkas1::CZkas1(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, KABE);
	mState = EState::EMOVE;
	mTag = ETag::EKABEY;
}

void CZkas1::Update()
{ 
	float y;
	switch (mState)
	{
	case EState::EMOVE:
		if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 9)
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
		break;
	case EState::EBACK:
		if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 4)
		{
			y = Y() - 8;
			Y(y);
		}
		if (CYZ::sNow1 >= 5 && CYZ::sNow1 <= 9)
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
		if (y < -300.0f)
		{
			mEnabled = false;
		}
	}
}

void CZkas1::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CZkas1::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			//X(X() + x);
			Y(Y() + y);
			mState = EState::EBACK;
		}
	}
}
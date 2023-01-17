#include "CZkabe.h"
#include "CApplication.h"
#include "CYZ.h"
#include "CUi.h"

#define NOW 0

int CZkabe::sNow = 0;

int CZkabe::Now()
{
	return sNow;
}

void CZkabe::Now(int now)
{
	sNow = now;
}

CZkabe::CZkabe(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, l, r, b, t);
	mState = EState::EBACK;
}

void CZkabe::Update()
{
	if (mState == EState::EBACK)
		{
		float x;
		if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 4)
		{ 
			x = X() - 4;
			X(x);
		}
		if (CYZ::sNow1 >= 5 && CYZ::sNow1 <= 9)
		{
			x = X() - 5;
			X(x);
		}
		if (CYZ::sNow1 >= 10 && CYZ::sNow1 <= 19)
		{
			x = X() - 6;
			X(x);
		}
		if (CYZ::sNow1 >= 20 && CYZ::sNow1 <= 29)
		{
			x = X() - 7;
			X(x);
		}
		if (CYZ::sNow1 >= 30 && CYZ::sNow1 <= 39)
		{
			x = X() - 8;
			X(x);
		}
		if (CYZ::sNow1 >= 40 && CYZ::sNow1 <= 49)
		{
		    x = X() - 9;
			X(x);
		}
		if (CYZ::sNow1 >= 50 && CYZ::sNow1 <= 99)
		{
			x = X() - 10;
			X(x);
		}
	if (x < -600.0f)
			{
				x = 200.0f;
				X(x);
			sNow++;
			}
		}
}

void CZkabe::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CZkabe::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK1:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			mState = EState::EBACK;
		}
	}
}
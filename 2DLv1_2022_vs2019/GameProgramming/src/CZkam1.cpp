#include "CZkam1.h"
#include "CApplication.h"

#define KABE  0.0f, 45.0f, 68.0f, 100.0f

CZkam1::CZkam1(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, KABE);
	mState = EState::EMOVE;
	mTag = ETag::EKABEX;
}

void CZkam1::Update()
{
	float x;
	switch (mState)
	{
	case EState::EMOVE:
		if (CYZ::sNow1 >= 0)
		{
			if (CYZ::sNow1 <= 9)
			{
				x = X() - 20;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 10)
		{
			if (CYZ::sNow1 <= 19)
			{
				x = X() - 22;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 20)
		{
			if (CYZ::sNow1 <= 29)
			{
				x = X() - 24;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 30)
		{
			if (CYZ::sNow1 <= 39)
			{
				x = X() - 26;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 40)
		{
			if (CYZ::sNow1 <= 49)
			{
				x = X() - 28;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 50)
		{
			if (CYZ::sNow1 <= 99)
			{
				x = X() - 30;
				X(x);
			}
		}
		break;
	case EState::EBACK:
		if (CYZ::sNow1 >= 0)
		{
			if (CYZ::sNow1 <= 4)
			{
				x = X() + 8;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 5)
		{
			if (CYZ::sNow1 <= 9)
			{
				x = X() + 10;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 10)
		{
			if (CYZ::sNow1 <= 19)
			{
				x = X() + 12;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 20)
		{
			if (CYZ::sNow1 <= 29)
			{
				x = X() + 14;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 30)
		{
			if (CYZ::sNow1 <= 39)
			{
				x = X() + 16;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 40)
		{
			if (CYZ::sNow1 <= 49)
			{
				x = X() + 18;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 50)
		{
			if (CYZ::sNow1 <= 99)
			{
				x = X() + 20;
				X(x);
			}
		}
		if (x > 1395.0f)
		{
			mEnabled = false;
		}
	}
}

void CZkam1::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CZkam1::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK1:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			//Y(Y() + y);
			mState = EState::EBACK;
		}
	}
}
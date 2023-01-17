#include "SUP.h"
#include "CApplication.h"

#define SSUP  0.0f, 1000.0f, 1000.0f, 0.0f

SUP::SUP(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, SSUP);
	mTag = ETag::EUP;
	mState = EState::EMOVE;
}

void SUP::Update()
{
	float x;
	switch(mState)
	{
	case EState::EMOVE:
		if (CYZ::sNow1 >= 0 && CYZ::sNow1 <= 4)
		{
			x = X() - 4.3;
			X(x);
			if (x < 0.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 5 && CYZ::sNow1 <= 9)
		{
			x = X() - 5.3;
			X(x);
			if (x < 0.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 10 && CYZ::sNow1 <= 19)
		{
			x = X() + 6.3;
			X(x);
			if (x > 815.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 20 && CYZ::sNow1 <= 29)
		{
			x = X() - 7.3;
			X(x);
			if (x < 0.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 30 && CYZ::sNow1 <= 39)
		{
			x = X() + 8.3;
			X(x);
			if (x > 815.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 40 && CYZ::sNow1 <= 49)
		{
			x = X() - 9.3;
			X(x);
			if (x < 0.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 50 && CYZ::sNow1 <= 59)
		{
			x = X() + 10.3;
			X(x);
			if (x > 815.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 60 && CYZ::sNow1 <= 69)
		{
			x = X() - 10.3;
			X(x);
			if (x < 0.0f)
			{
				mEnabled = false;
			}
		}
		if (CYZ::sNow1 >= 70 && CYZ::sNow1 <= 79)
		{
			x = X() + 10.3;
			X(x);
			if (x > 815.0f)
			{
				mEnabled = false;
			}
		}
	}
	if (CYZ::RRR > 0)
	{
		CYZ::RRR--;
	}
    if (CYZ::UP1 < 80 || CYZ::UP1 > 528)
	{
		mEnabled = false;
	}
}

void SUP::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void SUP::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EPLAYER:
		if (CRectangle::Collision(o, &x, &y))
		{
			if (CYZ::RRR == 0)
			{
				CYZ::RRR = 1;
				CYZ::SPEED++;
			}
			mEnabled = false;
		}
		break;
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			//mEnabled = false;
		}
		break;
	case ETag::EKABEX:
		if (CRectangle::Collision(o, &x, &y))
		{
			//mEnabled = false;
		}
		break;
	case ETag::EKABEY:
		if (CRectangle::Collision(o, &x, &y))
		{
			//mEnabled = false;
		}
		break;
	}
}
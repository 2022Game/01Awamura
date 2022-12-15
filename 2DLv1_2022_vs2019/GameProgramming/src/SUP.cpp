#include "SUP.h"
#include "CApplication.h"

#define SSUP  0.0f, 1000.0f, 1000.0f, 0.0f

SUP::SUP(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, SSUP);
	mTag = ETag::EUP;
}

void SUP::Update()
{
	if (CYZ::RRR > 0)
	{
		CYZ::RRR--;
	}
	if (CYZ::UP < 80)
	{
		mEnabled = false;
	}
	if (CYZ::UP > 722)
	{
		mEnabled = false;
	}
	if (CYZ::UP1 < 80)
	{
		mEnabled = false;
	}
	if (CYZ::UP1 > 528)
	{
		mEnabled = false;
	}
	//if (CZkabe::sNow != CYZ::sNow2)
	//{
	//	mEnabled = false;
	//}
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
			mEnabled = false;
		}
		break;
	case ETag::EKABEX:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EKABEY:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	}
}
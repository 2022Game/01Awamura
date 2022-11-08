#include "CZkau1.h"
#include "CApplication.h"

#define KABE  0.0f, 45.0f, 68.0f, 100.0f

CZkau1::CZkau1(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt,KABE);
	mState = EState::EMOVE;
	mTag = ETag::EKABE;
}

void CZkau1::Update()
{
	float y;
	switch (mState)
	{
	case EState::EMOVE:
		y = Y() - 20;
		Y(y);
		break;
	case EState::EBACK:
		y = Y() + 8;
		Y(y);
		if (y > 900.0f)
		{
			mEnabled = false;
		}
	}
}

void CZkau1::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CZkau1::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			mState = EState::EBACK;
		}
	}
}
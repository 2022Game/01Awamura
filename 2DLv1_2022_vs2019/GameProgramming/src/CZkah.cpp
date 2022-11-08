#include "CZkah.h"
#include "CApplication.h"

#define KABE  0.0f, 45.0f, 68.0f, 100.0f

CZkah::CZkah(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, KABE);
	mState = EState::EMOVE;
	mTag = ETag::EKABE;
}

void CZkah::Update()
{
		float x;
		switch (mState)
		{
		case EState::EMOVE:
			x = X() + 20;
			X(x);
			break;
		case EState::EBACK:
			x = X() - 8;
			X(x);
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
			Y(Y() + y);
			mState = EState::EBACK;
		}
	}
}
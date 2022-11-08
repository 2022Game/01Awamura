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
			float x = X() - 4;
			X(x);
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
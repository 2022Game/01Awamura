#include "CBlocks.h"
#include "CApplication.h"

#define TEXCOORD 192.0f, 208.0f, 16.5f, 0.0f //テクスチャ座標
//#define TEXCOORD 0.0f, 48.0f, 128.0f, 80.0f 

CBlocks::CBlocks(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, TEXCOORD);
	mTag = ETag::EBLOCKS;
	mState = EState::ER;
}

void CBlocks::Update()
{
	float x, y;
	switch (mState)
	{
	case EState::ER:
		if (CYZ::sNow1 >= 0)
		{
			if (CYZ::sNow1 <= 9)
			{
				x = X() + 1;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 10)
		{
			if (CYZ::sNow1 <= 19)
			{
				x = X() + 2;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 20)
		{
			if (CYZ::sNow1 <= 29)
			{
				x = X() + 3;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 30)
		{
			if (CYZ::sNow1 <= 39)
			{
				x = X() + 4;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 40)
		{
			if (CYZ::sNow1 <= 49)
			{
				x = X() + 5;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 50)
		{
			if (CYZ::sNow1 <= 99)
			{
				x = X() + 6;
				X(x);
			}
		}
		break;
	case EState::EU:
		if (CYZ::sNow1 >= 0)
		{
			if (CYZ::sNow1 <= 9)
			{
				y = Y() + 1;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 10)
		{
			if (CYZ::sNow1 <= 19)
			{
				y = Y() + 2;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 20)
		{
			if (CYZ::sNow1 <= 29)
			{
				y = Y() + 3;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 30)
		{
			if (CYZ::sNow1 <= 39)
			{
				y = Y() + 4;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 40)
		{
			if (CYZ::sNow1 <= 49)
			{
				y = Y() + 5;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 50)
		{
			if (CYZ::sNow1 <= 99)
			{
				y = Y() + 6;
				Y(y);
			}
		}
		break;
	case EState::EL:
		if (CYZ::sNow1 >= 0)
		{
			if (CYZ::sNow1 <= 9)
			{
				x = X() - 1;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 10)
		{
			if (CYZ::sNow1 <= 19)
			{
				x = X() - 2;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 20)
		{
			if (CYZ::sNow1 <= 29)
			{
				x = X() - 3;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 30)
		{
			if (CYZ::sNow1 <= 39)
			{
				x = X() - 4;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 40)
		{
			if (CYZ::sNow1 <= 49)
			{
				x = X() - 5;
				X(x);
			}
		}
		if (CYZ::sNow1 >= 50)
		{
			if (CYZ::sNow1 <= 99)
			{
				x = X() - 6;
				X(x);
			}
		}
		break;
	case EState::ED:
		if (CYZ::sNow1 >= 0)
		{
			if (CYZ::sNow1 <= 9)
			{
				y = Y() - 1;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 10)
		{
			if (CYZ::sNow1 <= 19)
			{
				y = Y() - 2;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 20)
		{
			if (CYZ::sNow1 <= 29)
			{
				y = Y() - 3;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 30)
		{
			if (CYZ::sNow1 <= 39)
			{
				y = Y() - 4;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 40)
		{
			if (CYZ::sNow1 <= 49)
			{
				y = Y() - 5;
				Y(y);
			}
		}
		if (CYZ::sNow1 >= 50)
		{
			if (CYZ::sNow1 <= 99)
			{
				y = Y() - 6;
				Y(y);
			}
		}
		break;
	}
}

void CBlocks::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CBlocks::Collision(CCharacter* m, CCharacter* o)
{
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK3:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			if (mState == EState::EL)
			{
				mState = EState::ED;
			}
			if (mState == EState::ER)
			{
				mState = EState::EU;
			}
		}
		break;
	case ETag::EBLOCK4:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			if (mState == EState::ED)
			{
				mState = EState::ER;
			}
			if (mState == EState::EU)
			{
				mState = EState::EL;
			}
		}
	}
}
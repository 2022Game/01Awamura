#include "CYmigi.h"
#include "CApplication.h"

#define MIGI 0.0f,200.0f, 175.0f, 0.0f //テクスチャ座標
#define MU 0.0,0.0,0.0,0.0

CYmigi::CYmigi(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, MIGI);
	mState = EState::ESTOP;
	mTag = ETag::EMIGI;
}

CYmigi::CYmigi()
{
	mState = EState::EMOVE;
	mTag = ETag::EMIGI;
}

void CYmigi::Update()
{
	if (mState == EState::ESTOP)
	{
		//Texture(Texture(), MU);
	}
	if (mState == EState::EMOVE)
	{
		Texture(Texture(), MIGI);
	}
	if (CZkabe::sNow != CYZ::sNow2)
	{
		mEnabled = false;
	}
};
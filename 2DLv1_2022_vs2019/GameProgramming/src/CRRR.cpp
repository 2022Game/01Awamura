#include "CRRR.h"
#include "CApplication.h"

#define MU 0.0,0.0,0.0,0.0

CRRR::CRRR(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, MU);
	mState = EState::ESTOP;
	mTag = ETag::ESHITA;
}

void CRRR::Update()
{
	if (mState == EState::ESTOP)
	{
		//Texture(Texture(), MU);
	}
	if (mState == EState::EMOVE)
	{
		Texture(Texture(), MU);
	}
	if (CZkabe::sNow != CYZ::sNow2)
	{
		mEnabled = false;
	}
};
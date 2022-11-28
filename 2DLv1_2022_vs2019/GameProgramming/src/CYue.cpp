#include "CYue.h"
#include "CApplication.h"
#include "stdlib.h"
#include "stdio.h"
#include "CUi.h"
#include "time.h"

#define UE 0.0f,175.0f, 190.0f, 0.0f //テクスチャ座標
#define MU 0.0,0.0,0.0,0.0

CYue::CYue(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, UE);
	mState = EState::ESTOP;
	mTag = ETag::EUE;
}

CYue::CYue()
{
	mState = EState::EMOVE;
	mTag = ETag::ESHITA;
}

void CYue::Update()
{
	if (mState == EState::ESTOP)
	{
		//Texture(Texture(), MU);
	}
	if (mState == EState::EMOVE)
	{
		Texture(Texture(),UE);
	}
	if (CZkabe::sNow != CYZ::sNow2)
	{
		mEnabled = false;
	}
};
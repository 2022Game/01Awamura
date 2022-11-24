#include "CYshita.h"
#include "CApplication.h"
#include "time.h"

#define SHITA 0.0f,175.0f, 200.0f, 0.0f //テクスチャ座標
#define MU 0.0,0.0,0.0,0.0

int CYshita::shita = 81 + rand() % 641;

CYshita::CYshita(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, SHITA);
	mState = EState::ESTOP;
	mTag = ETag::ESHITA;
}

CYshita::CYshita()
{
	mState = EState::EMOVE;
	mTag = ETag::ESHITA;
	srand((unsigned int)time(NULL));
}

void CYshita::Update()
{
	if (mState == EState::ESTOP)
	{
		//Texture(Texture(), MU);
	}
	if (mState == EState::EMOVE)
	{
		Texture(Texture(), SHITA);
	}
	if (CZkabe::sNow != CYZ::sNow2)
	{
		mEnabled = false;
	}
	if (CYZ::sNow3 != CYZ::sNow2)
	{
		shita = 81 + rand() % 641;
	}
};
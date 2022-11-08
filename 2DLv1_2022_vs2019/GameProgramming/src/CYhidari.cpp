#include "CYhidari.h"
#include "CApplication.h"

#define HIDARI 0.0f,200.0f, 175.0f, 0.0f //�e�N�X�`�����W
#define MU 0.0,0.0,0.0,0.0	//�e�N�X�`���}�b�s���O

CYhidari::CYhidari(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, HIDARI);
	mState = EState::ESTOP;
	mTag = ETag::EHIDARI;
}

CYhidari::CYhidari()
{
	mState = EState::EMOVE;
	mTag = ETag::EHIDARI;
}

void CYhidari::Update()
{
	if (mState == EState::ESTOP)
	{
			//Texture(Texture(), MU);
	}
	if (mState == EState::EMOVE)
	{
		Texture(Texture(), HIDARI);
	}
	if (CZkabe::sNow != CYZ::sNow2)
	{
		mEnabled = false;
	}
};
#include "CXPlayer.h"

#define ROTATION2_YV CVector(0.0f, 2.0f, 0.0f) //‰ñ“]‘¬“x
#define VELOCITY2 CVector(0.0f, 0.0f, 0.1f) //ˆÚ“®‘¬“x

CXPlayer::CXPlayer()
	:AttackFrame(0)
	, AnimaScene(0)
	,AnimaFrame(0)
{

}

void CXPlayer::Update()
{
	if (AttackFrame != 0)
	{
		AttackFrame--;
	}
	if (AnimaFrame != 0)
	{
		AnimaFrame--;
	}
	if (mInput.Key(VK_SPACE))
	{
		if (AnimaScene != 4 && AnimaScene != 3)
		{
			ChangeAnimation(AnimaScene = 3, false, AttackFrame = 30);
		}
	}
	if (AnimaScene == 3 && AttackFrame <= 0)
	{
		ChangeAnimation(AnimaScene = 4, false, AttackFrame = 30);
	}
	if (AnimaScene == 4 && AttackFrame <= 0)
	{
		ChangeAnimation(AnimaScene = 0, true, 60);
	}

	if (mInput.Key('A'))
	{
		//YŽ²‚Ì‰ñ“]’l‚ðŒ¸­
		mRotation = mRotation + ROTATION2_YV;
	}
	if (mInput.Key('D'))
	{
		//YŽ²‚Ì‰ñ“]’l‚ðŒ¸­
		mRotation = mRotation - ROTATION2_YV;
	}
	if (mInput.Key('W'))
	{
		ChangeAnimation(AnimaScene = 1, true, AnimaFrame = 60);
		mPosition = mPosition + VELOCITY2 * mMatrixRotate;
	}
	else if(AnimaScene == 1)
	{
		ChangeAnimation(0, true, 60);
	}
	CXCharacter::Update();
}
#include "CXPlayer.h"

#define ROTATION2_YV CVector(0.0f, 2.0f, 0.0f) //回転速度
#define VELOCITY CVector(0.0f, 0.0f, 0.1f) //移動速度

void CXPlayer::Update()
{
	if (mInput.Key('A'))
	{
		//Y軸の回転値を減少
		mRotation = mRotation + ROTATION2_YV;
	}
	if (mInput.Key('D'))
	{
		//Y軸の回転値を減少
		mRotation = mRotation - ROTATION2_YV;
	}
	if (mInput.Key('W'))
	{
		ChangeAnimation(1, true, 60);
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	else
	{
		ChangeAnimation(0, true, 60);
	}
	CXCharacter::Update();
}
#include "CXPlayer.h"

#define ROTATION2_YV CVector(0.0f, 2.0f, 0.0f) //��]���x
#define VELOCITY CVector(0.0f, 0.0f, 0.1f) //�ړ����x

void CXPlayer::Update()
{
	if (mInput.Key('A'))
	{
		//Y���̉�]�l������
		mRotation = mRotation + ROTATION2_YV;
	}
	if (mInput.Key('D'))
	{
		//Y���̉�]�l������
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
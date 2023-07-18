#include <stdio.h>
#include "CUi.h"
#include "CCamera.h"
#include "SceneType.h"
#include "CApplication.h"

void CUi::Clear()
{
	mFont.Draw(36, 300, 18, 36, "GAME CLEAR!!");
	mFont.Draw(36, 200, 18, 36, "PUSH ENTER KEY!");
}

void CUi::Over()
{
	mFont.Draw(36, 300, 18, 36, "GAME OVER!!");
	mFont.Draw(36, 200, 18, 36, "PUSH ENTER KEY!");
}

void CUi::Start()
{
	mFont.Draw(36, 300, 18, 36, "START PUSH ENTER KEY!");
}

void CUi::Enemy(int enemy)
{
	mEnemy = enemy;
}

CUi::CUi()
	: mHp(0)
	, mTime(0)
	,mRestart(0)
	, mEnemy(0)
	, mPosY(0.0f)
	, mRotX(0.0f)
	, mRotY(0.0f)
{
	mFont.Load("FontWhite.png", 1, 64);
}

void CUi::Hp(int hp)
{
	mHp = hp;
}

void CUi::Time(int time)
{
	mTime = time;
}

void CUi::Restart(int restart)
{
	mRestart = restart;
}

void CUi::Render()
{
	CCamera::Start(0, 800, 0, 600); //2D�`��J�n
	//�`��E�̐ݒ�(�ΐF�̔�����)
	glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
	//������ҏW�G���A�̍쐬
	char buf[64];


	
	sprintf(buf, "TIME:%03d", mTime);
	mFont.Draw(20, 580, 8, 16, buf);

	//�`��E�̐ݒ�(�ΐF�̔�����)
	glColor4f(1.0f, 1.0f, 1.0f, 10.5f);
	sprintf(buf, "RESTART:%03d", mRestart);
	mFont.Draw(20, 20, 8, 16, buf);

	if (CApplication::StageCount == 4)
	{
		glColor4f(1.0f, 1.0f, 1.0f, 10.5f);
		sprintf(buf, "SCORE:%03d", 100000 - (mRestart + 1) * mTime);
		mFont.Draw(200, 300, 18, 36, buf);
		sprintf(buf, "TIME:%03d", mTime);
		mFont.Draw(150, 200, 12, 24, buf);
		sprintf(buf, "RESTART:%03d", mRestart);
		mFont.Draw(400, 200, 12, 24, buf);
		mFont.Draw(200, 400, 18, 36, "GAME CLEAR!!");
		
	}

	//Y���W�̕\��
	//������̐ݒ�
	//sprintf(buf, "PY:%7.2f", mPosY);
	////������̕`��
	//mFont.Draw(500, 330, 8, 16, buf);

	////X����]�l�̕\��
	////������̐ݒ�
	//sprintf(buf, "RX:%7.2f", mRotX);
	////������̕`��
	//mFont.Draw(500, 300, 8, 16, buf);

	////Y����]�l�̕\��
	////������̐ݒ�
	//sprintf(buf, "RY:%7.2f", mRotY);
	////������̕`��
	//mFont.Draw(500, 200, 8, 16, buf);
	CCamera::End(); //2D�`��I��
}

void CUi::PosY(float f)
{
	mPosY = f;
}

void CUi::RotX(float f)
{
	mRotX = f;
}

void CUi::RotY(float f)
{
	mRotY = f;
}
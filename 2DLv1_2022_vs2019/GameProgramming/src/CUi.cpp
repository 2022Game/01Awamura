#include <stdio.h>
#include "CUi.h"

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
	, mNow(0)
	,mNow1(0)
	,mNow2(0)
	,mNow3(0)
	, mEnemy(0)
{
	mFont.Load("FontWhite.png", 1, 64);
}

void CUi::Hp(int hp)
{
	mHp = hp;
}

void CUi::Now(int time)
{
	mNow = time;
}

void CUi::Now1(int time)
{
	mNow1 = time;
}

void CUi::Now2(int time)
{
	mNow2 = time;
}

void CUi::Now3(int time)
{
	mNow3 = time;
}

void CUi::Render()
{
	char str[16];
	sprintf(str, "NOW:%03d", mNow);
	mFont.Draw(620, 580, 10, 20, str);
	sprintf(str, "HP:%d", mHp);
	mFont.Draw(20, 580, 10, 20, str);
	//sprintf(str, "ENEMY:%d", mEnemy);
	//mFont.Draw(20, 580, 10, 20, str);
}

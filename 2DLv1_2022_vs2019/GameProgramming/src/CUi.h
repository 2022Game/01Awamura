#pragma once
#include "CFont.h"
/*
* CUi
* ユーザーインタフェースクラス
*/
class CUi
{
public:
	//ゲームクリア表示
	void Clear();
	//ゲームオーバー表示
	void Over();
	//スタート表示
	void Start();
	//Enemy(敵の数)
	void Enemy(int enemy);
	CUi();
	void Hp(int hp);
	//Time(時間)
	void Now(int now);
	void Now1(int now1);
	void Now2(int now2);
	void Now3(int now3);
	void Render();
private:
	int mEnemy;	//敵の数
	int mHp;
	int mNow;	//経過時間
	int mNow1;
	int mNow2;
	int mNow3;
	CFont mFont;
};

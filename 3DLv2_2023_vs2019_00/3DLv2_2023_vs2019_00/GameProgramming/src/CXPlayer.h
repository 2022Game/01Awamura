#ifndef CENEMY3_H
#define CENEMY3_H
#include "CXCharacter.h"
#include "Cinput.h"

class CXPlayer :public CXCharacter
{
public:
	void Update();
	CXPlayer();
private:
	int AnimaScene; //アニメーション番号
	int AttackFrame; //攻撃時のアニメーションフレーム数
	CInput mInput;
};

#endif
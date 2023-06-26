#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "Cinput.h"
#include "CCollider.h"

class CXPlayer :public CXCharacter
{
public:
	void Update();
	CXPlayer();
	void Init(CModelX* model);
private:
	//コライダの宣言
	CCollider mColSphereBody; //体
	CCollider mColSphereHead; //頭
	CCollider mColSphereSword; //剣
	int AnimaScene; //アニメーション番号
	int AttackFrame; //攻撃時のアニメーションフレーム数
	CInput mInput;
};

#endif
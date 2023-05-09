#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"

/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer : public CCharacter3
{
private:
	//float mVy;	//Y軸速度
	CInput mInput;
	CColliderLine mLine; //線分コライダ
	CColliderLine mLine2;
	CColliderLine mLine3;
	//プレイヤーのインスタンス
	static CPlayer* spInstance;
public:
	//インスタンスのポインタの取得
	static CPlayer* Instance();
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	CPlayer();
	//CPlayer(位置、回転、スケール）
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	void Update();
	//CBullet bullet;
};

#endif
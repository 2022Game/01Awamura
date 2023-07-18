#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CCharacter.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"

/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer : public CCharacter3 ,CCharacter
{
private:
	//float mVy;	//Y軸速度
	CInput mInput;
	CColliderLine mLine; //線分コライダ
	CColliderLine mLine2;
	CColliderLine mLine3;
	int ddStage;
	int ccStage;
	//プレイヤーのインスタンス
	static CPlayer* spInstance;

	//接地している移動オブジェクトのTransform
	CTransform* mGroundedMoveObjTf;
	//接地しているかどうか
	bool mIsGrounded;

	//ステージクリア用のオブジェクトに接地時の処理
	void GroundedClearObj();
	//ステージの壁生成用のオブジェクトに接地時の処理
	void GroundedGuardObj();
	CVector mLastPos;
public:
	static int CountLine;
	static int CountCraft;
	int mTime;
	int mRestart;
	int randddco;
	int randdd;
	int n;
	int jc;//ジャンプカウント
	int jswitch;
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
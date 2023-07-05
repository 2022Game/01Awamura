#ifndef CASoccer_H
#define CASoccer_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CCharacter.h"
//コリコリのインクルード
#include "CCollider.h"
#include "CColliderMesh.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CASoccer : public CCharacter3 {
private:
	//コライダ
	//CColliderMesh mColliderMesh;
	CCollider mCollider;
	CVector mLastPos;
public:
	int ha;
	int hb;
	int hc;
	static int hdhd;
	int coo;
	//static int hn;
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮）
	CASoccer(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
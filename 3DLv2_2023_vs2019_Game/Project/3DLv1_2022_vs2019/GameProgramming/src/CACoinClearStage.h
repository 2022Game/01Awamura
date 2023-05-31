#ifndef CACOINCREARSTAGE_H
#define CACOINCREARSTAGE_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
//コリコリのインクルード
#include "CCollider.h"
#include "CColliderMesh2.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CACoinClearStage : public CCharacter3 {
private:
	//コライダ
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
	CColliderMesh2 mColliderMesh3;
public:
	int SCount;
	int UpCount;
	int SideChengeCount;
	int SideCount;
	//static int mD;
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮）
	CACoinClearStage(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
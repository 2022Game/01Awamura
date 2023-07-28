#ifndef CACOINCREARSTAGE_H
#define CACOINCREARSTAGE_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
//コリコリのインクルード
#include "CCollider.h"
#include "CColliderMesh.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CACoinClearStage : public CCharacter3 {
private:
	//コライダ
	CColliderMesh mColliderMesh;
public:
	int BackCount;
	int SCount;
	int UpCount;
	int SideChengeCount;
	int SideCount;
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//コンストラクタ
	CACoinClearStage(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
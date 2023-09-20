#ifndef CACOIN_H
#define CACOIN_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
//コリコリのインクルード
#include "CCollider.h"
#include "CColliderMesh.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CACoin : public CCharacter3 {
private:
	//コライダ
	CColliderMesh mColliderMesh;
	CCollider mCollider;
	CVector mLastPos;
	int rand11;
	int rand12;
	int rand13;
	int rand14;
	int rand15;
	int rand16;
public:
	int ha;
	int hb;
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
	CACoin(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
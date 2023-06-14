#ifndef CAWood_H
#define CAWood_H
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
class CAWood : public CCharacter3 {
private:
	//コライダ
	//CColliderMesh mColliderMesh;
	CCollider mCollider;
public:
	int ha;
	int hb;
	int hc;
	int hd;
	int coo;
	//static int hn;
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮）
	CAWood(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
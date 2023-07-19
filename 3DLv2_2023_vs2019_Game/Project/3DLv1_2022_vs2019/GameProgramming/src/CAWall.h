#ifndef CAWall_H
#define CAWall_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CCharacter.h"
//コリコリのインクルード
#include "CCollider.h"
#include "CColliderMesh.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CAWall : public CCharacter3 {
private:
	//コライダ
	CColliderMesh mColliderMesh;
	CCollider mCollider;
public:
	//static int hn;
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮）
	CAWall(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
#ifndef CAHamah_H
#define CAHamah_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CCharacter.h"
//コリコリのインクルード
#include "CCollider.h"
#include "CColliderMesh1.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CAHamah : public CCharacter3{
private:
	//コライダ
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
	CColliderMesh1 mColliderMesh2;
public:
	static int hn;
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮）
	CAHamah(CModel* model, const CVector& position,
		const CVector& rotation, const CVector& scale);
	//更新処理
	void Update();
};
#endif
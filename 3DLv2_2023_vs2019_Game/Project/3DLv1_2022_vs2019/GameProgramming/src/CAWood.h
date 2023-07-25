#ifndef CAWood_H
#define CAWood_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CCharacter.h"
//コリコリのインクルード
#include "CCollider.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CAWood : public CCharacter3 {
private:
	//コライダ
	CCollider mCollider;
	CVector mLastPos;
	CVector mStartPos;
public:
	int ha;
	int rararan;
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
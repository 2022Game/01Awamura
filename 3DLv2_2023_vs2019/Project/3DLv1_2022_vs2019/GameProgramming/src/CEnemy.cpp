#include "CEnemy.h"
#include "CEffect.h"
#include "CCollisionManager.h"

//移動速度
#define VELOCITY CVector(0.0f,0.0f,0.09f)

//コンストラクタ
//CEnemy(モデル、位置、回転、拡縮）
CEnemy::CEnemy(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
}

//更新処理
void CEnemy::Update() {
	//行列を更新
	CTransform::Update();
	//位置を移動
	Position(Position() + VELOCITY * MatrixRotate());
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CEnemy::Collision(CCollider* m, CCollider* o) {
	//相手のコライダタイプの判定
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE://球コライダの時
		//コライダのmとyが衝突しているか判定
		if (CCollider::Collision(m, o)) {
			//エフェクト生成
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//衝突している時は無効にする
			//mEnabled = false;
		}
		break;
	case CCollider::EType::ETRIANGLE://三角コライダの時
		CVector adjust;//調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			//衝突しない位置まで戻す
			Position(Position() + adjust);
		}
		break;
	}
	////コライダのmとoが衝突しているか判定
	//if (CCollider::Collision(m, o)) {
	//	//エフェクト生成
	//	new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
	//	//衝突しているときは無効にする
	////	mEnabled = false;
	//}
}

void CEnemy::Collision()
{
	//コライダの優先度変更
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);
}
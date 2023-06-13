#include "CAWall.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.20f,0.0f,0.0f)

//コンストラクタ
//CAHamah(モデル、位置、回転、拡縮）
CAWall::CAWall(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	mColliderMesh.Set(this, &Matrix(), mpModel);
}

void CAWall::Update() {
	//行列を更新
	CTransform::Update();

}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CAWall::Collision(CCollider* m, CCollider* o) {
	//相手のコライダタイプの判定
	//switch (o->Type())
	//{
	//case CCollider::ETRIANGLE2://三角コライダの時
	//	if (m->Type() == CCollider::ELINE) {
	//	}
	//	break;
	//}
	if (CCollider::Collision(m, o)) {
		mEnabled = false;
	}
}

void CAWall::Collision()
{
	//コライダの優先度変更
	mColliderMesh.ChangePriority();
}
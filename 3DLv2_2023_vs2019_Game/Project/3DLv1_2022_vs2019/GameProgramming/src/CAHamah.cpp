#include "CAHamah.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.35f,0.0f,0.0f)

//コンストラクタ
//CAHamah(モデル、位置、回転、拡縮）
CAHamah::CAHamah(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:CCharacter3((int)TaskPriority::eObstacie)
	,mCollider(this,&Matrix(),CVector(),2.25f)
{
	//障害物用のタグ設定
	mTag = ETag::EOBSTACLE;

	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	ha = 0;
	hb = 0;
	mLastPos = position; //前回のポジションに設定する
}

void CAHamah::Update() {
	//移動前の座標を記憶しておく
	mLastPos = Position();
	if (ha % 2 == 0)
	{
		Position(Position() + VELOCITY10 * MatrixRotate());
	}
	else
	{
		Position(Position() - VELOCITY10 * MatrixRotate());
	}
	//行列を更新
	CTransform::Update();
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CAHamah::Collision(CCollider* m, CCollider* o) {
	//相手が線分の壁コライダでなければ、衝突判定を行わない
	if (o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Type()) {
	case CCollider::EType::ELINE:
		if (CCollider::Collision(m, o)) {
				ha++;
		}
		break;
	}
}

	void CAHamah::Collision()
	{
		//コライダの優先度変更
		mCollider.ChangePriority();
		//衝突処理を実行
		CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 100);
	}
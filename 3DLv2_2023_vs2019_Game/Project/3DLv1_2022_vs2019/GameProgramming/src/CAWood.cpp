#include "CAWood.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.20f,0.0f,0.0f)
#define VELOCITY11 CVector(-0.20f,0.0f,0.10f)

//コンストラクタ
//CAHamah(モデル、位置、回転、拡縮）
CAWood::CAWood(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f,1.0f,0.0f), 0.75f)
{
	//障害物用のタグ設定
	mTag = ETag::EOBSTACLE;

	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	ha = 0;
	hb = 40;
	coo = 100;
}

void CAWood::Update() {
	//行列を更新
	CTransform::Update();
	hb--;
	if (CApplication::hcount == 1)
	{
		if (ha % 2 == 0)
		{
			Position(Position() + VELOCITY10 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY10 * MatrixRotate());
		}
	}
	if (CApplication::hcount == 0)
	{
		if (ha % 2 == 0)
		{
			Position(Position() + VELOCITY11 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY11 * MatrixRotate());
		}
	}
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CAWood::Collision(CCollider* m, CCollider* o) {
	switch (o->Type()) {
	case CCollider::ELINE:
		if (CCollider::Collision(m, o)) {
			//衝突しているときは無効にする
			if (hb <= 0)
			{
				ha++;
				hb = 60;
			}
		}
	}
}

void CAWood::Collision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
}
#include "CACoin.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#include <stdlib.h>

#include "time.h"

//移動速度
#define VELOCITY CVector(0.0f,0.075f,0.0f)
#define VELOCITY10 CVector(0.15f,0.0f,0.0f)

int rand(void);
void srand(unsigned int seed);

//コンストラクタ
//CACoin(モデル、位置、回転、拡縮）
CACoin::CACoin(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 0.0f, 0.0f), 3.0f)
	,rand11(0)
	,rand12(0)
	,rand13(0)
	,rand14(0)
	,rand15(0)
	,rand16(0)
{
	//ステージの壁生成用タグを設定
	mTag = ETag::ESTAGEGUARD;

	srand((unsigned int)time(NULL));


	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	mColliderMesh.Set(this, &Matrix(), mpModel);
	SCount = 2;
	UpCount = 180 / 6 * 10;
	SideChengeCount = 0;
	SideCount = 300 / 6;
	ha = 0;
	hb = 0;
	mLastPos = position; //前回のポジションに設定する
	mCollider.Layer(CCollider::ELayer::ECOIN);
}

//更新処理
void CACoin::Update() {
	//移動前の座標を記憶しておく
	mLastPos = Position();
	//位置を移動
	if (SCount >= 2)
	{
		if (SideChengeCount % 2 == 0)
		{
			Position(Position() + VELOCITY10 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY10 * MatrixRotate());
		}
	}
	//行列を更新
	CTransform::Update();
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CACoin::Collision(CCollider* m, CCollider* o) {
	//相手が線分の壁コライダでなければ、衝突判定を行わない
	if (o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Type()) {
	case CCollider::EType::ELINE:
		if (CCollider::Collision(m, o)) {
			//衝突しているときは無効にする
			Position(mLastPos);
			SideChengeCount++;
		}
		break;
	}
}

void CACoin::Collision()
{
	//コライダの優先度変更
	//mColliderMesh.ChangePriority();
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 10);
}
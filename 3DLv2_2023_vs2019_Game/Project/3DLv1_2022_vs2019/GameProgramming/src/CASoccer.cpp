#include "CASoccer.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY20 CVector(0.0f,0.0f,-0.25f)
#define VELOCITY21 CVector(-0.2f,0.0f,0.30f)

int CASoccer::hdhd = 0;
//コンストラクタ
//CAHamah(モデル、位置、回転、拡縮）
CASoccer::CASoccer(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 1.0f, 0.0f), 1.75f)
{
	hdhd = 0;
	//障害物用のタグ設定
	mTag = ETag::EOBSTACLE;
	//木のオブジェクト用のレイヤーを設定
	mCollider.Layer(CCollider::ELayer::ESOCCER);

	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	mLastPos = position; //前回のポジションに設定する
}

void CASoccer::Update() {
	//移動前の座標を記憶しておく
	mLastPos = Position();
	Position(Position() + VELOCITY20 * MatrixRotate());
	//行列を更新
	CTransform::Update();
	if (hdhd == 2)
	{
		hdhd = 0;
	}
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CASoccer::Collision(CCollider* m, CCollider* o) {
	//相手が線分の壁コライダでなければ、衝突判定を行わない
	if (o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Type()) {
	case CCollider::EType::ELINE:
		if (CCollider::Collision(m, o)) {
			mEnabled = false;
			hdhd = 2;
		}
		break;
	}
}

void CASoccer::Collision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 10);
}
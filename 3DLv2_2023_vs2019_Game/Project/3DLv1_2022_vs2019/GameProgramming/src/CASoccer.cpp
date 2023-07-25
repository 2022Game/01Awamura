#include "CASoccer.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#include <stdlib.h>

#include "time.h"

#define VELOCITY20 CVector(0.0f,0.0f,-0.75f)
#define VELOCITY21 CVector(-0.2f,0.0f,-0.30f)
#define VELOCITY22 CVector(0.2f,0.0f,-0.30f)

int rand(void);
void srand(unsigned int seed);

int CASoccer::hdhd = 0;
//コンストラクタ
CASoccer::CASoccer(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 2.0f, 0.0f), 1.50f)
	,rarand(0)
{
	srand((unsigned int)time(NULL));
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
	//mLastPos = Position();
	if (CApplication::hcount == 7)
	{
		Position(Position() + VELOCITY20 * MatrixRotate());
	}
	if (CApplication::hcount == 8)
	{
		if (hdhd % 2 == 0)
		{
			Position(Position() + VELOCITY21 * MatrixRotate());
		}
		else
		{
			Position(Position() + VELOCITY22 * MatrixRotate());
		}
	}
	//行列を更新
	CTransform::Update();
	/*if (hdhd == 2)
	{
		hdhd = 0;
	}*/
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CASoccer::Collision(CCollider* m, CCollider* o) {
	//相手が線分の壁コライダでなければ、衝突判定を行わない
	if (o->Layer() != CCollider::ELayer::ELINEWALL2 && o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Layer()) {
	case CCollider::ELayer::ELINEWALL2:
		if (CCollider::Collision(m, o)) {
			//mEnabled = false;
			//hdhd = 2;
			rarand = 4 + rand() % 17;
			if (CApplication::StageCheck == 0)
			{
				Position((CVector(rarand, 23.0f, 70.0f)));
			}
			if (CApplication::StageCheck == 1)
			{
				Position((CVector(rarand, 23.0f, 120.0f)));
			}
			if (CApplication::StageCheck == 2)
			{
				Position((CVector(rarand, 23.0f, 170.0f)));
			}
			if (CApplication::StageCheck == 3)
			{
				Position((CVector(rarand, 23.0f, 170.0f)));
			}
		}
		break;
	}
		switch (o->Layer()) {
		case CCollider::ELayer::ELINEWALL:
			if (CCollider::Collision(m, o)) {
				hdhd++;
				Position(mLastPos);
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
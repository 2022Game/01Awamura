#include "CAWood.h"
#include "CCollisionManager.h"
#include "CApplication.h"

#include <stdlib.h>

#include "time.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.25f,0.0f,0.0f)
#define VELOCITY11 CVector(-0.25f,0.0f,0.30f)
#define VELOCITY12 CVector(-0.25f,0.0f,-0.30f)
#define VELOCITY13 CVector(0.25f,0.0f,-0.30f)

int rand(void);
void srand(unsigned int seed);

//コンストラクタ
//CAHamah(モデル、位置、回転、拡縮）
CAWood::CAWood(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 1.0f, 0.0f), 0.75f)
	, rararan(0)
{
	//障害物用のタグ設定
	mTag = ETag::EOBSTACLE;
	//木のオブジェクト用のレイヤーを設定
	mCollider.Layer(CCollider::ELayer::EWOOD);

	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	ha = 0;
	mLastPos = position; //前回のポジションに設定する
	mStartPos = position;
}

void CAWood::Update() {
	//移動前の座標を記憶しておく
	mLastPos = Position();
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
	if (CApplication::hcount == 2)
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
	if (CApplication::hcount == 3)
	{
		if (ha % 2 == 0)
		{
			Position(Position() + VELOCITY12 * MatrixRotate());
		}
		else
		{
			Position(Position() + VELOCITY13 * MatrixRotate());
		}
	}
	//行列を更新
	CTransform::Update();
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CAWood::Collision(CCollider* m, CCollider* o) {
	//相手が線分の壁コライダでなければ、衝突判定を行わない
	if (o->Layer() != CCollider::ELayer::ELINEWALL && o->Layer() != CCollider::ELayer::ELINEWALL2)return;

	switch (o->Layer()) {
	case CCollider::ELayer::ELINEWALL:
		if (CCollider::Collision(m, o)) {
			//衝突しているときは無効にする
				Position(mLastPos);
				ha++;
		}
		break;
	}
	switch (o->Layer()) {
	case CCollider::ELayer::ELINEWALL2:
		if (CCollider::Collision(m, o)) {
			//衝突しているときは無効にする
			//Position(mStartPos);
			ha++;
			rararan = 4 + rand() % 17;
			if (CApplication::StageCheck == 0)
			{
				Position((CVector(rararan, 22.9f, 102.0f)));
			}
			if (CApplication::StageCheck == 1)
			{
				Position((CVector(rararan, 22.9f, 154.0f)));
			}
			if (CApplication::StageCheck == 2)
			{
				Position((CVector(rararan, 22.9f, 203.0f)));
			}
			if (CApplication::StageCheck == 3)
			{
				Position((CVector(rararan, 22.9f, 203.0f)));
			}
		}
		break;
	}
}

void CAWood::Collision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 200);
}
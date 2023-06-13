#include "CACoinClearStage.h"
#include "CCollisionManager.h"
#include "CEffect.h"

#define VELOCITY CVector(0.0f,0.75f,0.0f)
#define VELOCITY10 CVector(0.05f,0.0f,0.0f)

//コンストラクタ
//CACoin(モデル、位置、回転、拡縮）
CACoinClearStage::CACoinClearStage(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	mTag = ETag::ESTAGECLEAR;

	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale; //拡縮の設定
	mColliderMesh.Set(this, &mMatrix, mpModel);
	SCount = 0;
	UpCount = 180 / 6;
	SideChengeCount = 0;
	SideCount = 300 / 6;
	//mTag = CCharacter3::ETag::ECOIN;
}

//更新処理
void CACoinClearStage::Update() {
	/*if (mD == 150)
	{
		mEnabled = false;
	}*/
	//行列を更新
	CTransform::Update();
	//位置を移動
	if (SideCount <= 0)
	{
		SideChengeCount++;
		SideCount = 480 / 6;
	}
	if (UpCount < 0)
	{
		//		mPosition = mPosition + VELOCITY10 * mMatrixRotate;
		UpCount = 0;
		SCount = 2;
	}
	if (SCount == 1)
	{
		UpCount--;
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (SCount >= 2)
	{
		SideCount--;
		if (SideChengeCount % 2 == 0)
		{
			mPosition = mPosition + VELOCITY10 * mMatrixRotate;
		}
		else
		{
			mPosition = mPosition - VELOCITY10 * mMatrixRotate;
		}
	}
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CACoinClearStage::Collision(CCollider* m, CCollider* o) {
	//相手のコライダタイプの判定
	switch (o->Type())
	{
	case CCollider::ELINE://三角コライダの時
		CVector adjust;//調整用ベクトル
		if (CCollider::CollisionTriangleLine(o, m, &adjust))
		{
			mEnabled = false;
		}
		break;
	}
}

void CACoinClearStage::Collision()
{
	//コライダの優先度変更
	mColliderMesh.ChangePriority();
}
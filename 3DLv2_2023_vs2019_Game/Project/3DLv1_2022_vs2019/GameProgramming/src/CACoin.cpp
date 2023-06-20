

#include "CACoin.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

//移動速度
#define VELOCITY CVector(0.0f,0.075f,0.0f)
#define VELOCITY10 CVector(0.05f,0.0f,0.0f)

//int CACoin::mD;

//コンストラクタ
//CACoin(モデル、位置、回転、拡縮）
CACoin::CACoin(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//ステージの壁生成用タグを設定
	mTag = ETag::ESTAGEGUARD;

	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	mColliderMesh.Set(this, &Matrix(), mpModel);
	SCount = 0;
	UpCount = 180 / 6 * 10;
	SideChengeCount = 0;
	SideCount = 300 / 6;
	//mTag = CCharacter3::ETag::ECOIN;
}

//更新処理
void CACoin::Update() {
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
		Position(Position() + VELOCITY * MatrixRotate());
	}
	if (SCount >= 2)
	{
		SideCount--;
		if (SideChengeCount % 2 == 0)
		{
			Position(Position() + VELOCITY10 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY10 * MatrixRotate());
		}
	}
}

//衝突処理
//CCollision(コライダ１、コライダ２）
void CACoin::Collision(CCollider* m, CCollider* o) {
	switch (o->Type())
	{
	case CCollider::ESPHERE://球コライダの時
		//コライダのmとyが衝突しているか判定
		if (CCollider::Collision(m, o)) {
			//エフェクト生成
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//衝突している時は無効にする
			//mEnabled = false;
		}
		break;
	}
}

void CACoin::Collision()
{
	//コライダの優先度変更
	mColliderMesh.ChangePriority();
}
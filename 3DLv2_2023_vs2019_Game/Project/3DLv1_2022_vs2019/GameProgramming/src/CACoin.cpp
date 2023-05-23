//#include "CACoin.h"
//
//#include "CTaskManager.h"
//#include "CApplication.h"
//#include "CCollisionManager.h"
//
//#define ROTATION_YV CVector(0.0f,1.0f,0.0f) //回転速度
//#define VELOCITY CVector(0.0f,0.0f,0.05f) //移動速度
//#define VELOCITY1 CVector(0.0f,0.2f,0.0f) //移動速度
//#define VELOCITY2 CVector(0.0f,0.05f,0.0f) //移動速度
//#define VELOCITY3 CVector(0.0f,0.2f,0.0f) //移動速
//#define ROTATION_XV CVector(1.0f,0.0f,0.0f) //回転速度
//
////CPlayer(位置、回転、スケール）
//CACoin::CACoin(const CVector& pos, const CVector& rot, const CVector& scale)
//	: jc(0)
//	, n(0)
//{
//	CTransform::Update(pos, rot, scale);//行列の更新
//}
//
//CACoin::CACoin()
//	/*: mLine(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 2.0f, 0.0f))
//	, mLine2(this, &mMatrix, CVector(-0.5f, 1.2f, 0.0f), CVector(0.5f, 1.2f, 0.0f))
//	, mLine3(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f))*/
//{
//	//インスタンスの設定
//	spInstance = this;
//}
//
////更新処理
//void CACoin::Update() {
//	//変換行列の更新
//	CTransform::Update();
//	//Ui設定
//	CApplication::Ui()->PosY(mPosition.Y());
//	CApplication::Ui()->RotX(mRotation.X());
//	CApplication::Ui()->RotY(mRotation.Y());
//	mPosition = mPosition + VELOCITY;
//}
//
//void CACoin::Collision(CCollider* m, CCollider* o) {
//	//自身のコライダタイプの判定
//	switch (m->Type()) {
//	case CCollider::ETRIANGLE://線分コライダ
//		//相手のコライダが三角コライダの時
//		if (o->Type() == CCollider::ELINE) {
//			CVector adjust;//調整用ベクトル
//			//三角形と線分の衝突判定
//			if (CCollider::CollisionTriangleLine(o, m, &adjust))
//			{
//				//位置の更新(mPosition + adjust)
//				mPosition = mPosition + adjust;
//				//行列の更新
//				CTransform::Update();
//			}
//		}
//		break;
//	}
//}
//
////衝突処理
//void CACoin::Collision()
//{
//	//コライダの優先度変更
//	mLine.ChangePriority();
//	mLine2.ChangePriority();
//	mLine3.ChangePriority();
//	//衝突処理を実行
//	CCollisionManager::Instance()->Collision(&mLine, COLLISIONRANGE);
//	CCollisionManager::Instance()->Collision(&mLine2, COLLISIONRANGE);
//	CCollisionManager::Instance()->Collision(&mLine3, COLLISIONRANGE);
//}
//
//CACoin* CACoin::spInstance = nullptr;
//
//CACoin* CACoin::Instance()
//{
//	return spInstance;
//}

#include "CACoin.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

//移動速度
#define VELOCITY CVector(0.0f,0.75f,0.0f)
#define VELOCITY10 CVector(0.01f,0.0f,0.0f)

int CACoin::a,b,c,d;

//コンストラクタ
//CACoin(モデル、位置、回転、拡縮）
CACoin::CACoin(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//モデル、位置、回転、拡縮を設定する
	mpModel = model; //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale; //拡縮の設定
	mColliderMesh1.Set(this, &mMatrix, mpModel);
	a = 0;
	b = 180;
	c = 0;
	d = 480;
}

//更新処理
void CACoin::Update(){
	//行列を更新
	CTransform::Update();
	//位置を移動
	if (d <= 0)
	{
		c++;
		d = 480;
	}
	if (b < 0)
	{
//		mPosition = mPosition + VELOCITY10 * mMatrixRotate;
		b = 0;
		a = 2;
	}
	if (a == 1)
	{
		b--;
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (a >= 2)
	{
		d--;
		if (c % 2 == 0)
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
void CACoin::Collision(CCollider* m, CCollider* o) {
	//相手のコライダタイプの判定
	switch (o->Type())
	{
	case CCollider::ETRIANGLE://三角コライダの時
		if (o->Type() == CCollider::ELINE) {
			//	CVector adjust;//調整値
			//if (CCollider::CollisionTriangleLine(o, m, &adjust)) {
				//	CVector adjust;//調整値
					//if (CCollider::CollisionTriangleSphere(o, m, &adjust))
					//{
					//	//衝突しない位置まで戻す
					//	mPosition = mPosition + adjust;
				a = 1;
				//}
		}
		break;
	}
}

void CACoin::Collision()
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
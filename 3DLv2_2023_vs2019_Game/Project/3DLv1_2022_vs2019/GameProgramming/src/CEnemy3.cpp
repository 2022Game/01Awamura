#include "CEnemy3.h"
#include "CEffect.h"
#include "CCollisionManager.h"
#include "CPlayer.h"

#define OBJ "res\\Beard_man.obj" //モデルのファイル
#define MTL "res\\Beard_man.mtl" //モデルのマテリアルファイル
#define HP 3 //耐久値
#define VELOCITY 0.11f //速度

CModel CEnemy3::sModel; //モデルデータ作成

//デフォルトコンストラクタ
CEnemy3::CEnemy3()
	:CCharacter3(1)
	,mCollider(this,&Matrix(),CVector(0.0f,0.0f,0.0f),0.4f)
	, mHp(HP)
{
	//モデルがないときは読みこむ
	if (sModel.Triangles().size() == 0)
	{
		sModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &sModel;
}

//コンストラクタ
//CEnemy(位置、回転、拡縮）
CEnemy3::CEnemy3(const CVector& position, const CVector& rotation,
	const CVector& scale)
	:CEnemy3() //デフォルトコンストラクタを実行する
{
	//位置、回転、拡散を設定する
	Position(position); //位置の設定
	Rotation(rotation); //回転の設定
	Scale(scale); //拡縮の設定
	CTransform::Update(); //行列の更新
	//目標地点の設定
	mPoint = Position() + CVector(0.0f, 0.0f, 100.0f) * MatrixRotate();
	////目標地点の設定
	//mPoint = mPosition + CVector(0.0f, 0.0f, 100.0f) * mMatrixRotate;
}

//更新処理
void CEnemy3::Update()
{
	CTransform::Update();
	//プレイヤーのポインタが０以外の時
	CPlayer* player = CPlayer::Instance();
	//HPが０以下の時　撃破
	if (mHp <= 0)
	{
		mHp--;
		//１５フレーム毎にエフェクト
		if (mHp % 15 == 0)
		{
			//エフェクト生成
			new CEffect(Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
		//下降させる.
		Position(Position() - CVector(0.0f, 0.03f, 0.0f));
		CTransform::Update();
		return;
	}
	if (player != nullptr)
	{
		//プレイヤーまでのベクトルを求める
		CVector vp = player->Position() - Position();
		//左ベクトルとの内積を求める
		float dx = vp.Dot(MatrixRotate().VectorX());
		//上ベクトルとの内積を求める
		float dy = vp.Dot(MatrixRotate().VectorY());
		float dz = vp.Dot(MatrixRotate().VectorZ());

		//X軸のズレが2.0以下
		if (-2.0f < dx && dx < 2.0f)
		{
			if (-2.0f < dy && dy < 2.0f)
			{
				if (30.0f > dz && dz >= 0.0f)
				{
					//弾を発射します
					/*CBullet* bullet = new CBullet();
					bullet->Set(0.1f, 1.5f);
					bullet->Position(
						CVector(0.0f, 0.0f, 10.0f) * mMatrix);
					bullet->Rotation(mRotation);
					bullet->Update();*/
				}
			}
		}
	}
	//目標地点までのベクトルを求める
	CVector vp = mPoint - Position();
	//課題
	//左ベクトルとの内積を求める
	float dx = vp.Dot(MatrixRotate().VectorX());
	//上ベクトルとの内積を求める
	float dy = vp.Dot(MatrixRotate().VectorY());
	const float margin = 0.1f;
	//左右方向へ回転
	if (dx > margin)
	{
		Rotation(Rotation() + CVector(0.0f, 1.0f, 0.0f));//左へ回転
	}
	else if (dx < -margin)
	{
		//課題
		Rotation(Rotation() - CVector(0.0f, 1.0f, 0.0f));//右へ回転
	}
	//上下方向へ回転
	if (dy > margin)
	{
		Rotation(Rotation() + CVector(-1.0f, 0.0f, 0.0f));//上へ回転
	}
	else if (dy < -margin)
	{
		//課題
		Rotation(Rotation() - CVector(-1.0f, 0.0f, 0.0f));//下へ回転
	}
	//機体前方へ移動する
	Position(Position() + MatrixRotate().VectorZ() * VELOCITY);
	CTransform::Update(); //行列更新
	///およそ3秒後に目標地点を更新
	int r = rand() % 180; //rand()は整数の乱数を返す
	//%180は１８０で割った余りを求める
	if (r == 0)
	{
		if (player != nullptr)
		{
			mPoint = player->Position();
		}
		else
		{
			mPoint = mPoint * CMatrix().RotateY(45);
		}
	}
}

//更新処理
//Collision(コライダ1、コライダ２）
void CEnemy3::Collision(CCollider* m, CCollider* o)
{
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE://球コライダの時
		//コライダのmとyが衝突しているか判定
		if (CCollider::Collision(m, o)) {
			//エフェクト生成
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//衝突している時は無効にする
			//mEnabled = false;
			mHp--;
		}
		break;
	case CCollider::EType::ETRIANGLE:
		CVector adjust;
		if (CCollider::CollisionTriangleSphere(o, m, &adjust) && mHp <= 0)
		{
			mEnabled = false;
		}
		break;
	}
}

void CEnemy3::Collision()
{
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
}

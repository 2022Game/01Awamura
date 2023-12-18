#include "CAppearFloor.h"
#include "Maths.h"

//消えるのにかかる時間
#define FADE_TIME 3.0f
//消えた後の待機時間
#define WAIT_TIME 3.0f

//コンストラクタ
CAppearFloor::CAppearFloor(const CVector& pos, const CVector& scale,
	ETag reactionTag, ELayer reactionLayer)
	:CRideableObject(ETaskPriority::eTransparent)
	, mState(EState::Idle)
	, mStateStep(0)
	, mReactionTag(reactionTag)
	, mReactionLayer(reactionLayer)
	, mFadeTime(0.0f)
	, mWaitTime(0.0f)
	, mIsCollision(false)
{
	//床のモデルを取得
	mpModel = CResourceManager::Get<CModel>("FieldCube");

	//消える床のコライダー作成
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	//プレイヤーは上に乗るので必須で当たり判定を有効にする
	mpColliderMesh->SetCollisionLayers({ ELayer::ePlayer });
	mpColliderMesh->SetCollisionTags({ ETag::ePlayer });
	//生成時に設定された触れたときに反応するオブジェクトタグと
	//コライダーのレイヤーを個別に設定
	mpColliderMesh->SetCollisionLayer(mReactionLayer, true);
	mpColliderMesh->SetCollisionTag(mReactionTag, true);

	Position(pos);
	Scale(scale);

	SetColor(CColor(1.0f, 0.0f, 1.0f, 1.0f));
}

//デストラクタ
CAppearFloor::~CAppearFloor()
{
	SAFE_DELETE(mpColliderMesh);
}

//衝突処理
void CAppearFloor::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	CObjectBase* owner = other->Owner();
	if (owner == nullptr)return;

	//衝突しているのが、反応するオブジェクトであれば
	if (owner->Tag() == mReactionTag && other->Layer() == mReactionLayer)
	{
		//現在が待機状態であれば、現れている状態へ切り替える
		if (mState == EState::Idle)
		{
			ChangeState(EState::Appeared);
			mFadeTime = FADE_TIME;
			mWaitTime = WAIT_TIME;
		}

		//反応するオブジェクトが触れているので、衝突オン
		mIsCollision = true;
	}
}

//状態を切り替える
void CAppearFloor::ChangeState(EState state)
{
	mState = state;
	mStateStep = 0;
}

//待機状態の更新処理
void CAppearFloor::UpdateIdle()
{

}


//現れている状態の待機処理
void CAppearFloor::UpdateAppeared()
{
	//反応するオブジェクトが触れいていたら
	if (mIsCollision)
	{
		//ステップ０からやり直し
		mStateStep = 0;
		mWaitTime = WAIT_TIME;
		mFadeTime = FADE_TIME;
	}
	//ステップごとに処理を切り替え
	switch (mStateStep)
	{
		//ステップ０ フェードの後の待機時間
	case 0:
		//待ち時間が経過していなければ、経過時間分減らす
		if (mWaitTime > 0.0f)
		{
			mWaitTime -= Time::DeltaTime();
		}
		else
		{
			mStateStep++;
		}
		break;
		//ステップ１で消えた床を元に戻す
	case 1:
		if (mFadeTime > 0.0f)
		{
			mFadeTime -= Time::DeltaTime();
		}
		else
		{
			//待機状態へ戻す
			ChangeState(EState::Idle);
			mFadeTime = 0.0f;
			mWaitTime = 0.0f;
		}
		break;
	}
}

//更新
void CAppearFloor::Update()
{
	//現在の状態に合わせて処理を切り替え
	switch (mState)
	{
		//待機状態
	case EState::Idle:
		UpdateIdle();
		break;
		//現れている状態
	case EState::Appeared:
		UpdateAppeared();
		break;
	}
	//フェード時間に合わせて床のアルファ値を求めてアルファ値を設定
	float alpha = Math::Clamp01(mFadeTime / FADE_TIME);
	SetAlpha(alpha);

	//衝突フラグを初期化
	mIsCollision = false;
}

//描画
void CAppearFloor::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}
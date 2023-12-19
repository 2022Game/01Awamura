#include "CDisappearFloor2.h"
#include "Maths.h"

//消えるのにかかる時間
#define FADE_TIME 5.0f
//消えた後の待機時間
#define WAIT_TIME 2.0f

//コンストラクタ
CDisappearFloor2::CDisappearFloor2(const CVector& pos, const CVector& scale,
	ETag reactionTag, ELayer reactionLayer)
	:CRideableObject(ETaskPriority::eTransparent)
	, mState(EState::Idle)
	, mStateStep(0)
	, mReactionTag(reactionTag)
	, mReactionLayer(reactionLayer)
	, mFadeTime(0.0f)
	, mWaitTime(0.0f)
{
	//床のモデルを取得
	mpModel = CResourceManager::Get<CModel>("FieldCube");

	//消える床のコライダー作成
	mpColliderMesh = new CColliderMesh(this, ELayer::eObject, mpModel, true);
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
CDisappearFloor2::~CDisappearFloor2()
{
	SAFE_DELETE(mpColliderMesh);
}

//衝突処理
void CDisappearFloor2::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	CObjectBase* owner = other->Owner();
	if (owner == nullptr)return;

	//衝突しているのが、反応するオブジェクトであれば
	if (owner->Tag() == mReactionTag && other->Layer() == mReactionLayer)
	{
		//現在が待機状態であれば、フェード状態へ切り替える
		if (mState == EState::Idle)
		{
			ChangeState(EState::Fade);
		}
	}
}

//状態を切り替える
void CDisappearFloor2::ChangeState(EState state)
{
	mState = state;
	mStateStep = 0;
}

//待機状態の更新処理
void CDisappearFloor2::UpdateIdle()
{

}

//フェード中の更新処理
void CDisappearFloor2::UpdateFade()
{
	//フェード時間が経っていない
	if (mFadeTime < FADE_TIME)
	{
		//経過時間を加算
		mFadeTime += Time::DeltaTime();
	}
	//フェード時間が経過した
	else
	{
		//フェード後の待機時間へ復帰
		ChangeState(EState::Wait);
		mFadeTime = FADE_TIME;
		mWaitTime = WAIT_TIME;

		//完全に消えたタイミングで
		//コライダーをオフにして、乗れないようにする
		mpColliderMesh->SetEnable(false);
	}
}

//フェード後の待機処理
void CDisappearFloor2::UpdateWait()
{
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
			mFadeTime -= 10 * Time::DeltaTime();
		}
		else
		{
			//待機状態へ戻す
			ChangeState(EState::Idle);
			mFadeTime = 0.0f;
			mWaitTime = 0.0f;

			//元の状態に戻ったタイミングで
			//コライダーをオンにして乗れるようにする
			mpColliderMesh->SetEnable(true);
		}
		break;
	}
}

//更新
void CDisappearFloor2::Update()
{
	//現在の状態に合わせて処理を切り替え
	switch (mState)
	{
		//待機状態
	case EState::Idle:
		UpdateIdle();
		break;
		//フェード中
	case EState::Fade:
		UpdateFade();
		break;
		//フェード後の待機
	case EState::Wait:
		UpdateWait();
		break;
	}
	//フェード時間に合わせて床のアルファ値を求めてアルファ値を設定
	float alpha = 1.0f - Math::Clamp01(mFadeTime / FADE_TIME);
	SetAlpha(alpha);
}

//描画
void CDisappearFloor2::Render()
{
	mpModel->SetColor(mColor);
	mpModel->Render(Matrix());
}
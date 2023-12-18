#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"

//消える床
class CAppearFloor :public CRideableObject
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">初期位置</param>
	/// <param name="scale">床のスケール値</param>
	/// <param name="reactionTag">触れると反応するオブジェクトのタグ</param>
	/// <param name="reactionLayer">触れると反応するコライダーのレイヤー</param>
	CAppearFloor(const CVector& pos, const CVector& scale,
		ETag reactionTag, ELayer reactionLayer);

	//デストラクタ
	~CAppearFloor();

	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit)override;

	//更新
	void Update() override;
	//描画
	void Render() override;

private:
	enum class EState
	{
		Idle,//待機
		Appeared, //現れている状態
	};
	//状態を切り替える
	void ChangeState(EState state);
	//待機状態の更新処理
	void UpdateIdle();
	//現れている状態の更新処理
	void UpdateAppeared();

	CModel* mpModel; //消える床のモデル
	CColliderMesh* mpColliderMesh; //消える床のコライダー

	EState mState; //現在の状態
	int mStateStep; //状態内のステップ

	ETag mReactionTag; //触れたときに反応するオブジェクトのタグ
	ELayer mReactionLayer; //触れたときに反応するコライダーのレイヤ-

	float mFadeTime; //フェード時間
	float mWaitTime; //フェード後の待機時間
	bool mIsCollision; //衝突しているかどうか
};
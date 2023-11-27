#pragma once
//キャラクタクラスのインクルード
#include "CXCharacter.h"
#include "CColliderLine.h"
#include "CColliderSphere.h"
#include "CRideableObject.h"

/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer : public CXCharacter
{
public:
	//インスタンスのポインタの取得
	static CPlayer* Instance();

	// コンストラクタ
	CPlayer();
	// デストラクタ
	~CPlayer();

	// 待機状態
	void UpdateIdle();
	// 攻撃
	void UpdateAttack();
	// 攻撃終了待ち
	void UpdateAttackWait();
	// ジャンプ開始
	void UpdateJumpStart();
	// ジャンプ中
	void UpdateJump();
	// ジャンプ終了
	void UpdateJumpEnd();
	//空中
	void UpdateJumpN();
	//クリア
	void UpdateClear();
	//クリア終了
	void UpdateClearEnd();
	//倒れる
	void UpdateDown();
	//吹っ飛び倒れる
	void UpdateBadDown();
	//起き上がる
	void UpdateUp();

	// 更新
	void Update();

	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="self">衝突した自身のコライダー</param>
	/// <param name="other">衝突した相手のコライダー</param>
	/// <param name="hit">衝突した時の情報</param>
	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit) override;

	// 描画
	void Render();

	/*static bool mSwitchObject;*/

private:
	// アニメーションの種類
	enum class EAnimType
	{
		None = -1,

		eIdle,		// 待機
	//	eSuperJump,
		eSlowRun,
		eJumpUp,
		eJumpDown2,
		eJumpDown3,
	//	eRun,
		eJumpN,
		eDown,
		eUp,
		eClear,

		Num
	};
	// アニメーション切り替え
	void ChangeAnimation(EAnimType type);

	// プレイヤーのインスタンス
	static CPlayer* spInstance;

	// アニメーションデータ
	struct AnimData
	{
		std::string path;	// アニメーションデータのパス
		bool loop;			// ループするかどうか
		float frameLength;	// アニメーションのフレーム数
	};
	// アニメーションデータのテーブル
	static const AnimData ANIM_DATA[];

	// プレイヤーの状態
	enum class EState
	{
		eIdle,		// 待機
		eAttack,	// 攻撃
		eAttackWait,// 攻撃終了待ち
		eJumpStart,	// ジャンプ開始
		eJump,		// ジャンプ中
		eJumpEnd,	// ジャンプ終了
		eJumpN, //空中
		eClear, //クリア
		eClearEnd, //クリア終了
		eDown, //倒れる
		eBadDown, 
		eUp, //起き上がる
	};
	EState mState;	// プレイヤーの状態

	CVector mMoveSpeed;	// 移動速度
	bool mIsGrounded;	// 接地しているかどうか

	CColliderLine* mpColliderLine;
	CColliderSphere* mpColliderSphere;
	CColliderLine* mpColliderLineBody;
	CColliderLine* mpColliderLineHead;
	CColliderLine* mpColliderLineLeg;
	CTransform* mpRideObject;
	CVector mStartPos;
	int Downcount;
};

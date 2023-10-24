//プレイヤークラスのインクルード
#include "CPlayer.h"
#include "CInput.h"
#include "CCamera.h"
#include "CField.h"

// プレイヤーのインスタンス
CPlayer* CPlayer::spInstance = nullptr;

// プレイヤーのモデルデータのパス
#define MODEL_PATH "Character\\Player\\Beardman.x"

// プレイヤーのアニメーションデータのテーブル
const CPlayer::AnimData CPlayer::ANIM_DATA[] =
{
	{ "Character\\Player\\Normalidol.x",true,	554.0f	},	// Tポーズ
	{ "Character\\Player\\SuperJump.x",true,	160.0f	},	// Tポーズ
	{ "Character\\Player\\run.x",		true,	40.0f	},	// 待機
	{ "Character\\Player\\jumpUp.x",		true,	30.0f	},	// 待機
	{ "Character\\Player\\jumpDown2.x",		true,	35.0f	},	// 歩行
	{ "Character\\Player\\jumpDown3.x",		true,	38.0f	},	// 歩行
	//{ "Character\\Player\\anim\\attack.x",		false,	91.0f	},	// 攻撃
	//{ "Character\\Player\\anim\\SuperJump.x",	false,	25.0f	},	// ジャンプ開始
	//{ "Character\\Player\\anim\\jump.x",		true,	1.0f	},	// ジャンプ中
	//{ "Character\\Player\\anim\\jump_end.x",	false,	26.0f	},	// ジャンプ終了
};

#define PLAYER_HEIGHT 1.0f
#define MOVE_SPEED 0.375f
#define JUMP_SPEED 1.5f
#define GRAVITY 0.0625f
#define JUMP_END_Y 1.0f

// コンストラクタ
CPlayer::CPlayer()
	: CXCharacter(ETag::ePlayer, ETaskPriority::ePlayer)
	, mState(EState::eIdle)
	, mpRideObject(nullptr)
{
	//インスタンスの設定
	spInstance = this;

	// モデルデータ読み込み
	CModelX* model = new CModelX();
	model->Load(MODEL_PATH);

	Scale(10.0f, 10.0f, 10.0f);


	// テーブル内のアニメーションデータを読み込み
	int size = ARRAY_SIZE(ANIM_DATA);
	for (int i = 0; i < size; i++)
	{
		const AnimData& data = ANIM_DATA[i];
		if (data.path.empty()) continue;
		model->AddAnimationSet(data.path.c_str());
	}
	// CXCharacterの初期化
	Init(model);

	// 最初は待機アニメーションを再生
	ChangeAnimation(EAnimType::eIdle);

	mpColliderLine = new CColliderLine
	(
		this, ELayer::eField,
		CVector(0.0f, 0.0f, 0.0f),
		CVector(0.0f, PLAYER_HEIGHT, 0.0f)
	);

	mpColliderLineBody = new CColliderLine
	(
		this, ELayer::eField,
		CVector(PLAYER_HEIGHT/4, PLAYER_HEIGHT/2, 0.0f),
		CVector(-PLAYER_HEIGHT/4, PLAYER_HEIGHT/2, 0.0f)
	);

	mpColliderLineBody = new CColliderLine
	(
		this, ELayer::eField,
		CVector(0.0f, PLAYER_HEIGHT / 2, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT / 2, 0.0f)
	);
	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::eField,
		CVector(PLAYER_HEIGHT / 4, 1.0f, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, 1.0f, 0.0f)
	);

	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::eField,
		CVector(0.0f, 1.0f, PLAYER_HEIGHT / 4),
		CVector(0.0f, 1.0f, 0.0f)
	);

	mpColliderLineHead = new CColliderLine
	(
		this, ELayer::eField,
		CVector(PLAYER_HEIGHT / 4, PLAYER_HEIGHT, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, PLAYER_HEIGHT, 0.0f)
	);

	mpColliderLineHead = new CColliderLine
	(
		this, ELayer::eField,
		CVector(0.0f, PLAYER_HEIGHT, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT, 0.0f)
	);
	mpColliderLine->SetCollisionLayers({ ELayer::eField });
	mpColliderLineBody->SetCollisionLayers({ ELayer::eField });
	mpColliderLineLeg->SetCollisionLayers({ ELayer::eField });
	mpColliderLineHead->SetCollisionLayers({ ELayer::eField });
}

CPlayer::~CPlayer()
{
	if (mpColliderLine != nullptr)
	{
		delete mpColliderLine;
		mpColliderLine = nullptr;
	}

	if (mpModel != nullptr)
	{
		delete mpModel;
		mpModel = nullptr;
	}
}

CPlayer* CPlayer::Instance()
{
	return spInstance;
}

// アニメーション切り替え
void CPlayer::ChangeAnimation(EAnimType type)
{
	/*if (!(EAnimType::None < type && type < EAnimType::Num)) return;
	AnimData data = ANIM_DATA[(int)type];
	CXCharacter::ChangeAnimation((int)type, data.loop, data.frameLength);*/
}

// 待機
void CPlayer::UpdateIdle()
{
	mMoveSpeed.X(0.0f);
	mMoveSpeed.Z(0.0f);
	//CXCharacter::ChangeAnimation(0, true, 1.0f);
	
	if (mIsGrounded)
	{
		// 移動処理
		// キーの入力ベクトルを取得
		CVector input;
		if (CInput::Key('W'))		input.Z(1.0f);
		else if (CInput::Key('S'))	input.Z(-1.0f);
		if (CInput::Key('A'))		input.X(-1.0f);
		else if (CInput::Key('D'))	input.X(1.0f);

		// 入力ベクトルの長さで入力されているか判定
		if (input.LengthSqr() > 0.0f)
		{
			// カメラの向きに合わせた移動ベクトルに変換
			CVector move = CCamera::MainCamera()->Rotation() * input;
			move.Y(0.0f);
			move.Normalize();

			mMoveSpeed += move * MOVE_SPEED;

			// 歩行アニメーションに切り替え
			CXCharacter::ChangeAnimation(2, true, 5.0f);
		}
		// 移動キーを入力していない
		else
		{
			// 待機アニメーションに切り替え
			CXCharacter::ChangeAnimation(0, true, 544.0f);
		}

		// 左クリックで攻撃状態へ移行
		if (CInput::PushKey(VK_LBUTTON))
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mState = EState::eAttack;
		}
		// SPACEキーでジャンプ開始へ移行
		else if (CInput::PushKey(VK_SPACE))
		{
			mState = EState::eJumpStart;
		}
	}
	else
	{
		// 待機アニメーションに切り替え
		CXCharacter::ChangeAnimation(0, true, 544.0f);
	}
}

// 攻撃
void CPlayer::UpdateAttack()
{
	// 攻撃アニメーションを開始
	ChangeAnimation(EAnimType::eAttack);
	// 攻撃終了待ち状態へ移行
	mState = EState::eAttackWait;
}

// 攻撃終了待ち
void CPlayer::UpdateAttackWait()
{
	// 攻撃アニメーションが終了したら、
	if (IsAnimationFinished())
	{
		// 待機状態へ移行
		mState = EState::eIdle;
		ChangeAnimation(EAnimType::eIdle);
	}
}

// ジャンプ開始
void CPlayer::UpdateJumpStart()
{
	//ChangeAnimation(EAnimType::eJumpStart);
	CXCharacter::ChangeAnimation(3, true, 10.0f);
	if (IsAnimationFinished())
	{
		mState = EState::eJump;

		mMoveSpeed += CVector(0.0f, JUMP_SPEED, 0.0f);
		mIsGrounded = false;
	}
}

// ジャンプ中
void CPlayer::UpdateJump()
{
	CXCharacter::ChangeAnimation(4, true, 40.0f);
	if (mMoveSpeed.Y() <= 0.0f)
	{
		//ChangeAnimation(EAnimType::eJumpEnd);
	}
}

// ジャンプ終了
void CPlayer::UpdateJumpEnd()
{
	if (IsAnimationFinished())
	{
		mState = EState::eIdle;
	}
}

//クリア
void CPlayer::UpdateClear()
{
	// クリアアニメーションを開始
	//ChangeAnimation(EAnimType::eAttack);
	// クリア終了待ち状態へ移行
	CXCharacter::ChangeAnimation(0, true, 544.0f);
	mState = EState::eClearEnd;
}

//クリア終了
void CPlayer::UpdateClearEnd()
{
	// クリアアニメーションが終了したら、
	if (IsAnimationFinished())
	{
		// 待機状態へ移行
		CField::mClearCountSwitch = 1;
		CField::mStageCreateSwitch = 1;
		CField::mClearCount = 1;
		//ChangeAnimation(EAnimType::eIdle);
		mState = EState::eIdle;
	}
}

// 更新
void CPlayer::Update()
{
	SetParent(mpRideObject);
	mpRideObject = nullptr;

	// 状態に合わせて、更新処理を切り替える
	switch (mState)
	{
		// 待機状態
		case EState::eIdle:
			UpdateIdle();
			break;
		// 攻撃
		case EState::eAttack:
			UpdateAttack();
			break;
		// 攻撃終了待ち
		case EState::eAttackWait:
			UpdateAttackWait();
			break;
		// ジャンプ開始
		case EState::eJumpStart:
			UpdateJumpStart();
			break;
		// ジャンプ中
		case EState::eJump:
			UpdateJump();
			break;
		// ジャンプ終了
		case EState::eJumpEnd:
			UpdateJumpEnd();
			break;
		// クリア
		case EState::eClear:
			UpdateClear();
			break;
		// クリア終了
		case EState::eClearEnd:
			UpdateClearEnd();
			break;
	}

	mMoveSpeed -= CVector(0.0f, GRAVITY, 0.0f);

	// 移動
	Position(Position() + mMoveSpeed);

	// プレイヤーを移動方向へ向ける
	CVector current = VectorZ();
	CVector target = mMoveSpeed;
	target.Y(0.0f);
	target.Normalize();
	CVector forward = CVector::Slerp(current, target, 0.125f);
	Rotation(CQuaternion::LookRotation(forward));

	// キャラクターの更新
	CXCharacter::Update();

	mIsGrounded = false;
}

// 衝突処理
void CPlayer::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderLine)
	{
		if (other->Layer() == ELayer::eClearObject)
		{
			mState = EState::eClear;
		}
		//else if (CField::mClearCountSwitch = 0);
		if (other->Layer() == ELayer::eClearObject || other->Layer() == ELayer::eField)
		{
			if (mState == EState::eJump)
			{
				CXCharacter::ChangeAnimation(5, true, 38.0f);
				mState = EState::eJumpEnd;
			}
		}

		if (other->Layer() == ELayer::eField || other->Layer() == ELayer::eObject || other->Layer() == ELayer::eClearObject)
		{
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust);
			mIsGrounded = true;
			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
				if (mState != EState::eIdle)
				{
					CXCharacter::ChangeAnimation(5, true, 38.0f);
					mState = EState::eJumpEnd;
				}
			}
		}
	}
	if (self == mpColliderLineBody)
	{
		if (other->Layer() == ELayer::eObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;

			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
			}
		}
	}

	if (self == mpColliderLineLeg)
	{
		if (other->Layer() == ELayer::eObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;

			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
			}
		}
	}
	
	if (self == mpColliderLineHead)
	{
		if (other->Layer() == ELayer::eObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;

			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
			}
		}
	}
}

// 描画
void CPlayer::Render()
{
	CXCharacter::Render();
}

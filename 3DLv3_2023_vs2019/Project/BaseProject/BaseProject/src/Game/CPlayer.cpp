//プレイヤークラスのインクルード
#include "CPlayer.h"
#include "CInput.h"
#include "CCamera.h"
#include "CField.h"

// プレイヤーのインスタンス
CPlayer* CPlayer::spInstance = nullptr;

// プレイヤーのモデルデータのパス
#define MODEL_PATH "Character\\Player\\Beardman.x"

bool CPlayer::mSwitchRObject = false;
bool CPlayer::mSwitchLObject = false;

// プレイヤーのアニメーションデータのテーブル
const CPlayer::AnimData CPlayer::ANIM_DATA[] =
{
	{ "Character\\Player\\Normalidol.x",true,	554.0f	},	// Tポーズ
	//{ "Character\\Player\\SuperJump.x",true,	160.0f	},	// 謎
	{ "Character\\Player\\slowrun.x",		true,	44.0f	},	// 待機
	{ "Character\\Player\\jumpUp.x",		false,	8.0f	},	// ジャンプ開始
	{ "Character\\Player\\jumpDown2.x",		false,	35.0f	},	// ジャンプ落下中
	{ "Character\\Player\\jumpDown3.x",		false,	38.0f	},	// ジャンプ着地
	//{ "Character\\Player\\run.x",		true,	40.0f	},	// 走る
	{ "Character\\Player\\jumpN.x",		false,	1.0f	},	// 空中
	{ "Character\\Player\\Down.x",		false,	60.0f	},	// 倒れる
	{ "Character\\Player\\Up.x",		false,	60.0f	},	// 起き上がる
	{ "Character\\Player\\Clear.x",		false,	90.0f	}, //クリア
};

#define PLAYER_HEIGHT 1.6f
#define MOVE_SPEED 0.375f
#define JUMP_SPEED 1.5f
#define GRAVITY 0.0625f
#define JUMP_END_Y 1.0f

// コンストラクタ
CPlayer::CPlayer()
	: CXCharacter(ETag::ePlayer, ETaskPriority::ePlayer)
	, mState(EState::eIdle)
	, mpRideObject(nullptr)
	, Downcount(180)
{
	//インスタンスの設定
	spInstance = this;
	Position(0.0f,30.0f,0.0f);
	mStartPos = Position();

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
		this, ELayer::ePlayer,
		CVector(0.0f, 0.0f, 0.0f),
		CVector(0.0f, PLAYER_HEIGHT, 0.0f)
	);

	mpColliderLineBody = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT/4, PLAYER_HEIGHT/2, 0.0f),
		CVector(-PLAYER_HEIGHT/4, PLAYER_HEIGHT/2, 0.0f)
	);

	mpColliderLineBody = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, PLAYER_HEIGHT / 2, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT / 2, -0.4f)
	);
	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, 0.1f, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, 0.1f, 0.0f)
	);

	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, 0.1f, PLAYER_HEIGHT / 4),
		CVector(0.0f, 0.1f, -0.4f)
	);

	mpColliderLineHead = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, PLAYER_HEIGHT, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, PLAYER_HEIGHT, 0.0f)
	);

	mpColliderLineHead = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, PLAYER_HEIGHT, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT, -0.4f)
	);
	/*mpColliderSphere = new CColliderSphere
	(
		this, ELayer::ePlayerSpher,1.0f,CVector(0.0f, PLAYER_HEIGHT, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT, -0.4f)
	);*/
	/*mpColliderSphere->SetCollisionLayers({});*/
	mpColliderLine->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,
		ELayer::eSlopeField,ELayer::eStorn,ELayer::eMoveRSwitch,ELayer::eMoveLSwitch});
	mpColliderLineBody->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject});
	mpColliderLineLeg->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject,ELayer::eSlopeField });
	mpColliderLineHead->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject });
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
	if (!(EAnimType::None < type && type < EAnimType::Num)) return;
	AnimData data = ANIM_DATA[(int)type];
	CXCharacter::ChangeAnimation((int)type, data.loop, data.frameLength);
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
		if (CInput::Key('W'))		input.Z(-2.0f);
		else if (CInput::Key('S'))	input.Z(2.0f);
		if (CInput::Key('A'))		input.X(-2.0f);
		else if (CInput::Key('D'))	input.X(2.0f);

		// 入力ベクトルの長さで入力されているか判定
		if (input.LengthSqr() > 0.0f)
		{
			// カメラの向きに合わせた移動ベクトルに変換
			CVector move = CCamera::MainCamera()->Rotation() * input;
			move.Y(0.0f);
			move.Normalize();

			mMoveSpeed += move * MOVE_SPEED;

			// 歩行アニメーションに切り替え
			ChangeAnimation(EAnimType::eSlowRun);
		}
		// 移動キーを入力していない
		else
		{
			// 待機アニメーションに切り替え
			ChangeAnimation(EAnimType::eIdle);
		}

		// 左クリックで攻撃状態へ移行
		if (CInput::PushKey(VK_LBUTTON))
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mState = EState::eDown;
		}
		// SPACEキーでジャンプ開始へ移行
		else if (CInput::PushKey(VK_SPACE))
		{
			mState = EState::eJumpStart;
		}
	}
	else
	{
		//if (mMoveSpeed.Y() <= -0.5f && mMoveSpeed.Y() >-1.0f)
		//{
		//	// 待機アニメーションに切り替え
		//	ChangeAnimation(EAnimType::eIdle);
		//}
		
		if (mMoveSpeed.Y() <= -0.2f)
		{
			mState = EState::eJumpN;
		}
	}
}

//コライダーを行列にアタッチする用
//const CAmatrix* bodyMtx = GetFrameMtx("Armature_Body");
//mpAttackCol->SetAttachMtx(bodyMtx);

// 攻撃
void CPlayer::UpdateAttack()
{
	// 攻撃アニメーションを開始
	//ChangeAnimation(EAnimType::eDown);
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
	ChangeAnimation(EAnimType::eJumpUp);
	if (IsAnimationFinished())
	{
		mMoveSpeed += CVector(0.0f, JUMP_SPEED, 0.0f);
		mIsGrounded = false;
		mState = EState::eJump;
	}
}

// ジャンプ中
void CPlayer::UpdateJump()
{
	ChangeAnimation(EAnimType::eJumpDown2);
	//Downcount--;
	/*if (Downcount < 0)
	{
		Position(mStartPos);
		Downcount = 180;
	}*/
	if (mMoveSpeed.Y() <= 0.0f)
	{
		//CXCharacter::ChangeAnimation(5, true, 38.0f);
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

//空中
void CPlayer::UpdateJumpN()
{
	ChangeAnimation(EAnimType::eJumpN);
	/*Downcount--;
	if (Downcount < 0)
	{
		Position(mStartPos);
		Downcount = 180;
	}*/
	if (IsAnimationFinished())
	{

	}
}

//倒れる
void CPlayer::UpdateDown()
{
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f)
	{
		mState = EState::eUp;
	}
}

//吹っ飛び倒れる
void CPlayer::UpdateBadDown()
{
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f)
	{
		mState = EState::eUp;
	}
}

//起き上がる
void CPlayer::UpdateUp()
{
	mMoveSpeed.X(0.0f);
	mMoveSpeed.Z(0.0f);
	ChangeAnimation(EAnimType::eUp);
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
	mMoveSpeed.X(0.0f);
	mMoveSpeed.Z(0.0f);
	ChangeAnimation(EAnimType::eClear);
	if (IsAnimationFinished())
	{
		mState = EState::eClearEnd;
	}
}

//クリア終了
void CPlayer::UpdateClearEnd()
{
	//ChangeAnimation(EAnimType::eUp);
	// クリアアニメーションが終了したら、
	//if (IsAnimationFinished())
	//{
		// 待機状態へ移行
		CField::mClearCountSwitch = 1;
		CField::mStageCreateSwitch = 1;
		CField::mClearCount = 1;
		//CField::mDeleteSwitch = 1;
		//ChangeAnimation(EAnimType::eIdle);
		Position(mStartPos);
		mState = EState::eIdle;
//	}
}

// 更新
void CPlayer::Update()
{
	SetParent(mpRideObject);
	mpRideObject = nullptr;

	if (mMoveSpeed.Y() <= 0.0f )
	{
		Downcount--;
		if (Downcount < 0)
		{
			Position(mStartPos);
			Downcount = 180;
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mState = EState::eDown;
		}
	}
	if (mMoveSpeed.Y() >= 0.0f && Downcount != 180)
		{
			Downcount = 180;
		}
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
		//ジャンプ中
		case EState::eJumpN:
			UpdateJumpN();
			break;
		// クリア
		case EState::eClear:
			UpdateClear();
			break;
		// クリア終了
		case EState::eClearEnd:
			UpdateClearEnd();
			break;
		//倒れる
		case EState::eDown:
			UpdateDown();
			break;
		//吹っ飛び倒れる
		case EState::eBadDown:
			UpdateDown();
			break;
		//起き上がる
		case EState::eUp:
			UpdateUp();
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
	mSwitchRObject = false;
	mSwitchLObject = false;
	mIsGrounded = false;
}

// 衝突処理
void CPlayer::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderLine)
	{
		//クリア判定コイン着地判定
		if (other->Layer() == ELayer::eClearObject)
		{
			//待機状態以外
			if (mState != EState::eIdle)
			{
				//空中から着地した時
				if (mState == EState::eJump || mState == EState::eJumpN)
				{
					//着地時に移動しないようにする
					mMoveSpeed.X(0.0f);
					mMoveSpeed.Z(0.0f);
					//着地モーション
					ChangeAnimation(EAnimType::eJumpDown3);
				}
				//クリア状態以外でアニメーションが終わった時にクリア状態にする
				if (mState != EState::eClear && mState != EState::eClearEnd && IsAnimationFinished())
				{
					mState = EState::eClear;
				}
			}
			//通常時にクリア土台に着いたらクリアにする
			if (mState == EState::eIdle)
			{
				mState = EState::eClear;
			}
		}
		
		//待機状態を含む着地判定
		if (other->Layer() == ELayer::eClearObject || other->Layer() == ELayer::eField)
		{
			if (mState == EState::eJump || mState == EState::eJumpN)
			{
				//着地時に滑らない
				mMoveSpeed.X(0.0f);
				mMoveSpeed.Z(0.0f);
				ChangeAnimation(EAnimType::eJumpDown3);
				mState = EState::eJumpEnd;
			}
		}

		//フィールドと障害物とクリア土台の上に乗っかる
		if (other->Layer() == ELayer::eField || other->Layer() == ELayer::eObject || other->Layer() == ELayer::eClearObject)
		{
			//落ちないようにする
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			//乗れる土台
			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
				if (mState != EState::eIdle)
				{
					if(mState == EState::eJump || mState == EState::eJumpN)
					{
						//滑らないようにする
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
						ChangeAnimation(EAnimType::eJumpDown3);
						mState = EState::eJumpEnd;
					}
					//ダウンした時に地面を滑らないようにする
					if (mState == EState::eDown || mState == EState::eBadDown)
					{
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
					}
				}
			}
		}

		if (other->Layer() == ELayer::eSlopeField)
		{
			//落ちないようにする
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			//乗れる土台
			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
				if (mState != EState::eIdle)
				{
					if (mState == EState::eJump || mState == EState::eJumpN)
					{
						//滑らないようにする
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
						ChangeAnimation(EAnimType::eJumpDown3);
						mState = EState::eJumpEnd;
					}
					//ダウンした時に地面を滑らないようにする
					if (mState == EState::eDown || mState == EState::eBadDown)
					{
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
					}
				}
			}
		}

		//悪い障害物
		if (other->Layer() == ELayer::eBadObject)
		{
			//押し戻される
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			//空中でぶつかったときにダウンする
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump /*|| mState != EState::eBadDown || mState != EState::eDown*/)
			{
				mState = EState::eBadDown;
			}
		}
		//とても悪い障害物
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			//当たったらDOWNする
			if (mState != EState::eBadDown || mState != EState::eDown || mState != EState::eUp)
			{
				mState = EState::eBadDown;
			}
		}
		//ワープ障害物
		if (other->Layer() == ELayer::eWarpObject)
		{
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			//mIsGrounded = true;
			//条件によりワープ位置を変える
			//ゲームステージ１スタート
			if (CField::mStageCount == 0)
			{
				CField::mClearCount = 1;
				CField::mClearCountSwitch = 1;
				CField::mStageCreateSwitch = 1;
				//ステージ１開始位置へワープ
				Position(mStartPos);
			}
		}
		//岩
		if (other->Layer() == ELayer::eStorn)
		{
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState != EState::eBadDown || mState != EState::eDown || mState != EState::eUp)
			{
				mState = EState::eBadDown;
			}
		}
		
		if (other->Layer() == ELayer::eMoveRSwitch)
		{
			mSwitchRObject = true;
		}
		if (other->Layer() == ELayer::eMoveLSwitch)
		{
			mSwitchLObject = true;
		}
	}

	//胴の判定
	if (self == mpColliderLineBody)
	{
		if (other->Layer() == ELayer::eObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;

			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
			}
		}
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump /*|| mState != EState::eBadDown || mState != EState::eDown*/)
			{
				mState = EState::eBadDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState != EState::eBadDown || mState != EState::eUp || mState != EState::eDown)
			{
				mState = EState::eBadDown;
			}
		}
	}

	//足の判定
	if (self == mpColliderLineLeg)
	{
		if (other->Layer() == ELayer::eObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;

			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
			}
		}
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump /*|| mState != EState::eDown*/)
			{
				mState = EState::eBadDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState != EState::eDown || mState != EState::eBadDown || mState != EState::eUp)
			{
				mState = EState::eBadDown;
			}
		}
	}
	
	//頭の判定
	if (self == mpColliderLineHead)
	{
		if (other->Layer() == ELayer::eObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;

			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
			}
		}
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump /*|| mState != EState::eBadDown || mState != EState::eDown*/)
			{
				mState = EState::eBadDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mState != EState::eDown || mState != EState::eBadDown || mState != EState::eUp)
			{
				mState = EState::eBadDown;
			}
		}
	}
}

// 描画
void CPlayer::Render()
{
	CXCharacter::Render();
}

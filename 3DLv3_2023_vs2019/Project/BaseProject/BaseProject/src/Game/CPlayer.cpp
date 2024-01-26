//プレイヤークラスのインクルード
#include "CPlayer.h"
#include "CInput.h"
#include "CCamera.h"
#include "CField.h"
#include "CGameManager.h"
#include "CDisappearFloor.h"

// プレイヤーのインスタンス
CPlayer* CPlayer::spInstance = nullptr;


bool CPlayer::mSwitchRObject = false;
bool CPlayer::mSwitchLObject = false;
bool CPlayer::mResetCount = false;
bool CPlayer::mDownSwitch = false;

// プレイヤーのアニメーションデータのテーブル
const CPlayer::AnimData CPlayer::ANIM_DATA[] =
{
	{ "Character\\Player\\Normalidol.x",true,	277.0f	},	// Tポーズ
	//{ "Character\\Player\\SuperJump.x",true,	160.0f	},	// 謎
	{ "Character\\Player\\slowrun.x",		true,	35.0f	},	//走る
	{ "Character\\Player\\jumpUp.x",		false,	8.0f	},	// ジャンプ開始
	{ "Character\\Player\\jumpDown2.x",		false,	25.0f	},	// ジャンプ落下中
	{ "Character\\Player\\jumpDown3.x",		false,	26.0f	},	// ジャンプ着地
	//{ "Character\\Player\\run.x",		true,	40.0f	},	// 走る
	{ "Character\\Player\\jumpN.x",		false,	1.0f	},	// 空中
	{ "Character\\Player\\Down.x",		false,	60.0f	},	// 倒れる
	{ "Character\\Player\\Up.x",		false,	60.0f	},	// 起き上がる
	{ "Character\\Player\\Clear.x",		false,	90.0f	}, //クリア
	{ "Character\\Player\\Squat.x",		false,	22.5f	}, //しゃがみ
	{ "Character\\Player\\SquatUp.x",		false,	22.0f	}, //しゃがみ解除
};

#define PLAYER_HEIGHT 1.8f
#define MOVE_SPEED 0.375f
#define JUMP_SPEED 1.5f
#define GRAVITY 0.0625f
#define JUMP_END_Y 1.0f

// コンストラクタ
CPlayer::CPlayer()
	: CXCharacter(ETag::ePlayer, ETaskPriority::ePlayer)
	, mState(EState::eIdle)
	, mpRideObject(nullptr)
	, mStateStep(0)
	, mDowncount(180)
	, mIsPlayedSlashSE(false)
	, mCollisioncheck(false)
	, mIceGrounded(false)
	, mIceDown(false)
	, mIceLeft(false)
	, mIceRight(false)
	, mIceUp(false)
	, Box(0)
	, Box2(0)
{
	/*SetColor(CColor(1.0f, 0.0f, 1.0f, 1.0f));
	SetAlpha(0.1f);*/
	//インスタンスの設定
	spInstance = this;
	Position(0.0f,30.0f,0.0f);
	mStartPos = Position();



	// モデルデータ読み込み
	CModelX* model = CResourceManager::Get<CModelX>("Player");

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

	mpSlashSE = CResourceManager::Get<CSound>("SlashSound");

	mpColliderLine = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, 0.0f, 0.0f),
		CVector(0.0f, PLAYER_HEIGHT, 0.0f)
	);

	mpColliderLineHead = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, PLAYER_HEIGHT, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, PLAYER_HEIGHT, 0.0f)
	);

	mpColliderLineHead2 = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, PLAYER_HEIGHT, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT, -0.4f)
	);

	mpColliderLineBodyHalf = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, PLAYER_HEIGHT * 0.75, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, PLAYER_HEIGHT * 0.75, 0.0f)
	);

	mpColliderLineBodyHalf2 = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, PLAYER_HEIGHT * 0.75, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT * 0.75, -0.4f)
	);

	mpColliderLineBody = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, PLAYER_HEIGHT / 2, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, PLAYER_HEIGHT / 2, 0.0f)
	);

	mpColliderLineBody2 = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, PLAYER_HEIGHT / 2, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT / 2, -0.4f)
	);
	mpColliderLineLegHalf = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, PLAYER_HEIGHT * 0.25, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, PLAYER_HEIGHT * 0.25, 0.0f)
	);

	mpColliderLineLegHalf2 = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, PLAYER_HEIGHT * 0.25, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT * 0.25, -0.4f)
	);

	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(PLAYER_HEIGHT / 4, 0.1f, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, 0.1f, 0.0f)
	);

	mpColliderLineLeg2 = new CColliderLine
	(
		this, ELayer::ePlayer,
		CVector(0.0f, 0.1f, PLAYER_HEIGHT / 4),
		CVector(0.0f, 0.1f, -0.4f)
	);

	mColliderPos = mpColliderLineHead->Position();
	mColliderPos2 = mpColliderLineHead2->Position();

	mColliderPos3 = mpColliderLineBody->Position();
	mColliderPos4 = mpColliderLineBody2->Position();
	/*mpColliderSphere = new CColliderSphere
	(
		this, ELayer::ePlayerSpher,1.0f,CVector(0.0f, PLAYER_HEIGHT, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT, -0.4f)
	);*/
	/*mpColliderSphere->SetCollisionLayers({});*/
	mpColliderLine->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject,ELayer::eWarpObject,
		ELayer::eSlopeField,ELayer::eStone,ELayer::eMoveRSwitch,ELayer::eMoveLSwitch,ELayer::eDead,ELayer::eIceField,ELayer::eMoveObject });
		mpColliderLineBody->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject,
			ELayer::eStone,ELayer::eMoveObject });
		mpColliderLineBody2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
			ELayer::eBigBadObject,ELayer::eMoveObject });
	mpColliderLineLeg->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
		ELayer::eBigBadObject,ELayer::eSlopeField,ELayer::eIceField,ELayer::eMoveObject });
	mpColliderLineLeg2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
		ELayer::eBigBadObject,ELayer::eSlopeField,ELayer::eIceField,ELayer::eMoveObject });

		mpColliderLineHead->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
			ELayer::eBigBadObject,ELayer::eMoveObject });
		mpColliderLineHead2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
			ELayer::eBigBadObject,ELayer::eMoveObject });
		mpColliderLineBodyHalf->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject,
			ELayer::eStone,ELayer::eMoveObject });
		mpColliderLineLegHalf->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
			ELayer::eBigBadObject,ELayer::eSlopeField,ELayer::eMoveObject });
		mpColliderLineBodyHalf2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
			ELayer::eBigBadObject,ELayer::eMoveObject });
		mpColliderLineLegHalf2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,
			ELayer::eBigBadObject,ELayer::eSlopeField,ELayer::eMoveObject });
}

CPlayer::~CPlayer()
{
	if (mpColliderLine != nullptr)
	{
		delete mpColliderLine;
		mpColliderLine = nullptr;
	}
	spInstance = nullptr;
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

//乗ることができるオブジェクトが削除された時の処理
void CPlayer::DeleteRideableObject(CTransform* rideObj)
{
	//削除されるのが現在乗っているオブジェクトであれば
	//乗っているオブジェクトを解除
	if (mpRideObject == rideObj)
	{
		mpRideObject = nullptr;
	}
}

//ステージ開始時の位置を設定
void CPlayer::SetStartPosition(const CVector& pos)
{
	mStartPos = pos;
	Position(mStartPos);
}

//現在の状態を切り替え
void CPlayer::ChangeState(EState state)
{
	mState = state;
	mStateStep = 0;
}

//準備中の状態
void CPlayer::UpdateReady()
{
	//ステップごとに処理を切り替える
	switch (mStateStep)
	{
		//ステップ０　初期化処理
	case 0:
		//プレイヤー全ての衝突判定をOFFにする
		SetEnableCol(false);
		//プレイヤーの移動速度を０にする
		mMoveSpeed = CVector::zero;
		//次のステップへ
		mStateStep++;
		break;
	case 1:
		//ゲームが開始したら
		if (CGameManager::GameState() == EGameState::eGame)
		{
			//プレイヤーの衝突判定をオンにする
			SetEnableCol(true);
			//現在の状態を待機に切り替え
			ChangeState(EState::eIdle);
		}
		break;
	}
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
		if (CGameManager::StageNo() != 8)
		{
			if (CInput::Key('W'))	     input.Z(-2.0f);
			else if (CInput::Key('S'))   input.Z(2.0f);
			if (CInput::Key('A'))		 input.X(-2.0f);
			else if (CInput::Key('D'))	 input.X(2.0f);
		}

		//ステージ8の状態
		if (CGameManager::StageNo() == 8)
		{
			//壁にゴリゴリしないようにする
			if (mIceGrounded != false && mCollisioncheck == true)
			{
				if (CInput::Key('W') && mIceUp != true)	    mIceGrounded = false, mIceUp = true,Box = 1, input.Z(-2.0f);
				else if (CInput::Key('S') && mIceDown != true)  mIceGrounded = false, mIceDown = true,Box = 2, input.Z(2.0f);
				else if (CInput::Key('A') && mIceLeft != true)		mIceGrounded = false, mIceLeft = true,Box = 3, input.X(-2.0f);
				else if (CInput::Key('D') && mIceRight != true)	mIceGrounded = false, mIceRight = true,Box = 4, input.X(2.0f);
			}

			//平常時
			if (mIceGrounded != false && mCollisioncheck == false)
			{
				if (CInput::Key('W'))	    mIceGrounded = false, input.Z(-2.0f);
				else if (CInput::Key('S')) mIceGrounded = false, input.Z(2.0f);
				else if (CInput::Key('A'))		 mIceGrounded = false, input.X(-2.0f);
				else if (CInput::Key('D')) mIceGrounded = false, input.X(2.0f);
			}
		}
		//壁にゴリゴリしないようにする
		if (CGameManager::StageNo() == 8)
		{
			if (Box2 != Box)
			{
				if (Box2 == 1)
				{
					mIceUp = false;
					Box2 = 0;
				}
				if (Box2 == 2)
				{
					mIceDown = false;
					Box2 = 0;
				}
				if (Box2 == 3)
				{
					mIceLeft = false;
					Box2 = 0;
				}
				if (Box2 == 4)
				{
					mIceRight = false;
					Box2 = 0;
				}
			}
		}
		Box2 = Box;

		// 入力ベクトルの長さで入力されているか判定
		if (input.LengthSqr() > 0.0f)
		{
			// カメラの向きに合わせた移動ベクトルに変換
			CCamera* mainCamera = CCamera::MainCamera();
			CVector camForward = mainCamera->VectorZ();
			CVector camSide = CVector::Cross(CVector::up, camForward);
			CVector move = camForward * input.Z() + camSide * input.X();
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

		// 左クリックでしゃがみ状態へ移行
		if (CInput::PushKey(VK_LBUTTON))
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			ChangeState(EState::eSquat);

			CCamera::MainCamera()->Position();
		}
		// SPACEキーでジャンプ開始へ移行
		else if (CInput::PushKey(VK_SPACE))
		{
			ChangeState(EState::eJumpStart);
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
			ChangeState(EState::eJumpN);
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
	ChangeState(EState::eAttackWait);
}

// 攻撃終了待ち
void CPlayer::UpdateAttackWait()
{
	// 攻撃アニメーションが終了したら、
	if (IsAnimationFinished())
	{
		// 待機状態へ移行
		ChangeState(EState::eIdle);
		ChangeAnimation(EAnimType::eIdle);
	}
}

// ジャンプ開始
void CPlayer::UpdateJumpStart()
{
	//mMoveSpeed.X(0.0f);
	//mMoveSpeed.Z(0.0f);
	//if (!mIsGrounded)
	//{
	//	CVector input;
	//	if (CInput::Key('W'))	     input.Z(-2.0f);
	//	else if (CInput::Key('S'))   input.Z(2.0f);
	//	if (CInput::Key('A'))		 input.X(-2.0f);
	//	else if (CInput::Key('D'))	 input.X(2.0f);
	//	// 入力ベクトルの長さで入力されているか判定
	//	if (input.LengthSqr() > 0.0f)
	//	{
	//		// カメラの向きに合わせた移動ベクトルに変換
	//		CCamera* mainCamera = CCamera::MainCamera();
	//		CVector camForward = mainCamera->VectorZ();
	//		CVector camSide = CVector::Cross(CVector::up, camForward);
	//		CVector move = camForward * input.Z() + camSide * input.X();
	//		move.Y(0.0f);
	//		move.Normalize();

	//		mMoveSpeed += move * MOVE_SPEED;
	//	}
	//}
	//ChangeAnimation(EAnimType::eJumpStart);
	ChangeAnimation(EAnimType::eJumpUp);
	if (IsAnimationFinished())
	{
		mMoveSpeed += CVector(0.0f, JUMP_SPEED, 0.0f);
		mIsGrounded = false;
		ChangeState(EState::eJump);
	}
}

// ジャンプ中
void CPlayer::UpdateJump()
{
	if (!mIsGrounded)
	{
		mMoveSpeed.X(0.0f);
		mMoveSpeed.Z(0.0f);
		CVector input;
		ChangeAnimation(EAnimType::eJumpDown2);
		if (CInput::Key('W'))	     input.Z(-2.0f);
		else if (CInput::Key('S'))   input.Z(2.0f);
		if (CInput::Key('A'))		 input.X(-2.0f);
		else if (CInput::Key('D'))	 input.X(2.0f);
		// 入力ベクトルの長さで入力されているか判定
		if (input.LengthSqr() > 0.0f)
		{
			// カメラの向きに合わせた移動ベクトルに変換
			CCamera* mainCamera = CCamera::MainCamera();
			CVector camForward = mainCamera->VectorZ();
			CVector camSide = CVector::Cross(CVector::up, camForward);
			CVector move = camForward * input.Z() + camSide * input.X();
			move.Y(0.0f);
			move.Normalize();

			mMoveSpeed += move * MOVE_SPEED;
		}
	}
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
		ChangeState(EState::eIdle);
	}
}

//空中
void CPlayer::UpdateJumpN()
{
	if (!mIsGrounded)
	{
		mMoveSpeed.X(0.0f);
		mMoveSpeed.Z(0.0f);
		CVector input;
		//ChangeAnimation(EAnimType::eJumpDown2);
		if (CInput::Key('W'))	     input.Z(-2.0f);
		else if (CInput::Key('S'))   input.Z(2.0f);
		if (CInput::Key('A'))		 input.X(-2.0f);
		else if (CInput::Key('D'))	 input.X(2.0f);
		// 入力ベクトルの長さで入力されているか判定
		if (input.LengthSqr() > 0.0f)
		{
			// カメラの向きに合わせた移動ベクトルに変換
			CCamera* mainCamera = CCamera::MainCamera();
			CVector camForward = mainCamera->VectorZ();
			CVector camSide = CVector::Cross(CVector::up, camForward);
			CVector move = camForward * input.Z() + camSide * input.X();
			move.Y(0.0f);
			move.Normalize();

			mMoveSpeed += move * MOVE_SPEED;
		}
	}
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
	mDownSwitch = true;
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f)
	{
		ChangeState(EState::eUp);
	}
}

//吹っ飛び倒れる
void CPlayer::UpdateBadDown()
{
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f && mIsGrounded == true)
	{
		ChangeState(EState::eUp);
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
		mDownSwitch = false;
		ChangeState(EState::eIdle);
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
		ChangeState(EState::eClearEnd);
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
		//CField::mClearCountSwitch = 1;
		//CField::mStageCreateSwitch = 1;
		//CField::mClearCount = 1;
		//CField::mStageCount++;
		////CField::mDeleteSwitch = 1;
		////ChangeAnimation(EAnimType::eIdle);
		//if (CField::mStageCount == 3)
		//{
		//	Position(0.0f, 30.0f, 240.0f);
		//}
		//if(CField::mStageCount != 3)
		//{
		//	Position(mStartPos);
		//}
	
	//ステージをクリア
	CGameManager::StageClear();

	//ステージをクリアしたら、次のステージ開始まで準備中の状態に変更
	ChangeState(EState::eReady);
}

//しゃがみ
void CPlayer::UpdateSquat()
{
	ChangeAnimation(EAnimType::eSquat);
	//しゃがみボタン解除でもしゃがみ戻りに移行する
	if (IsAnimationFinished() && CInput::Key(VK_LBUTTON) == false)
	{
		ChangeState(EState::eSquatUp);
	}
}

//しゃがみ戻り
void CPlayer::UpdateSquatUp()
{
	ChangeAnimation(EAnimType::eSquatUp);
	if (IsAnimationFinished())
	{
		ChangeState(EState::eIdle);
	}
}

//死亡
void CPlayer::UpdateDead()
{
	Position(mStartPos);
	ChangeState(EState::eDown);
}

//滑る
void CPlayer::UpdateIce()
{
	ChangeAnimation(EAnimType::eJumpN);
	if (mIceGrounded == true)
	{
		//mCollisioncheck = false;
		ChangeState(EState::eJumpEnd);
	}
}

// 更新
void CPlayer::Update()
{
	if (CGameManager::StageNo() == 7 && CDisappearFloor::mFadeCount <= 0)
	{
		Position(0.0f, -270.0f, -90.0f);
		mMoveSpeed.Y(-0.1f);
		mMoveSpeed.X(0.0f);
		mMoveSpeed.Z(0.0f);
		CDisappearFloor::mFadeCount = CDisappearFloor::mFadeCountBox;
	}


	if (mResetCount == true)
	{
		mResetCount = false;
	}

	SetParent(mpRideObject);
	mpRideObject = nullptr;

	if (mMoveSpeed.Y() < 0.0f)
	{
		mDowncount--;
		if (mDowncount < 0)
		{
			Position(mStartPos);
			mDowncount = 180;
			mMoveSpeed.Y(-0.1f);
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mResetCount = true;
			ChangeState(EState::eDown);
		}
	}
	if (mMoveSpeed.Y() >= 0.0f && mDowncount != 180)
		{
			mDowncount = 180;
		}
	/*if (mResetCount != 0)
	{
		mResetCount = 0;
	}*/
	// 状態に合わせて、更新処理を切り替える
	switch (mState)
	{
		//準備中の状態
	    case EState::eReady:
		UpdateReady();
		break;
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
			//しゃがむ
		case EState::eSquat:
			UpdateSquat();
			break;
			//しゃがむ解除
		case EState::eSquatUp:
			UpdateSquatUp();
			break;
			//死亡
		case EState::eDead:
			UpdateDead();
			break;
			//滑る床
		case EState::eIce:
			UpdateIce();
			break;
	}

	//準備中でなければ移動処理などを行う
	if (mState != EState::eReady && mState != EState::eClear && mState != EState::eClearEnd )
	{
		//mColliderSpeed = CVector(0.0f, -10.0f, 0.0f);

		if (!CInput::Key(VK_SPACE))
		{
			mMoveSpeed -= CVector(0.0f, GRAVITY, 0.0f);
		}
		// 移動
		Position(Position() + mMoveSpeed);

		// プレイヤーを移動方向へ向ける
		CVector current = VectorZ();
		CVector target = mMoveSpeed;
		target.Y(0.0f);
		target.Normalize();
		CVector forward = CVector::Slerp(current, target, 0.125f);
		Rotation(CQuaternion::LookRotation(forward));
	}

	// キャラクターの更新
	CXCharacter::Update();
	mSwitchRObject = false;
	mSwitchLObject = false;
	mIsGrounded = false;
	//mIceGrounded = false;
	//mCollisioncheck = false;
	if (mState == EState::eSquat)
	{
		mpColliderLineHead->Position(mColliderPos3); 
		mpColliderLineHead2->Position(mColliderPos4);
	}
	if (mState == EState::eSquatUp)
	{
		mpColliderLineHead->Position(mColliderPos);
		mpColliderLineHead2->Position(mColliderPos2);
	}
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
				if (mState != EState::eReady && mState != EState::eClear && mState != EState::eClearEnd && IsAnimationFinished())
				{
					ChangeState(EState::eClear);
				}
			}
			//通常時にクリア土台に着いたらクリアにする
			if (mState == EState::eIdle)
			{
				ChangeState(EState::eClear);
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
				ChangeState(EState::eJumpEnd);
			}
		}

		//フィールドと障害物とクリア土台の上に乗っかる
		if (other->Layer() == ELayer::eField || other->Layer() == ELayer::eObject || other->Layer() == ELayer::eClearObject)
		{
			//落ちないようにする
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (CGameManager::StageNo() == 8)
			{
				mIceGrounded = true;
			}
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
						ChangeState(EState::eJumpEnd);
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

		if (other->Layer() == ELayer::eField && CGameManager::StageNo() == 8)
		{
			mCollisioncheck = false;
		}

		//滑る床
		if (other->Layer() == ELayer::eIceField)
		{
			//落ちないようにする
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mIceGrounded == false)
			{
				ChangeState(EState::eIce);
			}
		}

		//坂
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
						ChangeState(EState::eJumpEnd);
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
			if (mState != EState::eSquat && mState != EState::eClear)
			{
				//押し戻される
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				//空中でぶつかったときにダウンする
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					ChangeState(EState::eBadDown);
				}
			}
		}
		//とても悪い障害物
		if (other->Layer() == ELayer::eBigBadObject)
		{
			if (mState != EState::eSquat && mState != EState::eClear)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				//当たったらDOWNする
				/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
					ChangeState(EState::eBadDown);
				//}
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
			if (CGameManager::StageNo() == 0)
			{
				//入口ステージクリアで次のステージへ
				CGameManager::StageClear();
				//ステージ１開始位置へワープ
				Position(mStartPos);
			}
		}
		//岩
		if (other->Layer() == ELayer::eStone)
		{
			if (mState != EState::eSquat && mState != EState::eClear)
			{
				//mMoveSpeed.Y(-0.2f);
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
					ChangeState(EState::eBadDown);
				//}
			}
		}

		//当たると死亡
		if (other->Layer() == ELayer::eDead)
		{
			/*Position(Position() + hit.adjust * hit.weight);*/
			ChangeState(EState::eDead);
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
	if (self == mpColliderLineBody || self == mpColliderLineBody2)
	{
		//syougaibutu
		if (CGameManager::StageNo() == 8 && other->Layer() == ELayer::eObject)
		{
			mIceGrounded = true;
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			//ChangeState(EState::eJumpEnd);
		}
			if (mState != EState::eClear)
			{
				if (mState != EState::eDown && mState != EState::eBadDown || mIsGrounded != true)
				{
					if (other->Layer() == ELayer::eObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;

						if (other->Tag() == ETag::eRideableObject)
						{
							mpRideObject = other->Owner();
						}
					}
					if (other->Layer() == ELayer::eMoveObject)
					{
						Position(Position() + hit.adjust * hit.weight);
					}
					if (other->Layer() == ELayer::eBadObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
						{
							ChangeState(EState::eBadDown);
						}
					}
					if (other->Layer() == ELayer::eBigBadObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						/*if (mState != EState::eBadDown && mState != EState::eUp && mState != EState::eDown)
						{*/
						ChangeState(EState::eBadDown);
						//}
					}
					//岩
					if (other->Layer() == ELayer::eStone)
					{
						mMoveSpeed.Y(-0.2f);
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
						{*/
						ChangeState(EState::eBadDown);
						//}
					}
				}
			}
	}

	//胸の判定
	if (self == mpColliderLineBodyHalf || self == mpColliderLineBodyHalf2)
	{
		//syougaibutu
		if (CGameManager::StageNo() == 8 && other->Layer() == ELayer::eObject)
		{
			mIceGrounded = true;
			mCollisioncheck = true;
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			//ChangeState(EState::eJumpEnd);
		}
			if (mState != EState::eClear)
			{
				/*if (mState == EState::eSquat)
				{*/
				if (mState != EState::eDown && mState != EState::eBadDown || mIsGrounded != true)
				{
					if (other->Layer() == ELayer::eObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;

						if (other->Tag() == ETag::eRideableObject)
						{
							mpRideObject = other->Owner();
						}
					}
					if (other->Layer() == ELayer::eMoveObject)
					{
						Position(Position() + hit.adjust * hit.weight);
					}
					if (other->Layer() == ELayer::eBadObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
						{
							ChangeState(EState::eBadDown);
						}
					}
					if (other->Layer() == ELayer::eBigBadObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						/*if (mState != EState::eBadDown && mState != EState::eUp && mState != EState::eDown)
						{*/
						ChangeState(EState::eBadDown);
						//}
					}
					//岩
					if (other->Layer() == ELayer::eStone)
					{
						mMoveSpeed.Y(-0.2f);
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
						{*/
						ChangeState(EState::eBadDown);
						//}
					}
				}
				//}
			}
	}

	//足の判定
	if (self == mpColliderLineLeg || self == mpColliderLineLeg2)
	{
		//syougaibutu
		if (CGameManager::StageNo() == 8 && other->Layer() == ELayer::eObject)
		{
			mIceGrounded = true;
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			//ChangeState(EState::eJumpEnd);
		}
		if (mState != EState::eClear)
		{
			if (other->Layer() == ELayer::eObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;

				if (other->Tag() == ETag::eRideableObject)
				{
					mpRideObject = other->Owner();
				}
			}
			if (other->Layer() == ELayer::eMoveObject)
			{
				Position(Position() + hit.adjust * hit.weight);
			}
			//当たると死亡
			if (other->Layer() == ELayer::eDead)
			{
				/*Position(Position() + hit.adjust * hit.weight);*/
				//ChangeState(EState::eDead);
			}
			if (other->Layer() == ELayer::eBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					ChangeState(EState::eBadDown);
				}
			}
			if (other->Layer() == ELayer::eBigBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*if (mState != EState::eDown && mState != EState::eBadDown && mState != EState::eUp)
				{*/
				ChangeState(EState::eBadDown);
				//}
			}
			//岩
			if (other->Layer() == ELayer::eStone)
			{
				mMoveSpeed.Y(-0.2f);
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
			/*	if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
				ChangeState(EState::eBadDown);
				//}
			}
		}
	}

	//膝の判定
	if (self == mpColliderLineLegHalf || self == mpColliderLineLegHalf2)
	{
		//syougaibutu
		if (CGameManager::StageNo() == 8 && other->Layer() == ELayer::eObject)
		{
			mIceGrounded = true;
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			//ChangeState(EState::eJumpEnd);
		}
		if (mState != EState::eClear)
		{
			if (mState == EState::eBadDown || mState == EState::eDown)
			{
				if (other->Layer() == ELayer::eObject)
				{
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;

					if (other->Tag() == ETag::eRideableObject)
					{
						mpRideObject = other->Owner();
					}
				}
				if (other->Layer() == ELayer::eMoveObject)
				{
					Position(Position() + hit.adjust * hit.weight);
				}
				if (other->Layer() == ELayer::eBadObject)
				{
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;
					if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
					{
						ChangeState(EState::eBadDown);
					}
				}
				if (other->Layer() == ELayer::eBigBadObject)
				{
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;
					/*if (mState != EState::eDown && mState != EState::eBadDown && mState != EState::eUp)
					{*/
					ChangeState(EState::eBadDown);
					//}
				}
				//岩
				if (other->Layer() == ELayer::eStone)
				{
					mMoveSpeed.Y(-0.2f);
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;
					/*	if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
						{*/
					ChangeState(EState::eBadDown);
					//}
				}
			}
		}
	}
	
	//頭の判定
	if (self == mpColliderLineHead || self == mpColliderLineHead2)
	{
		//syougaibutu
		if (CGameManager::StageNo() == 8 && other->Layer() == ELayer::eObject)
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mIceGrounded = true;
			mCollisioncheck = true;
			//ChangeState(EState::eJumpEnd);
		}
			if (mState != EState::eClear)
			{
				if (mState != EState::eSquat && mState != EState::eDown && mState != EState::eBadDown && mState != EState::eUp || mIsGrounded != true)
				{
					if (other->Layer() == ELayer::eObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						if (other->Tag() == ETag::eRideableObject)
						{
							mpRideObject = other->Owner();
						}
					}
					if (other->Layer() == ELayer::eMoveObject)
					{
						Position(Position() + hit.adjust * hit.weight);
					}
					if (other->Layer() == ELayer::eBadObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
						{
							ChangeState(EState::eBadDown);
						}
					}
					if (other->Layer() == ELayer::eBigBadObject)
					{
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						ChangeState(EState::eBadDown);
					}
					//岩
					if (other->Layer() == ELayer::eStone)
					{
						mMoveSpeed.Y(-0.2f);
						Position(Position() + hit.adjust * hit.weight);
						//mIsGrounded = true;
						ChangeState(EState::eBadDown);
					}
				}
			}
	}
}

// 描画
void CPlayer::Render()
{
	CXCharacter::Render();
}

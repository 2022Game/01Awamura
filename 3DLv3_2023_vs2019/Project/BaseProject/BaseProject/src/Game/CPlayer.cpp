//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
#include "CInput.h"
#include "CCamera.h"
#include "CField.h"
#include "CGameManager.h"
#include "CDisappearFloor.h"

// �v���C���[�̃C���X�^���X
CPlayer* CPlayer::spInstance = nullptr;


bool CPlayer::mSwitchRObject = false;
bool CPlayer::mSwitchLObject = false;
bool CPlayer::mResetCount = false;
bool CPlayer::mDownSwitch = false;

// �v���C���[�̃A�j���[�V�����f�[�^�̃e�[�u��
const CPlayer::AnimData CPlayer::ANIM_DATA[] =
{
	{ "Character\\Player\\Normalidol.x",true,	277.0f	},	// T�|�[�Y
	//{ "Character\\Player\\SuperJump.x",true,	160.0f	},	// ��
	{ "Character\\Player\\slowrun.x",		true,	35.0f	},	//����
	{ "Character\\Player\\jumpUp.x",		false,	8.0f	},	// �W�����v�J�n
	{ "Character\\Player\\jumpDown2.x",		false,	25.0f	},	// �W�����v������
	{ "Character\\Player\\jumpDown3.x",		false,	26.0f	},	// �W�����v���n
	//{ "Character\\Player\\run.x",		true,	40.0f	},	// ����
	{ "Character\\Player\\jumpN.x",		false,	1.0f	},	// ��
	{ "Character\\Player\\Down.x",		false,	60.0f	},	// �|���
	{ "Character\\Player\\Up.x",		false,	60.0f	},	// �N���オ��
	{ "Character\\Player\\Clear.x",		false,	90.0f	}, //�N���A
	{ "Character\\Player\\Squat.x",		false,	22.5f	}, //���Ⴊ��
	{ "Character\\Player\\SquatUp.x",		false,	22.0f	}, //���Ⴊ�݉���
};

#define PLAYER_HEIGHT 1.8f
#define MOVE_SPEED 0.375f
#define JUMP_SPEED 1.5f
#define GRAVITY 0.0625f
#define JUMP_END_Y 1.0f

// �R���X�g���N�^
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
	//�C���X�^���X�̐ݒ�
	spInstance = this;
	Position(0.0f,30.0f,0.0f);
	mStartPos = Position();



	// ���f���f�[�^�ǂݍ���
	CModelX* model = CResourceManager::Get<CModelX>("Player");

	Scale(10.0f, 10.0f, 10.0f);


	// �e�[�u�����̃A�j���[�V�����f�[�^��ǂݍ���
	int size = ARRAY_SIZE(ANIM_DATA);
	for (int i = 0; i < size; i++)
	{
		const AnimData& data = ANIM_DATA[i];
		if (data.path.empty()) continue;
		model->AddAnimationSet(data.path.c_str());
	}
	// CXCharacter�̏�����
	Init(model);

	// �ŏ��͑ҋ@�A�j���[�V�������Đ�
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

// �A�j���[�V�����؂�ւ�
void CPlayer::ChangeAnimation(EAnimType type)
{
	if (!(EAnimType::None < type && type < EAnimType::Num)) return;
	AnimData data = ANIM_DATA[(int)type];
	CXCharacter::ChangeAnimation((int)type, data.loop, data.frameLength);
}

//��邱�Ƃ��ł���I�u�W�F�N�g���폜���ꂽ���̏���
void CPlayer::DeleteRideableObject(CTransform* rideObj)
{
	//�폜�����̂����ݏ���Ă���I�u�W�F�N�g�ł����
	//����Ă���I�u�W�F�N�g������
	if (mpRideObject == rideObj)
	{
		mpRideObject = nullptr;
	}
}

//�X�e�[�W�J�n���̈ʒu��ݒ�
void CPlayer::SetStartPosition(const CVector& pos)
{
	mStartPos = pos;
	Position(mStartPos);
}

//���݂̏�Ԃ�؂�ւ�
void CPlayer::ChangeState(EState state)
{
	mState = state;
	mStateStep = 0;
}

//�������̏��
void CPlayer::UpdateReady()
{
	//�X�e�b�v���Ƃɏ�����؂�ւ���
	switch (mStateStep)
	{
		//�X�e�b�v�O�@����������
	case 0:
		//�v���C���[�S�Ă̏Փ˔����OFF�ɂ���
		SetEnableCol(false);
		//�v���C���[�̈ړ����x���O�ɂ���
		mMoveSpeed = CVector::zero;
		//���̃X�e�b�v��
		mStateStep++;
		break;
	case 1:
		//�Q�[�����J�n������
		if (CGameManager::GameState() == EGameState::eGame)
		{
			//�v���C���[�̏Փ˔�����I���ɂ���
			SetEnableCol(true);
			//���݂̏�Ԃ�ҋ@�ɐ؂�ւ�
			ChangeState(EState::eIdle);
		}
		break;
	}
}

// �ҋ@
void CPlayer::UpdateIdle()
{
	mMoveSpeed.X(0.0f);
	mMoveSpeed.Z(0.0f);
	//CXCharacter::ChangeAnimation(0, true, 1.0f);

	if (mIsGrounded)
	{
		// �ړ�����
		// �L�[�̓��̓x�N�g�����擾
		CVector input;
		if (CGameManager::StageNo() != 8)
		{
			if (CInput::Key('W'))	     input.Z(-2.0f);
			else if (CInput::Key('S'))   input.Z(2.0f);
			if (CInput::Key('A'))		 input.X(-2.0f);
			else if (CInput::Key('D'))	 input.X(2.0f);
		}

		//�X�e�[�W8�̏��
		if (CGameManager::StageNo() == 8)
		{
			//�ǂɃS���S�����Ȃ��悤�ɂ���
			if (mIceGrounded != false && mCollisioncheck == true)
			{
				if (CInput::Key('W') && mIceUp != true)	    mIceGrounded = false, mIceUp = true,Box = 1, input.Z(-2.0f);
				else if (CInput::Key('S') && mIceDown != true)  mIceGrounded = false, mIceDown = true,Box = 2, input.Z(2.0f);
				else if (CInput::Key('A') && mIceLeft != true)		mIceGrounded = false, mIceLeft = true,Box = 3, input.X(-2.0f);
				else if (CInput::Key('D') && mIceRight != true)	mIceGrounded = false, mIceRight = true,Box = 4, input.X(2.0f);
			}

			//���펞
			if (mIceGrounded != false && mCollisioncheck == false)
			{
				if (CInput::Key('W'))	    mIceGrounded = false, input.Z(-2.0f);
				else if (CInput::Key('S')) mIceGrounded = false, input.Z(2.0f);
				else if (CInput::Key('A'))		 mIceGrounded = false, input.X(-2.0f);
				else if (CInput::Key('D')) mIceGrounded = false, input.X(2.0f);
			}
		}
		//�ǂɃS���S�����Ȃ��悤�ɂ���
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

		// ���̓x�N�g���̒����œ��͂���Ă��邩����
		if (input.LengthSqr() > 0.0f)
		{
			// �J�����̌����ɍ��킹���ړ��x�N�g���ɕϊ�
			CCamera* mainCamera = CCamera::MainCamera();
			CVector camForward = mainCamera->VectorZ();
			CVector camSide = CVector::Cross(CVector::up, camForward);
			CVector move = camForward * input.Z() + camSide * input.X();
			move.Y(0.0f);
			move.Normalize();

			mMoveSpeed += move * MOVE_SPEED;

			// ���s�A�j���[�V�����ɐ؂�ւ�
			ChangeAnimation(EAnimType::eSlowRun);
		}
		// �ړ��L�[����͂��Ă��Ȃ�
		else
		{
			// �ҋ@�A�j���[�V�����ɐ؂�ւ�
			ChangeAnimation(EAnimType::eIdle);
		}

		// ���N���b�N�ł��Ⴊ�ݏ�Ԃֈڍs
		if (CInput::PushKey(VK_LBUTTON))
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			ChangeState(EState::eSquat);

			CCamera::MainCamera()->Position();
		}
		// SPACE�L�[�ŃW�����v�J�n�ֈڍs
		else if (CInput::PushKey(VK_SPACE))
		{
			ChangeState(EState::eJumpStart);
		}
	}
	else
	{
		//if (mMoveSpeed.Y() <= -0.5f && mMoveSpeed.Y() >-1.0f)
		//{
		//	// �ҋ@�A�j���[�V�����ɐ؂�ւ�
		//	ChangeAnimation(EAnimType::eIdle);
		//}
		
		if (mMoveSpeed.Y() <= -0.2f)
		{
			ChangeState(EState::eJumpN);
		}
	}
}

//�R���C�_�[���s��ɃA�^�b�`����p
//const CAmatrix* bodyMtx = GetFrameMtx("Armature_Body");
//mpAttackCol->SetAttachMtx(bodyMtx);

// �U��
void CPlayer::UpdateAttack()
{
	// �U���A�j���[�V�������J�n
	//ChangeAnimation(EAnimType::eDown);
	// �U���I���҂���Ԃֈڍs
	ChangeState(EState::eAttackWait);
}

// �U���I���҂�
void CPlayer::UpdateAttackWait()
{
	// �U���A�j���[�V�������I��������A
	if (IsAnimationFinished())
	{
		// �ҋ@��Ԃֈڍs
		ChangeState(EState::eIdle);
		ChangeAnimation(EAnimType::eIdle);
	}
}

// �W�����v�J�n
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
	//	// ���̓x�N�g���̒����œ��͂���Ă��邩����
	//	if (input.LengthSqr() > 0.0f)
	//	{
	//		// �J�����̌����ɍ��킹���ړ��x�N�g���ɕϊ�
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

// �W�����v��
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
		// ���̓x�N�g���̒����œ��͂���Ă��邩����
		if (input.LengthSqr() > 0.0f)
		{
			// �J�����̌����ɍ��킹���ړ��x�N�g���ɕϊ�
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

// �W�����v�I��
void CPlayer::UpdateJumpEnd()
{
	if (IsAnimationFinished())
	{
		ChangeState(EState::eIdle);
	}
}

//��
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
		// ���̓x�N�g���̒����œ��͂���Ă��邩����
		if (input.LengthSqr() > 0.0f)
		{
			// �J�����̌����ɍ��킹���ړ��x�N�g���ɕϊ�
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

//�|���
void CPlayer::UpdateDown()
{
	mDownSwitch = true;
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f)
	{
		ChangeState(EState::eUp);
	}
}

//������ѓ|���
void CPlayer::UpdateBadDown()
{
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f && mIsGrounded == true)
	{
		ChangeState(EState::eUp);
	}
}

//�N���オ��
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

//�N���A
void CPlayer::UpdateClear()
{
	// �N���A�A�j���[�V�������J�n
	//ChangeAnimation(EAnimType::eAttack);
	// �N���A�I���҂���Ԃֈڍs
	mMoveSpeed.X(0.0f);
	mMoveSpeed.Z(0.0f);
	ChangeAnimation(EAnimType::eClear);
	if (IsAnimationFinished())
	{
		ChangeState(EState::eClearEnd);
	}
}

//�N���A�I��
void CPlayer::UpdateClearEnd()
{
	//ChangeAnimation(EAnimType::eUp);
	// �N���A�A�j���[�V�������I��������A
	//if (IsAnimationFinished())
	//{
		// �ҋ@��Ԃֈڍs
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
	
	//�X�e�[�W���N���A
	CGameManager::StageClear();

	//�X�e�[�W���N���A������A���̃X�e�[�W�J�n�܂ŏ������̏�ԂɕύX
	ChangeState(EState::eReady);
}

//���Ⴊ��
void CPlayer::UpdateSquat()
{
	ChangeAnimation(EAnimType::eSquat);
	//���Ⴊ�݃{�^�������ł����Ⴊ�ݖ߂�Ɉڍs����
	if (IsAnimationFinished() && CInput::Key(VK_LBUTTON) == false)
	{
		ChangeState(EState::eSquatUp);
	}
}

//���Ⴊ�ݖ߂�
void CPlayer::UpdateSquatUp()
{
	ChangeAnimation(EAnimType::eSquatUp);
	if (IsAnimationFinished())
	{
		ChangeState(EState::eIdle);
	}
}

//���S
void CPlayer::UpdateDead()
{
	Position(mStartPos);
	ChangeState(EState::eDown);
}

//����
void CPlayer::UpdateIce()
{
	ChangeAnimation(EAnimType::eJumpN);
	if (mIceGrounded == true)
	{
		//mCollisioncheck = false;
		ChangeState(EState::eJumpEnd);
	}
}

// �X�V
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
	// ��Ԃɍ��킹�āA�X�V������؂�ւ���
	switch (mState)
	{
		//�������̏��
	    case EState::eReady:
		UpdateReady();
		break;
		// �ҋ@���
		case EState::eIdle:
			UpdateIdle();
			break;
		// �U��
		case EState::eAttack:
			UpdateAttack();
			break;
		// �U���I���҂�
		case EState::eAttackWait:
			UpdateAttackWait();
			break;
		// �W�����v�J�n
		case EState::eJumpStart:
			UpdateJumpStart();
			break;
		// �W�����v��
		case EState::eJump:
			UpdateJump();
			break;
		// �W�����v�I��
		case EState::eJumpEnd:
			UpdateJumpEnd();
			break;
		//�W�����v��
		case EState::eJumpN:
			UpdateJumpN();
			break;
		// �N���A
		case EState::eClear:
			UpdateClear();
			break;
		// �N���A�I��
		case EState::eClearEnd:
			UpdateClearEnd();
			break;
		//�|���
		case EState::eDown:
			UpdateDown();
			break;
		//������ѓ|���
		case EState::eBadDown:
			UpdateDown();
			break;
		//�N���オ��
		case EState::eUp:
			UpdateUp();
			break;
			//���Ⴊ��
		case EState::eSquat:
			UpdateSquat();
			break;
			//���Ⴊ�މ���
		case EState::eSquatUp:
			UpdateSquatUp();
			break;
			//���S
		case EState::eDead:
			UpdateDead();
			break;
			//���鏰
		case EState::eIce:
			UpdateIce();
			break;
	}

	//�������łȂ���Έړ������Ȃǂ��s��
	if (mState != EState::eReady && mState != EState::eClear && mState != EState::eClearEnd )
	{
		//mColliderSpeed = CVector(0.0f, -10.0f, 0.0f);

		if (!CInput::Key(VK_SPACE))
		{
			mMoveSpeed -= CVector(0.0f, GRAVITY, 0.0f);
		}
		// �ړ�
		Position(Position() + mMoveSpeed);

		// �v���C���[���ړ������֌�����
		CVector current = VectorZ();
		CVector target = mMoveSpeed;
		target.Y(0.0f);
		target.Normalize();
		CVector forward = CVector::Slerp(current, target, 0.125f);
		Rotation(CQuaternion::LookRotation(forward));
	}

	// �L�����N�^�[�̍X�V
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

// �Փˏ���
void CPlayer::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderLine)
	{
		//�N���A����R�C�����n����
		if (other->Layer() == ELayer::eClearObject)
		{
			//�ҋ@��ԈȊO
			if (mState != EState::eIdle)
			{
				//�󒆂��璅�n������
				if (mState == EState::eJump || mState == EState::eJumpN)
				{
					//���n���Ɉړ����Ȃ��悤�ɂ���
					mMoveSpeed.X(0.0f);
					mMoveSpeed.Z(0.0f);
					//���n���[�V����
					ChangeAnimation(EAnimType::eJumpDown3);
				}
				//�N���A��ԈȊO�ŃA�j���[�V�������I��������ɃN���A��Ԃɂ���
				if (mState != EState::eReady && mState != EState::eClear && mState != EState::eClearEnd && IsAnimationFinished())
				{
					ChangeState(EState::eClear);
				}
			}
			//�ʏ펞�ɃN���A�y��ɒ�������N���A�ɂ���
			if (mState == EState::eIdle)
			{
				ChangeState(EState::eClear);
			}
		}
		
		//�ҋ@��Ԃ��܂ޒ��n����
		if (other->Layer() == ELayer::eClearObject || other->Layer() == ELayer::eField)
		{
			if (mState == EState::eJump || mState == EState::eJumpN)
			{
				//���n���Ɋ���Ȃ�
				mMoveSpeed.X(0.0f);
				mMoveSpeed.Z(0.0f);
				ChangeAnimation(EAnimType::eJumpDown3);
				ChangeState(EState::eJumpEnd);
			}
		}

		//�t�B�[���h�Ə�Q���ƃN���A�y��̏�ɏ������
		if (other->Layer() == ELayer::eField || other->Layer() == ELayer::eObject || other->Layer() == ELayer::eClearObject)
		{
			//�����Ȃ��悤�ɂ���
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (CGameManager::StageNo() == 8)
			{
				mIceGrounded = true;
			}
			//����y��
			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
				if (mState != EState::eIdle)
				{
					if(mState == EState::eJump || mState == EState::eJumpN)
					{
						//����Ȃ��悤�ɂ���
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
						ChangeAnimation(EAnimType::eJumpDown3);
						ChangeState(EState::eJumpEnd);
					}
					//�_�E���������ɒn�ʂ�����Ȃ��悤�ɂ���
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

		//���鏰
		if (other->Layer() == ELayer::eIceField)
		{
			//�����Ȃ��悤�ɂ���
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			if (mIceGrounded == false)
			{
				ChangeState(EState::eIce);
			}
		}

		//��
		if (other->Layer() == ELayer::eSlopeField)
		{
			//�����Ȃ��悤�ɂ���
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mIsGrounded = true;
			//����y��
			if (other->Tag() == ETag::eRideableObject)
			{
				mpRideObject = other->Owner();
				if (mState != EState::eIdle)
				{
					if (mState == EState::eJump || mState == EState::eJumpN)
					{
						//����Ȃ��悤�ɂ���
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
						ChangeAnimation(EAnimType::eJumpDown3);
						ChangeState(EState::eJumpEnd);
					}
					//�_�E���������ɒn�ʂ�����Ȃ��悤�ɂ���
					if (mState == EState::eDown || mState == EState::eBadDown)
					{
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
					}
				}
			}
		}

		//������Q��
		if (other->Layer() == ELayer::eBadObject)
		{
			if (mState != EState::eSquat && mState != EState::eClear)
			{
				//�����߂����
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				//�󒆂łԂ������Ƃ��Ƀ_�E������
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					ChangeState(EState::eBadDown);
				}
			}
		}
		//�ƂĂ�������Q��
		if (other->Layer() == ELayer::eBigBadObject)
		{
			if (mState != EState::eSquat && mState != EState::eClear)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				//����������DOWN����
				/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
					ChangeState(EState::eBadDown);
				//}
			}
		}
		//���[�v��Q��
		if (other->Layer() == ELayer::eWarpObject)
		{
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			//mIsGrounded = true;
			//�����ɂ�胏�[�v�ʒu��ς���
			//�Q�[���X�e�[�W�P�X�^�[�g
			if (CGameManager::StageNo() == 0)
			{
				//�����X�e�[�W�N���A�Ŏ��̃X�e�[�W��
				CGameManager::StageClear();
				//�X�e�[�W�P�J�n�ʒu�փ��[�v
				Position(mStartPos);
			}
		}
		//��
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

		//������Ǝ��S
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

	//���̔���
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
					//��
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

	//���̔���
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
					//��
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

	//���̔���
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
			//������Ǝ��S
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
			//��
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

	//�G�̔���
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
				//��
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
	
	//���̔���
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
					//��
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

// �`��
void CPlayer::Render()
{
	CXCharacter::Render();
}

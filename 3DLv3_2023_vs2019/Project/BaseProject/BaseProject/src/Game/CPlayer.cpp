//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
#include "CInput.h"
#include "CCamera.h"
#include "CField.h"

// �v���C���[�̃C���X�^���X
CPlayer* CPlayer::spInstance = nullptr;

// �v���C���[�̃��f���f�[�^�̃p�X
#define MODEL_PATH "Character\\Player\\Beardman.x"

bool CPlayer::mSwitchRObject = false;
bool CPlayer::mSwitchLObject = false;
bool CPlayer::mResetCount = false;

// �v���C���[�̃A�j���[�V�����f�[�^�̃e�[�u��
const CPlayer::AnimData CPlayer::ANIM_DATA[] =
{
	{ "Character\\Player\\Normalidol.x",true,	554.0f	},	// T�|�[�Y
	//{ "Character\\Player\\SuperJump.x",true,	160.0f	},	// ��
	{ "Character\\Player\\slowrun.x",		true,	44.0f	},	//����
	{ "Character\\Player\\jumpUp.x",		false,	8.0f	},	// �W�����v�J�n
	{ "Character\\Player\\jumpDown2.x",		false,	35.0f	},	// �W�����v������
	{ "Character\\Player\\jumpDown3.x",		false,	38.0f	},	// �W�����v���n
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
	, mDowncount(180)
{
	//�C���X�^���X�̐ݒ�
	spInstance = this;
	Position(0.0f,30.0f,0.0f);
	mStartPos = Position();

	// ���f���f�[�^�ǂݍ���
	CModelX* model = new CModelX();
	model->Load(MODEL_PATH);

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
		ELayer::eSlopeField,ELayer::eStone,ELayer::eMoveRSwitch,ELayer::eMoveLSwitch});
	mpColliderLineBody->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject,ELayer::eStone });
	mpColliderLineLeg->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject,ELayer::eSlopeField });
	mpColliderLineHead->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject });
	mpColliderLineBody2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject });
	mpColliderLineLeg2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject,ELayer::eSlopeField });
	mpColliderLineHead2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject });
	mpColliderLineBodyHalf->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject,ELayer::eStone });
	mpColliderLineLegHalf->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject,ELayer::eSlopeField });
	mpColliderLineBodyHalf2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject });
	mpColliderLineLegHalf2->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eStone,ELayer::eBigBadObject,ELayer::eSlopeField });
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

// �A�j���[�V�����؂�ւ�
void CPlayer::ChangeAnimation(EAnimType type)
{
	if (!(EAnimType::None < type && type < EAnimType::Num)) return;
	AnimData data = ANIM_DATA[(int)type];
	CXCharacter::ChangeAnimation((int)type, data.loop, data.frameLength);
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
		if (CInput::Key('W'))		input.Z(-2.0f);
		else if (CInput::Key('S'))	input.Z(2.0f);
		if (CInput::Key('A'))		input.X(-2.0f);
		else if (CInput::Key('D'))	input.X(2.0f);

		// ���̓x�N�g���̒����œ��͂���Ă��邩����
		if (input.LengthSqr() > 0.0f)
		{
			// �J�����̌����ɍ��킹���ړ��x�N�g���ɕϊ�
			CVector move = CCamera::MainCamera()->Rotation() * input;
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

		// ���N���b�N�ōU����Ԃֈڍs
		if (CInput::PushKey(VK_LBUTTON))
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mState = EState::eSquat;

			CCamera::MainCamera()->Position();
		}
		// SPACE�L�[�ŃW�����v�J�n�ֈڍs
		else if (CInput::PushKey(VK_SPACE))
		{
			mState = EState::eJumpStart;
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
			mState = EState::eJumpN;
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
	mState = EState::eAttackWait;
}

// �U���I���҂�
void CPlayer::UpdateAttackWait()
{
	// �U���A�j���[�V�������I��������A
	if (IsAnimationFinished())
	{
		// �ҋ@��Ԃֈڍs
		mState = EState::eIdle;
		ChangeAnimation(EAnimType::eIdle);
	}
}

// �W�����v�J�n
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

// �W�����v��
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

// �W�����v�I��
void CPlayer::UpdateJumpEnd()
{
	if (IsAnimationFinished())
	{
		mState = EState::eIdle;
	}
}

//��
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

//�|���
void CPlayer::UpdateDown()
{
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f)
	{
		mState = EState::eUp;
	}
}

//������ѓ|���
void CPlayer::UpdateBadDown()
{
	ChangeAnimation(EAnimType::eDown);
	if (IsAnimationFinished() && mMoveSpeed.Y() >= 0.0f && mIsGrounded == true)
	{
		mState = EState::eUp;
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
		mState = EState::eIdle;
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
		mState = EState::eClearEnd;
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
		CField::mClearCountSwitch = 1;
		CField::mStageCreateSwitch = 1;
		CField::mClearCount = 1;
		CField::mStageCount++;
		//CField::mDeleteSwitch = 1;
		//ChangeAnimation(EAnimType::eIdle);
		if (CField::mStageCount == 3)
		{
			Position(0.0f, 30.0f, 240.0f);
		}
		if(CField::mStageCount != 3)
		{
			Position(mStartPos);
		}
		mState = EState::eIdle;
//	}
}

//���Ⴊ��
void CPlayer::UpdateSquat()
{
	ChangeAnimation(EAnimType::eSquat);
	//���Ⴊ�݃{�^�������ł����Ⴊ�ݖ߂�Ɉڍs����
	if (IsAnimationFinished() && CInput::Key(VK_LBUTTON) == false)
	{
		mState = EState::eSquatUp;
	}
}

//���Ⴊ�ݖ߂�
void CPlayer::UpdateSquatUp()
{
	ChangeAnimation(EAnimType::eSquatUp);
	if (IsAnimationFinished())
	{
		mState = EState::eIdle;
	}
}

// �X�V
void CPlayer::Update()
{
	if (mResetCount == true)
	{
		mResetCount = false;
	}

	SetParent(mpRideObject);
	mpRideObject = nullptr;

	if (mMoveSpeed.Y() < 0.0f )
	{
		mDowncount--;
		if (mDowncount < 0)
		{
			if (CField::mStageCount == 3)
			{
				Position(0.0f, 30.0f, 240.0f);
			}
			else if(CField::mStageCount != 3)
			{
				Position(mStartPos);
			}
			mDowncount = 180;
			mMoveSpeed.Y(-0.1f);
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mResetCount = true;
			mState = EState::eDown;
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
	}

	//mColliderSpeed = CVector(0.0f, -10.0f, 0.0f);

	mMoveSpeed -= CVector(0.0f, GRAVITY, 0.0f);

	// �ړ�
	Position(Position() + mMoveSpeed);

	// �v���C���[���ړ������֌�����
	CVector current = VectorZ();
	CVector target = mMoveSpeed;
	target.Y(0.0f);
	target.Normalize();
	CVector forward = CVector::Slerp(current, target, 0.125f);
	Rotation(CQuaternion::LookRotation(forward));

	// �L�����N�^�[�̍X�V
	CXCharacter::Update();
	mSwitchRObject = false;
	mSwitchLObject = false;
	mIsGrounded = false;
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
				if (mState != EState::eClear && mState != EState::eClearEnd && IsAnimationFinished())
				{
					mState = EState::eClear;
				}
			}
			//�ʏ펞�ɃN���A�y��ɒ�������N���A�ɂ���
			if (mState == EState::eIdle)
			{
				mState = EState::eClear;
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
				mState = EState::eJumpEnd;
			}
		}

		//�t�B�[���h�Ə�Q���ƃN���A�y��̏�ɏ������
		if (other->Layer() == ELayer::eField || other->Layer() == ELayer::eObject || other->Layer() == ELayer::eClearObject)
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
					if(mState == EState::eJump || mState == EState::eJumpN)
					{
						//����Ȃ��悤�ɂ���
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
						ChangeAnimation(EAnimType::eJumpDown3);
						mState = EState::eJumpEnd;
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
						mState = EState::eJumpEnd;
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
			if (mState != EState::eSquat)
			{
				//�����߂����
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				//�󒆂łԂ������Ƃ��Ƀ_�E������
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					mState = EState::eBadDown;
				}
			}
		}
		//�ƂĂ�������Q��
		if (other->Layer() == ELayer::eBigBadObject)
		{
			if (mState != EState::eSquat)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				//����������DOWN����
				/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
					mState = EState::eBadDown;
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
			if (CField::mStageCount == 0)
			{
				CField::mClearCount = 1;
				CField::mClearCountSwitch = 1;
				CField::mStageCreateSwitch = 1;
				//���K
				//CField::mStageCount = 1;
				//�e�X�g�p
				CField::mStageCount = 4;
				//�X�e�[�W�P�J�n�ʒu�փ��[�v
				Position(mStartPos);
			}
		}
		//��
		if (other->Layer() == ELayer::eStone)
		{
			if (mState != EState::eSquat)
			{
				mMoveSpeed.Y(0.0f);
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
					mState = EState::eBadDown;
				//}
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

	//���̔���
	if (self == mpColliderLineBody || self == mpColliderLineBody2)
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
			if (other->Layer() == ELayer::eBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					mState = EState::eBadDown;
				}
			}
			if (other->Layer() == ELayer::eBigBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*if (mState != EState::eBadDown && mState != EState::eUp && mState != EState::eDown)
				{*/
				mState = EState::eBadDown;
				//}
			}
			//��
			if (other->Layer() == ELayer::eStone)
			{
				mMoveSpeed.Y(0.0f);
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
				{*/
				mState = EState::eBadDown;
				//}
			}
		}
	}

	//���̔���
	if (self == mpColliderLineBodyHalf || self == mpColliderLineBodyHalf2)
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
				if (other->Layer() == ELayer::eBadObject)
				{
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;
					if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
					{
						mState = EState::eBadDown;
					}
				}
				if (other->Layer() == ELayer::eBigBadObject)
				{
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;
					/*if (mState != EState::eBadDown && mState != EState::eUp && mState != EState::eDown)
					{*/
					mState = EState::eBadDown;
					//}
				}
				//��
				if (other->Layer() == ELayer::eStone)
				{
					mMoveSpeed.Y(0.0f);
					Position(Position() + hit.adjust * hit.weight);
					//mIsGrounded = true;
					/*if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
					{*/
					mState = EState::eBadDown;
					//}
				}
			}
		//}
	}

	//���̔���
	if (self == mpColliderLineLeg || self == mpColliderLineLeg2)
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
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			//mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
			{
				mState = EState::eBadDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust * hit.weight);
			//mIsGrounded = true;
			/*if (mState != EState::eDown && mState != EState::eBadDown && mState != EState::eUp)
			{*/
				mState = EState::eBadDown;
			//}
		}
		//��
		if (other->Layer() == ELayer::eStone)
		{
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			//mIsGrounded = true;
		/*	if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
			{*/
				mState = EState::eBadDown;
			//}
		}
	}

	//�G�̔���
	if (self == mpColliderLineLegHalf || self == mpColliderLineLegHalf2)
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
			if (other->Layer() == ELayer::eBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					mState = EState::eBadDown;
				}
			}
			if (other->Layer() == ELayer::eBigBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*if (mState != EState::eDown && mState != EState::eBadDown && mState != EState::eUp)
				{*/
				mState = EState::eBadDown;
				//}
			}
			//��
			if (other->Layer() == ELayer::eStone)
			{
				mMoveSpeed.Y(0.0f);
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				/*	if (mState != EState::eBadDown && mState != EState::eDown && mState != EState::eUp)
					{*/
				mState = EState::eBadDown;
				//}
			}
		}
	}
	
	//���̔���
	if (self == mpColliderLineHead || self == mpColliderLineHead2)
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
			if (other->Layer() == ELayer::eBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump)
				{
					mState = EState::eBadDown;
				}
			}
			if (other->Layer() == ELayer::eBigBadObject)
			{
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				mState = EState::eBadDown;
			}
			//��
			if (other->Layer() == ELayer::eStone)
			{
				mMoveSpeed.Y(0.0f);
				Position(Position() + hit.adjust * hit.weight);
				//mIsGrounded = true;
				mState = EState::eBadDown;
			}
		}
	}
}

// �`��
void CPlayer::Render()
{
	CXCharacter::Render();
}

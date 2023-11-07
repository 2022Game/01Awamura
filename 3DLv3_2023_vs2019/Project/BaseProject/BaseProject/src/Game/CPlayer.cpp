//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
#include "CInput.h"
#include "CCamera.h"
#include "CField.h"

// �v���C���[�̃C���X�^���X
CPlayer* CPlayer::spInstance = nullptr;

// �v���C���[�̃��f���f�[�^�̃p�X
#define MODEL_PATH "Character\\Player\\Beardman.x"

// �v���C���[�̃A�j���[�V�����f�[�^�̃e�[�u��
const CPlayer::AnimData CPlayer::ANIM_DATA[] =
{
	{ "Character\\Player\\Normalidol.x",true,	554.0f	},	// T�|�[�Y
	{ "Character\\Player\\SuperJump.x",true,	160.0f	},	// T�|�[�Y
	{ "Character\\Player\\slowrun.x",		true,	44.0f	},	// �ҋ@
	{ "Character\\Player\\jumpUp.x",		true,	30.0f	},	// �W�����v�J�n
	{ "Character\\Player\\jumpDown2.x",		true,	35.0f	},	// �W�����v������
	{ "Character\\Player\\jumpDown3.x",		true,	38.0f	},	// �W�����v���n
	{ "Character\\Player\\run.x",		true,	40.0f	},	// ����
	{ "Character\\Player\\jumpN.x",		true,	1.0f	},	// ������
	{ "Character\\Player\\Down.x",		true,	150.0f	},	// ������
	{ "Character\\Player\\Up.x",		true,	110.0f	},	// ������
};

#define PLAYER_HEIGHT 1.6f
#define MOVE_SPEED 0.375f
#define JUMP_SPEED 1.5f
#define GRAVITY 0.0625f
#define JUMP_END_Y 1.0f

// �R���X�g���N�^
CPlayer::CPlayer()
	: CXCharacter(ETag::ePlayer, ETaskPriority::ePlayer)
	, mState(EState::eIdle)
	, mpRideObject(nullptr)
	, Downcount(180)
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
		CVector(0.0f, PLAYER_HEIGHT / 2, -0.4f)
	);
	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::eField,
		CVector(PLAYER_HEIGHT / 4, 0.1f, 0.0f),
		CVector(-PLAYER_HEIGHT / 4, 0.1f, 0.0f)
	);

	mpColliderLineLeg = new CColliderLine
	(
		this, ELayer::eField,
		CVector(0.0f, 0.1f, PLAYER_HEIGHT / 4),
		CVector(0.0f, 0.1f, -0.4f)
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
		CVector(0.0f, PLAYER_HEIGHT, -0.4f)
	);
	/*mpColliderSphere = new CColliderSphere
	(
		this, ELayer::ePlayerSpher,1.0f,CVector(0.0f, PLAYER_HEIGHT, PLAYER_HEIGHT / 4),
		CVector(0.0f, PLAYER_HEIGHT, -0.4f)
	);*/
	/*mpColliderSphere->SetCollisionLayers({});*/
	mpColliderLine->SetCollisionLayers({ ELayer::eField,ELayer::eClearObject,ELayer::eObject});
	mpColliderLineBody->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject});
	mpColliderLineLeg->SetCollisionLayers({ ELayer::eField,ELayer::eObject,ELayer::eBadObject,ELayer::eBigBadObject });
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

// �A�j���[�V�����؂�ւ�
void CPlayer::ChangeAnimation(EAnimType type)
{
	/*if (!(EAnimType::None < type && type < EAnimType::Num)) return;
	AnimData data = ANIM_DATA[(int)type];
	CXCharacter::ChangeAnimation((int)type, data.loop, data.frameLength);*/
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
		if (CInput::Key('W'))		input.Z(2.0f);
		else if (CInput::Key('S'))	input.Z(-2.0f);
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
			CXCharacter::ChangeAnimation(2, true, 44.0f);
		}
		// �ړ��L�[����͂��Ă��Ȃ�
		else
		{
			// �ҋ@�A�j���[�V�����ɐ؂�ւ�
			CXCharacter::ChangeAnimation(0, true, 544.0f);
		}

		// ���N���b�N�ōU����Ԃֈڍs
		if (CInput::PushKey(VK_LBUTTON))
		{
			mMoveSpeed.X(0.0f);
			mMoveSpeed.Z(0.0f);
			mState = EState::eDown;
		}
		// SPACE�L�[�ŃW�����v�J�n�ֈڍs
		else if (CInput::PushKey(VK_SPACE))
		{
			mState = EState::eJumpStart;
		}
	}
	else
	{
		// �ҋ@�A�j���[�V�����ɐ؂�ւ�
		CXCharacter::ChangeAnimation(0, true, 544.0f);
		if (mMoveSpeed.Y() <= 0.0f)
		{
			mState = EState::eJumpN;
		}
	}
}

// �U��
void CPlayer::UpdateAttack()
{
	// �U���A�j���[�V�������J�n
	ChangeAnimation(EAnimType::eAttack);
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
	CXCharacter::ChangeAnimation(3, true, 10.0f);
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
	CXCharacter::ChangeAnimation(4, false, 40.0f);
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
	CXCharacter::ChangeAnimation(7, false, 1.0f);
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
	CXCharacter::ChangeAnimation(8, false, 60.0f);
	if (IsAnimationFinished())
	{
		mState = EState::eUp;
	}
}

//�N���オ��
void CPlayer::UpdateUp()
{
	mMoveSpeed.X(0.0f);
	mMoveSpeed.Z(0.0f);
	CXCharacter::ChangeAnimation(9, false, 40.0f);
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
	CXCharacter::ChangeAnimation(8, true, 60.0f);
	if (IsAnimationFinished())
	{
		mState = EState::eClearEnd;
	}
}

//�N���A�I��
void CPlayer::UpdateClearEnd()
{
	CXCharacter::ChangeAnimation(9, true, 40.0f);
	// �N���A�A�j���[�V�������I��������A
	if (IsAnimationFinished())
	{
		// �ҋ@��Ԃֈڍs
		CField::mClearCountSwitch = 1;
		CField::mStageCreateSwitch = 1;
		CField::mClearCount = 1;
		//ChangeAnimation(EAnimType::eIdle);
		Position(mStartPos);
		mState = EState::eIdle;
	}
}

// �X�V
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
		//�N���オ��
		case EState::eUp:
			UpdateUp();
			break;
	}

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

	mIsGrounded = false;
}

// �Փˏ���
void CPlayer::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderLine)
	{
		if (other->Layer() == ELayer::eClearObject)
		{
			if (mState != EState::eIdle)
			{
				if (mState == EState::eJump || mState == EState::eJumpN)
				{
					//Downcount = 180;
					mMoveSpeed.X(0.0f);
					mMoveSpeed.Z(0.0f);
					CXCharacter::ChangeAnimation(5, true, 38.0f);
				}
				if (mState != EState::eClear && mState != EState::eClearEnd && IsAnimationFinished())
				{
					mState = EState::eClear;
				}
			}
			if (mState == EState::eIdle)
			{
				mState = EState::eClear;
			}
		}
		//else if (CField::mClearCountSwitch = 0);
		if (other->Layer() == ELayer::eClearObject || other->Layer() == ELayer::eField)
		{
			if (mState == EState::eJump || mState == EState::eJumpN)
			{
				//Downcount = 180;
				mMoveSpeed.X(0.0f);
				mMoveSpeed.Z(0.0f);
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
					if(mState == EState::eJump || mState == EState::eJumpN)
					{
						//Downcount = 180;
						mMoveSpeed.X(0.0f);
						mMoveSpeed.Z(0.0f);
						CXCharacter::ChangeAnimation(5, true, 38.0f);
						mState = EState::eJumpEnd;
					}
				}
			}
		}
	}

	if (self == mpColliderLine)
	{
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump || mState != EState::eDown)
			{
				mState = EState::eDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			mMoveSpeed.X(mMoveSpeed.X() * -1.0f);
			mMoveSpeed.Z(mMoveSpeed.Z() * -1.0f);
			Position(Position() + hit.adjust);
			mIsGrounded = true;
			if (mState != EState::eDown)
			{
				mState = EState::eDown;
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
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump || mState != EState::eDown)
			{
				mState = EState::eDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust);
			mMoveSpeed.X(mMoveSpeed.X() * -1.0f);
			mMoveSpeed.Z(mMoveSpeed.Z() * -1.0f);
			mIsGrounded = true;
			if (mState != EState::eDown)
			{
				mState = EState::eDown;
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
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump || mState != EState::eDown)
			{
				mState = EState::eDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust);
			mMoveSpeed.X(mMoveSpeed.X() * -1.0f);
			mMoveSpeed.Z(mMoveSpeed.Z() * -1.0f);
			mIsGrounded = true;
			if (mState != EState::eDown)
			{
				mState = EState::eDown;
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
		if (other->Layer() == ELayer::eBadObject)
		{
			Position(Position() + hit.adjust);
			mIsGrounded = true;
			if (mState == EState::eJumpN || mState == EState::eJumpStart || mState == EState::eJump || mState != EState::eDown)
			{
				mState = EState::eDown;
			}
		}
		if (other->Layer() == ELayer::eBigBadObject)
		{
			Position(Position() + hit.adjust);
			mMoveSpeed.X(mMoveSpeed.X() * -1.0f);
			mMoveSpeed.Z(mMoveSpeed.Z() * -1.0f);
			mIsGrounded = true;
			if (mState != EState::eDown)
			{
				mState = EState::eDown;
			}
		}
	}
}

// �`��
void CPlayer::Render()
{
	CXCharacter::Render();
}

//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"

#include "CTaskManager.h"
#include "CApplication.h"
#include "CCollisionManager.h"

#include <stdlib.h>

#include "time.h"

#define ROTATION_YV CVector(0.0f,1.0f,0.0f) //��]���x
#define VELOCITY CVector(0.0f,0.0f,0.1f) //�ړ����x
#define VELOCITY1 CVector(0.0f,0.1f,0.0f) //�ړ����x
#define VELOCITY2 CVector(0.0f,0.05f,0.0f) //�ړ����x
#define VELOCITY3 CVector(0.0f,0.2f,0.0f) //�ړ���
#define ROTATION_XV CVector(1.0f,0.0f,0.0f) //��]���x
#define VELOCITY4 CVector(0.0f,0.01f,0.0f) //�ړ���
#define VELOCITY10 CVector(0.01f,0.0f,0.0f)

int rand(void);
void srand(unsigned int seed);

//CPlayer(�ʒu�A��]�A�X�P�[���j
CPlayer::CPlayer(const CVector& pos, const CVector& rot, const CVector& scale)
	:CPlayer()
{
	mLastPos = pos;
	mStartPos = pos;
	CTransform::Update(pos, rot, scale);//�s��̍X�V
}

int CPlayer::CountLine = 0;

int CPlayer::CountCraft = 0;

CPlayer::CPlayer()
:CCharacter3((int)TaskPriority::ePlayer)
, mLine(this,&Matrix(),CVector(0.0f,0.0f,0.0f),CVector(0.0f,2.0f,0.0f))
, mLine2(this, &Matrix(), CVector(-0.5f, 1.2f, 0.0f), CVector(0.5f, 1.2f, 0.0f))
, mLine3(this, &Matrix(), CVector(0.0f, 1.0f, -0.5f), CVector(0.0f, 1.0f, 0.5f))
,mGroundedMoveObjTf(nullptr)
,mIsGrounded(false)
, jc(0)
, n(0)
,jswitch(0)
,randdd(0)
,randddco(0)
,mTime(0)
,mRestart(1)
,ddStage(0)
,ccStage(0)
{
	srand((unsigned int)time(NULL));
	//�C���X�^���X�̐ݒ�
	spInstance = this;
	randdd = 0;
	randddco = 180;
	mpModel = new CModel();
	mpModel->Load("res\\Beard_man.obj", "res\\Beard_man.mtl");
}

//�X�V����
void CPlayer::Update() {
	
	if (mTime >= 1000)
	{
		mState = EState::EOVER;
	}

	CTransform::Update();
	//�ڒn���Ă��鎞�ɃW�����v�\
	if (mIsGrounded)
	{
		//���㖳���W�����v���p
		if (jswitch == 0)
		{
			if (mInput.Key(VK_SPACE))
			{
				mState = EState::EJUMP;
				jc = 60;
				jswitch = 30;
			}
		}
	}
	//�W�����v���͉��~���邽�߂ɃJ�E���g��������
	if (jc > 0)
	{
		jc--;
		//���㖳���W�����v���p
		if (jswitch != 0)
		{
			jswitch--;
		}
	}
	//�W�����v�����~���n�߂鎞��
	if (jc < 35)
	{
		Position(Position() - VELOCITY3 * MatrixRotate());
	}
	//�W�����v�J�n���㏸����
	if (jc > 40 && jc <= 60)
	{
		Position(Position() + VELOCITY1 * MatrixRotate());
	}
	if (jc > 35 && jc <= 40)
	{
		Position(Position() + VELOCITY2 * MatrixRotate());
	}
	
	if (mInput.Key('O')) {
		//Y���̉�]�l������
		jc = 60;
	}


	//D�L�[���͂ŉ�]
	if (mInput.Key(VK_RIGHT) || mInput.Key('D')) {
		//Y���̉�]�l������
		Rotation(Rotation() - ROTATION_YV);
	}
	if (mInput.Key(VK_LEFT) || mInput.Key('A') ){
		//Y���̉�]�l�𑝂�����
		Rotation(Rotation() + ROTATION_YV);
	}
	//��L�[���͂őO�i
	if (mInput.Key(VK_UP) || mInput.Key('W')) {
		//Z�������̒l����]�����ړ�������nais
		Position(Position() + VELOCITY * MatrixRotate());
	}
	if (mInput.Key(VK_DOWN) || mInput.Key('S')) {
		//Z�������̒l����]�����ړ�������masi
		Position(Position() - VELOCITY * MatrixRotate());
	}
	//�ϊ��s��̍X�V
	CTransform::Update();
	//Ui�ݒ�
	if (CApplication::StageCount != 4) //�e�X�g�p
	{
		if (CApplication::StageTime == 1)
		{
			CApplication::Ui()->Time(mTime++);
		}
	}
	if (CApplication::StageCount == 4) //�e�X�g�p
	{
		CApplication::StageTime = 0;
		mTime = 0;
		mRestart = 0;
	}
	if (CApplication::Rcount == 1)
	{
		Position(mStartPos);
		CApplication::Rcount = 0;
	}
	CApplication::Ui()->PosY(Position().Y());
	CApplication::Ui()->RotX(Rotation().X());
	CApplication::Ui()->RotY(Rotation().Y());
}

//�X�e�[�W�N���A�p�̃I�u�W�F�N�g�ɐڒn���̏���
void CPlayer::GroundedClearObj()
{
	mLastPos = Position() + (CVector(0.0f, 20.0f, 0.0f));
	if (CApplication::StageCountGuard == 0)
	{
		CApplication::StageCountGuard = 1;
	}
	if (CApplication::StageSwitch == 0)
	{
		if (CApplication::StageReset != 1)
		{
			//randddco--; //�e�X�g�p
			//CApplication::StageGuard = 0;
			if (CApplication::StageCount == 0)
			{
				//mLastPos = Position();
				CApplication::SelectStage = 1 + rand() % 5;
				ddStage = CApplication::SelectStage; //��xddStage�ɓ���Ă���
				CApplication::StageSwitch = 1;
				//randddco = 380; //�e�X�g�p
			}
			if (CApplication::StageCount == 1)
			{
				CountLine = 1;
				CountCraft = 1;
				//mLastPos = Position();
				CApplication::SelectStage = 1 + rand() % 5;
				while (CApplication::SelectStage == ddStage)
				{
					CApplication::SelectStage = 1 + rand() % 5;
				}
				ccStage = CApplication::SelectStage; //��xccStage�ɓ���Ă���
				CApplication::StageSwitch = 1;
				//randddco = 580; //�e�X�g�p
			}
			if (CApplication::StageCount == 2)
			{
				CountLine = 2;
				CountCraft = 2;
				//mLastPos = Position();
				CApplication::SelectStage = 5;// 1 + rand() % 5;
				while (ddStage == CApplication::SelectStage ||
					ccStage == CApplication::SelectStage)
				{
					CApplication::SelectStage = 1 + rand() % 5;
				}
				CApplication::StageSwitch = 1;
			}
			if (CApplication::StageCount == 3)
			{
				CApplication::StageCount = 4;
			}
		}
	}
}

//�X�e�[�W�̕ǐ����p�̃I�u�W�F�N�g�ɐڒn�̏���
void CPlayer::GroundedGuardObj()
{
	if (CApplication::StageSwitch == 1)
	{
		CApplication::StageGuard = 1;
		CApplication::StageCount++;
		CApplication::StageClearDelete++;
		CApplication::StageCountGuard = 0;
		CApplication::StageSwitch = 0; //�e�X�g
	}
}


void CPlayer::Collision(CCollider* m, CCollider* o) {
	/*CVector adjust;
	if (CCollider::Collision(m,o,adjust))
	{
		mPosition = mPosition + adjust;
		CTransform::Update();
	}*/
	//���g�̃R���C�_�^�C�v�̔���
	switch (m->Type()) {
	case CCollider::EType::ELINE://�����R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (o->Type() == CCollider::EType::ETRIANGLE) {
			CVector adjust;//�����p�x�N�g��
			//mLastPos = Position() + (CVector(0.0f, 20.0f, 0.0f));
			//�O�p�`�Ɛ����̏Փ˔���
				if (CCollider::CollisionTriangleLine(o, m, &adjust))
				{
					//�ʒu�̍X�V
					Position(Position() + adjust);
					//�Փ˂����̂��A�ړ��I�u�W�F�N�g�ł����
					if (o->Tag() == CCharacter3::ETag::ESTAGECLEAR ||
						o->Tag() == CCharacter3::ETag::ESTAGEGUARD)
					{
						//�Փ˂����ړ��I�u�W�F�N�g��ێ����Ă���
						mGroundedMoveObjTf = o->Parent();
					}

					//�s��̍X�V
					CTransform::Update();

					//�ڒn�t���O��ON
					mIsGrounded = true;

					//�W�����v��ړ����ɐڒn������W�����vOK�ɂ���
					if (mState == EState::EJUMP || mState == EState::EMOVE)
					{
						mState = EState::EJO;
					}

					//�X�e�[�W�̕ǐ����p�̃R���C�_�Ƀq�b�g�����ꍇ
					if (o->Tag() == CCharacter3::ETag::ESTAGEGUARD)
					{
						/*if (mState == EState::EJUMP || mState == EState::EMOVE)
						{
							mState = EState::EJO;
						}*/
						GroundedGuardObj();
					}

					//�X�e�[�W�N���A�p�̃R���C�_�Ƀq�b�g�����ꍇ
					else if (o->Tag() == CCharacter3::ETag::ESTAGECLEAR)
					{
						GroundedClearObj();
					}
					else if (o->Tag() == CCharacter3::ETag::EOBSTACLE)
					{

					}

					if (o->Layer()== CCollider::ELayer::EDEATH)
					{
						Position(mLastPos);
						CApplication::StageReset = 1;
						if (CApplication::StageCountGuard == 0)
						{
							CApplication::StageCount--;
							CApplication::StageClearDelete--;
							CApplication::StageCountGuard = 1;
						}
						if (CApplication::StageCount != 4) { //�e�X�g�p
							CApplication::Ui()->Restart(mRestart++);
						}
					}
					if (mState == EState::EOVER)
					{

					}

					//CCharacter3* parent = o->Parent();
				}
		}
		//����̃R���C�_�����R���C�_�̎�
		else if (o->Type() == CCollider::EType::ESPHERE && o->Layer() 
			!= CCollider::ELayer::ECOIN) {
			CVector adjust;
			if (CCollider::CollisionSphereLine(o, m, &adjust))
			{
				//�ʒu�̍X�V
				Position(Position() + adjust);
				//�s��̍X�V
				CTransform::Update();
			}
		}
		break;
	}
}

//�Փˏ���
void CPlayer::Collision()
{
	//�ڒn���Ă���I�u�W�F�N�g�̃|�C���^��������
	mGroundedMoveObjTf = nullptr;
	mIsGrounded = false;

	//�R���C�_�̗D��x�ύX
	mLine.ChangePriority();
	mLine2.ChangePriority();
	mLine3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mLine, COLLISIONRANGE * 10);
	CCollisionManager::Instance()->Collision(&mLine2, COLLISIONRANGE * 10);
	CCollisionManager::Instance()->Collision(&mLine3, COLLISIONRANGE * 10);

	//�ڒn���Ă���ړ��I�u�W�F�N�g��e�ɐݒ�
	SetParent(mGroundedMoveObjTf);
}

CPlayer* CPlayer::spInstance = nullptr;

CPlayer* CPlayer::Instance()
{
	return spInstance;
}
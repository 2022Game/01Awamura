//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"

#include "CTaskManager.h"
#include "CApplication.h"
#include "CCollisionManager.h"

#define ROTATION_YV CVector(0.0f,1.0f,0.0f) //��]���x
#define VELOCITY CVector(0.0f,0.0f,0.1f) //�ړ����x
#define VELOCITY1 CVector(0.0f,0.2f,0.0f) //�ړ����x
#define VELOCITY2 CVector(0.0f,0.05f,0.0f) //�ړ����x
#define VELOCITY3 CVector(0.0f,0.2f,0.0f) //�ړ���
#define ROTATION_XV CVector(1.0f,0.0f,0.0f) //��]���x
#define VELOCITY4 CVector(0.0f,0.01f,0.0f) //�ړ���

//CPlayer(�ʒu�A��]�A�X�P�[���j
CPlayer::CPlayer(const CVector& pos, const CVector& rot, const CVector& scale)
	: jc(0)
	, n(0)
{
	CTransform::Update(pos, rot, scale);//�s��̍X�V
}

CPlayer::CPlayer()
: mLine(this,&mMatrix,CVector(0.0f,0.0f,0.0f),CVector(0.0f,2.0f,0.0f))
, mLine2(this, &mMatrix, CVector(-0.5f, 1.2f, 0.0f), CVector(0.5f, 1.2f, 0.0f))
, mLine3(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f))
{
	//�C���X�^���X�̐ݒ�
	spInstance = this;
}

//�X�V����
void CPlayer::Update() {
	if (jc > 0)
	{
		jc--;
	}
	if (mState != EState::EJO)
	{
		if (jc < 45)
		{
			mPosition = mPosition - VELOCITY3 * mMatrixRotate;
		}
	}
	if (mState != EState::EJO)
	{
		if (jc > 50 && jc <= 60)
		{
			mPosition = mPosition + VELOCITY1 * mMatrixRotate;
		}
		if (jc > 0 && jc <= 50)
		{
			mPosition = mPosition + VELOCITY2 * mMatrixRotate;
		}
	}
	//D�L�[���͂ŉ�]
	if (mInput.Key(VK_RIGHT) || mInput.Key('D')) {
		//Y���̉�]�l������
		mRotation = mRotation - ROTATION_YV;
	}
	if (mInput.Key(VK_LEFT) || mInput.Key('A') ){
		//Y���̉�]�l�𑝂�����
		mRotation = mRotation + ROTATION_YV;
	}
	//��L�[���͂őO�i
	if (mInput.Key(VK_UP) || mInput.Key('W')) {
		//Z�������̒l����]�����ړ�������nais
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (mInput.Key(VK_DOWN) || mInput.Key('S')) {
		//Z�������̒l����]�����ړ�������masi
		mPosition = mPosition - VELOCITY * mMatrixRotate;;
	}
	//if (mInput.Key(VK_RIGHT)) {
	//	//Z�������̒l����]�����ړ�������
	//	mPosition = mPosition + VELOCITY4;
	//}
	//if (mInput.Key(VK_LEFT)) {
	//	//Z�������̒l����]�����ړ�������
	//	mPosition = mPosition + VELOCITY5;
	//}
	if (mState != EState::EJUMP)
	{
		if (mInput.Key('Q')) 
		{
			mState = EState::EJUMP;
			jc = 60;
		}
	}
	//S�L�[���͂ŉ�����
	//if (mInput.Key('S')) {
	//	//X���̉�]�l�����Z
	//	mRotation = mRotation - ROTATION_XV;
	//}
	//W�L�[���͂ŏ����
	//if (mInput.Key('W')) {
	//	//X���̉�]�l�����Z
	//	mRotation = mRotation + ROTATION_XV;
	//}
	//�X�y�[�X�L�[���͂ŋʔ���
	//if (mInput.Key(VK_SPACE)) {
	//	CBullet* bullet = new CBullet();
 //		bullet->Set(0.1f, 1.5f);
	//	bullet->Position(CVector(0.0f, 0.0f, 10.0f) * mMatrix);
	//	bullet->Rotation(mRotation);
	//	bullet->Update();
	//	//CApplication::TaskManager()->Add(bullet);
	//}
	//�ϊ��s��̍X�V
	CTransform::Update();
	//Ui�ݒ�
	CApplication::Ui()->PosY(mPosition.Y());
	CApplication::Ui()->RotX(mRotation.X());
	CApplication::Ui()->RotY(mRotation.Y());
}

void CPlayer::Collision(CCollider* m, CCollider* o) {
	//���g�̃R���C�_�^�C�v�̔���
	switch (m->Type()) {
	case CCollider::ELINE://�����R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (o->Type() == CCollider::ETRIANGLE) {
			CVector adjust;//�����p�x�N�g��
			//�O�p�`�Ɛ����̏Փ˔���
				if (CCollider::CollisionTriangleLine(o, m, &adjust))
				{
					if (mState == EState::EJUMP || mState == EState::EMOVE)
					{
						mState = EState::EJO;
					}
					/*else
					{
						mPosition = mPosition - VELOCITY2 * mMatrixRotate;
					}*/
					//�ʒu�̍X�V(mPosition + adjust)
					mPosition = mPosition + adjust;
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
	//�R���C�_�̗D��x�ύX
	mLine.ChangePriority();
	mLine2.ChangePriority();
	mLine3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mLine, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mLine2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mLine3, COLLISIONRANGE);
}

CPlayer* CPlayer::spInstance = nullptr;

CPlayer* CPlayer::Instance()
{
	return spInstance;
}
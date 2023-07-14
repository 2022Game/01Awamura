#include "CAWood.h"
#include "CCollisionManager.h"
#include "CApplication.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.3f,0.0f,0.0f)
#define VELOCITY11 CVector(-0.3f,0.0f,0.30f)

//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CAWood::CAWood(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f,1.0f,0.0f), 0.75f)
{
	//��Q���p�̃^�O�ݒ�
	mTag = ETag::EOBSTACLE;
	//�؂̃I�u�W�F�N�g�p�̃��C���[��ݒ�
	mCollider.Layer(CCollider::ELayer::EWOOD);

	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	ha = 0;
	mLastPos = position; //�O��̃|�W�V�����ɐݒ肷��
}

void CAWood::Update() {
	//�ړ��O�̍��W���L�����Ă���
	mLastPos = Position();
	if (CApplication::hcount == 1)
	{
		if (ha % 2 == 0)
		{
			Position(Position() + VELOCITY10 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY10 * MatrixRotate());
		}
	}
	if (CApplication::hcount == 2)
	{
		if (ha % 2 == 0)
		{
			Position(Position() + VELOCITY11 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY11 * MatrixRotate());
		}
	}
	//�s����X�V
	CTransform::Update();
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAWood::Collision(CCollider* m, CCollider* o) {
	//���肪�����̕ǃR���C�_�łȂ���΁A�Փ˔�����s��Ȃ�
	if (o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Type()) {
	case CCollider::EType::ELINE:
		if (CCollider::Collision(m, o)) {
			//�Փ˂��Ă���Ƃ��͖����ɂ���
				Position(mLastPos);
				ha++;
		}
		break;
	}
}

void CAWood::Collision()
{
	//�R���C�_�̗D��x�ύX
	mCollider.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 200);
}
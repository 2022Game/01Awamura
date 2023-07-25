#include "CAWood.h"
#include "CCollisionManager.h"
#include "CApplication.h"

#include <stdlib.h>

#include "time.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.25f,0.0f,0.0f)
#define VELOCITY11 CVector(-0.25f,0.0f,0.30f)
#define VELOCITY12 CVector(-0.25f,0.0f,-0.30f)
#define VELOCITY13 CVector(0.25f,0.0f,-0.30f)

int rand(void);
void srand(unsigned int seed);

//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CAWood::CAWood(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 1.0f, 0.0f), 0.75f)
	, rararan(0)
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
	mStartPos = position;
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
	if (CApplication::hcount == 3)
	{
		if (ha % 2 == 0)
		{
			Position(Position() + VELOCITY12 * MatrixRotate());
		}
		else
		{
			Position(Position() + VELOCITY13 * MatrixRotate());
		}
	}
	//�s����X�V
	CTransform::Update();
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAWood::Collision(CCollider* m, CCollider* o) {
	//���肪�����̕ǃR���C�_�łȂ���΁A�Փ˔�����s��Ȃ�
	if (o->Layer() != CCollider::ELayer::ELINEWALL && o->Layer() != CCollider::ELayer::ELINEWALL2)return;

	switch (o->Layer()) {
	case CCollider::ELayer::ELINEWALL:
		if (CCollider::Collision(m, o)) {
			//�Փ˂��Ă���Ƃ��͖����ɂ���
				Position(mLastPos);
				ha++;
		}
		break;
	}
	switch (o->Layer()) {
	case CCollider::ELayer::ELINEWALL2:
		if (CCollider::Collision(m, o)) {
			//�Փ˂��Ă���Ƃ��͖����ɂ���
			//Position(mStartPos);
			ha++;
			rararan = 4 + rand() % 17;
			if (CApplication::StageCheck == 0)
			{
				Position((CVector(rararan, 22.9f, 102.0f)));
			}
			if (CApplication::StageCheck == 1)
			{
				Position((CVector(rararan, 22.9f, 154.0f)));
			}
			if (CApplication::StageCheck == 2)
			{
				Position((CVector(rararan, 22.9f, 203.0f)));
			}
			if (CApplication::StageCheck == 3)
			{
				Position((CVector(rararan, 22.9f, 203.0f)));
			}
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
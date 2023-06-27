#include "CAWood.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.20f,0.0f,0.0f)
#define VELOCITY11 CVector(-0.20f,0.0f,0.10f)

//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CAWood::CAWood(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f,1.0f,0.0f), 0.75f)
{
	//��Q���p�̃^�O�ݒ�
	mTag = ETag::EOBSTACLE;

	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	ha = 0;
	hb = 40;
	coo = 100;
}

void CAWood::Update() {
	//�s����X�V
	CTransform::Update();
	hb--;
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
	if (CApplication::hcount == 0)
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
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAWood::Collision(CCollider* m, CCollider* o) {
	switch (o->Type()) {
	case CCollider::ELINE:
		if (CCollider::Collision(m, o)) {
			//�Փ˂��Ă���Ƃ��͖����ɂ���
			if (hb <= 0)
			{
				ha++;
				hb = 60;
			}
		}
	}
}

void CAWood::Collision()
{
	//�R���C�_�̗D��x�ύX
	mCollider.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
}
#include "CAHamah.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.20f,0.0f,0.0f)

int ha, hb, hc, hd;

//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CAHamah::CAHamah(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale; //�g�k�̐ݒ�
	mColliderMesh2.Set(this, &mMatrix, mpModel);
	ha = 0;
	hb = 180;
	hc = 0;
	hd = 280;
}

void CAHamah::Update() {
	//�s����X�V
	CTransform::Update();
	hd--;
	if (hb > 0)
	{
		hb--;

	}
	else
	{
		hb = 0;
	}
	if (hb == 0)
	{
		if (hd <= 0)
		{
			hc++;
			hd = 240;
		}
		if (hc % 2 == 0)
		{
			mPosition = mPosition - VELOCITY10 * mMatrixRotate;
		}
		else
		{
			mPosition = mPosition + VELOCITY10 * mMatrixRotate;
		}
	}
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAHamah::Collision(CCollider* m, CCollider* o) {
	//����̃R���C�_�^�C�v�̔���
	//switch (o->Type())
	//{
	//case CCollider::ETRIANGLE2://�O�p�R���C�_�̎�
	//	if (m->Type() == CCollider::ELINE) {
	//	}
	//	break;
	//}
	if (CCollider::Collision(m, o)) {
		mEnabled = false;
	}
}

void CAHamah::Collision()
{
	mColliderMesh2.ChangePriority();
	//�R���C�_�̗D��x�ύX
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);
}
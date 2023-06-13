#include "CAWall.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.20f,0.0f,0.0f)

//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CAWall::CAWall(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	mColliderMesh.Set(this, &Matrix(), mpModel);
}

void CAWall::Update() {
	//�s����X�V
	CTransform::Update();

}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAWall::Collision(CCollider* m, CCollider* o) {
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

void CAWall::Collision()
{
	//�R���C�_�̗D��x�ύX
	mColliderMesh.ChangePriority();
}
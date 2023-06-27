#include "CAHamah.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY10 CVector(0.15f,0.0f,0.0f)

//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CAHamah::CAHamah(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:CCharacter3((int)TaskPriority::eObstacie)
	,mCollider(this,&Matrix(),CVector(),2.25f)
{
	//��Q���p�̃^�O�ݒ�
	mTag = ETag::EOBSTACLE;

	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	ha = 0;
	hb = 0;
}

void CAHamah::Update() {
	//�s����X�V
	CTransform::Update();
	hb--;
	if (ha % 2 == 0)
	{
		Position(Position() + VELOCITY10 * MatrixRotate());
	}
	else
	{
		Position(Position() - VELOCITY10 * MatrixRotate());
	}
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAHamah::Collision(CCollider* m, CCollider* o) {
	switch (o->Type()) {
	case CCollider::ELINE:
		if (CCollider::Collision(m, o)) {
			//�Փ˂��Ă���Ƃ��͖����ɂ���
			//mEnabled = false;
			if (hb <= 0)
			{
				ha++;
				hb = 60;
			}
		}
	}
}

	void CAHamah::Collision()
	{
		//�R���C�_�̗D��x�ύX
		mCollider.ChangePriority();
		//�Փˏ��������s
		CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
	}
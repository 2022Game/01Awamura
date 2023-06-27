

#include "CACoin.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"

//�ړ����x
#define VELOCITY CVector(0.0f,0.075f,0.0f)
#define VELOCITY10 CVector(0.05f,0.0f,0.0f)

//int CACoin::mD;

//�R���X�g���N�^
//CACoin(���f���A�ʒu�A��]�A�g�k�j
CACoin::CACoin(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
{
	//�X�e�[�W�̕ǐ����p�^�O��ݒ�
	mTag = ETag::ESTAGEGUARD;

	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	mColliderMesh.Set(this, &Matrix(), mpModel);
	SCount = 0;
	UpCount = 180 / 6 * 10;
	SideChengeCount = 0;
	SideCount = 300 / 6;
	//mTag = CCharacter3::ETag::ECOIN;
	ha = 0;
	hb = 0;
}

//�X�V����
void CACoin::Update() {
	/*if (mD == 150)
	{
		mEnabled = false;
	}*/
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
	if (SideCount <= 0)
	{
		SideChengeCount++;
		SideCount = 480 / 6;
	}
	if (UpCount < 0)
	{
		//		mPosition = mPosition + VELOCITY10 * mMatrixRotate;
		UpCount = 0;
		SCount = 2;
	}
	if (SCount == 1)
	{
		UpCount--;
		Position(Position() + VELOCITY * MatrixRotate());
	}
	if (SCount >= 2)
	{
		SideCount--;
		if (SideChengeCount % 2 == 0)
		{
			Position(Position() + VELOCITY10 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY10 * MatrixRotate());
		}
	}
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CACoin::Collision(CCollider* m, CCollider* o) {
	switch (o->Type())
	{
	case CCollider::ESPHERE://���R���C�_�̎�
		if (o->Type() == CCollider::ELINE) {
			CVector adjust;//�����p�x�N�g��
		}
		break;
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

void CACoin::Collision()
{
	//�R���C�_�̗D��x�ύX
	mColliderMesh.ChangePriority();
}
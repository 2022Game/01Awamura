#include "CACoinClearStage.h"
#include "CCollisionManager.h"

#define VELOCITY CVector(0.0f,0.075f,0.0f)
#define VELOCITY10 CVector(0.05f,0.0f,0.0f)

//�R���X�g���N�^
//CACoin(���f���A�ʒu�A��]�A�g�k�j
CACoinClearStage::CACoinClearStage(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:CCharacter3((int)TaskPriority::eMoveObject)
{
	mTag = ETag::ESTAGECLEAR;

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
}

//�X�V����
void CACoinClearStage::Update() {
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
void CACoinClearStage::Collision(CCollider* m, CCollider* o) {
	//����̃R���C�_�^�C�v�̔���
	switch (o->Type())
	{
	case CCollider::EType::ELINE://�O�p�R���C�_�̎�
		CVector adjust;//�����p�x�N�g��
		if (CCollider::CollisionTriangleLine(o, m, &adjust))
		{
			mEnabled = false;
		}
		break;
	}
}

void CACoinClearStage::Collision()
{
	//�R���C�_�̗D��x�ύX
	mColliderMesh.ChangePriority();
}
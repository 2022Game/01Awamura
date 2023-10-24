#include "CACoin.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#include <stdlib.h>

#include "time.h"

//�ړ����x
#define VELOCITY CVector(0.0f,0.075f,0.0f)
#define VELOCITY10 CVector(0.15f,0.0f,0.0f)

int rand(void);
void srand(unsigned int seed);

//�R���X�g���N�^
//CACoin(���f���A�ʒu�A��]�A�g�k�j
CACoin::CACoin(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 0.0f, 0.0f), 3.0f)
	,rand11(0)
	,rand12(0)
	,rand13(0)
	,rand14(0)
	,rand15(0)
	,rand16(0)
{
	//�X�e�[�W�̕ǐ����p�^�O��ݒ�
	mTag = ETag::ESTAGEGUARD;

	srand((unsigned int)time(NULL));


	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	mColliderMesh.Set(this, &Matrix(), mpModel);
	SCount = 2;
	UpCount = 180 / 6 * 10;
	SideChengeCount = 0;
	SideCount = 300 / 6;
	ha = 0;
	hb = 0;
	mLastPos = position; //�O��̃|�W�V�����ɐݒ肷��
	mCollider.Layer(CCollider::ELayer::ECOIN);
}

//�X�V����
void CACoin::Update() {
	//�ړ��O�̍��W���L�����Ă���
	mLastPos = Position();
	//�ʒu���ړ�
	if (SCount >= 2)
	{
		if (SideChengeCount % 2 == 0)
		{
			Position(Position() + VELOCITY10 * MatrixRotate());
		}
		else
		{
			Position(Position() - VELOCITY10 * MatrixRotate());
		}
	}
	//�s����X�V
	CTransform::Update();
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CACoin::Collision(CCollider* m, CCollider* o) {
	//���肪�����̕ǃR���C�_�łȂ���΁A�Փ˔�����s��Ȃ�
	if (o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Type()) {
	case CCollider::EType::ELINE:
		if (CCollider::Collision(m, o)) {
			//�Փ˂��Ă���Ƃ��͖����ɂ���
			Position(mLastPos);
			SideChengeCount++;
		}
		break;
	}
}

void CACoin::Collision()
{
	//�R���C�_�̗D��x�ύX
	//mColliderMesh.ChangePriority();
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 10);
}
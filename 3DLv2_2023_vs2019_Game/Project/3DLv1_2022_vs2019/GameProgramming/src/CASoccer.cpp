#include "CASoccer.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#include <stdlib.h>

#include "time.h"

#define VELOCITY20 CVector(0.0f,0.0f,-0.75f)
#define VELOCITY21 CVector(-0.2f,0.0f,-0.30f)
#define VELOCITY22 CVector(0.2f,0.0f,-0.30f)

int rand(void);
void srand(unsigned int seed);

int CASoccer::hdhd = 0;
//�R���X�g���N�^
CASoccer::CASoccer(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 2.0f, 0.0f), 1.50f)
	,rarand(0)
{
	srand((unsigned int)time(NULL));
	hdhd = 0;
	//��Q���p�̃^�O�ݒ�
	mTag = ETag::EOBSTACLE;
	//�؂̃I�u�W�F�N�g�p�̃��C���[��ݒ�
	mCollider.Layer(CCollider::ELayer::ESOCCER);

	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model; //���f���̐ݒ�
	Position(position); //�ʒu�̐ݒ�
	Rotation(rotation); //��]�̐ݒ�
	Scale(scale); //�g�k�̐ݒ�
	mLastPos = position; //�O��̃|�W�V�����ɐݒ肷��
}

void CASoccer::Update() {
	//�ړ��O�̍��W���L�����Ă���
	//mLastPos = Position();
	if (CApplication::hcount == 7)
	{
		Position(Position() + VELOCITY20 * MatrixRotate());
	}
	if (CApplication::hcount == 8)
	{
		if (hdhd % 2 == 0)
		{
			Position(Position() + VELOCITY21 * MatrixRotate());
		}
		else
		{
			Position(Position() + VELOCITY22 * MatrixRotate());
		}
	}
	//�s����X�V
	CTransform::Update();
	/*if (hdhd == 2)
	{
		hdhd = 0;
	}*/
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CASoccer::Collision(CCollider* m, CCollider* o) {
	//���肪�����̕ǃR���C�_�łȂ���΁A�Փ˔�����s��Ȃ�
	if (o->Layer() != CCollider::ELayer::ELINEWALL2 && o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Layer()) {
	case CCollider::ELayer::ELINEWALL2:
		if (CCollider::Collision(m, o)) {
			//mEnabled = false;
			//hdhd = 2;
			rarand = 4 + rand() % 17;
			if (CApplication::StageCheck == 0)
			{
				Position((CVector(rarand, 23.0f, 70.0f)));
			}
			if (CApplication::StageCheck == 1)
			{
				Position((CVector(rarand, 23.0f, 120.0f)));
			}
			if (CApplication::StageCheck == 2)
			{
				Position((CVector(rarand, 23.0f, 170.0f)));
			}
			if (CApplication::StageCheck == 3)
			{
				Position((CVector(rarand, 23.0f, 170.0f)));
			}
		}
		break;
	}
		switch (o->Layer()) {
		case CCollider::ELayer::ELINEWALL:
			if (CCollider::Collision(m, o)) {
				hdhd++;
				Position(mLastPos);
			}
			break;
		}
}

void CASoccer::Collision()
{
	//�R���C�_�̗D��x�ύX
	mCollider.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE * 10);
}
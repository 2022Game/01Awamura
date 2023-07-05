#include "CASoccer.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"
#include "CApplication.h"

#define VELOCITY CVector(0.0f,0.0f,0.0f)
#define VELOCITY20 CVector(0.0f,0.0f,-0.25f)
#define VELOCITY21 CVector(-0.2f,0.0f,0.30f)

int CASoccer::hdhd = 0;
//�R���X�g���N�^
//CAHamah(���f���A�ʒu�A��]�A�g�k�j
CASoccer::CASoccer(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider(this, &Matrix(), CVector(0.0f, 1.0f, 0.0f), 1.75f)
{
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
	mLastPos = Position();
	Position(Position() + VELOCITY20 * MatrixRotate());
	//�s����X�V
	CTransform::Update();
	if (hdhd == 2)
	{
		hdhd = 0;
	}
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CASoccer::Collision(CCollider* m, CCollider* o) {
	//���肪�����̕ǃR���C�_�łȂ���΁A�Փ˔�����s��Ȃ�
	if (o->Layer() != CCollider::ELayer::ELINEWALL)return;

	switch (o->Type()) {
	case CCollider::EType::ELINE:
		if (CCollider::Collision(m, o)) {
			mEnabled = false;
			hdhd = 2;
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
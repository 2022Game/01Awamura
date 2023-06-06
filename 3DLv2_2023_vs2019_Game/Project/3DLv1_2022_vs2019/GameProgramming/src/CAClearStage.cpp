

#include "CAClearStage.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CColliderMesh.h"
#include "CApplication.h"

//�y��Coin
#define MODEL_FCOIN "res\\Coin.obj","res\\Coin.mtl"

CAClearStage::CAClearStage()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);

}

CAClearStage::~CAClearStage()
{
	// �R�C���̃��f���f�[�^��j��
	if (mpCoinModel != nullptr)
	{
		delete mpCoinModel;
	}

	// �R�C����j��
	for (int i = 0; i < mClearStages.size(); i++)
	{
		delete mClearStages[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mClearStages.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CAClearStage::Init()
{
	// �R�C���̃��f���ǂݍ���
	mpCoinModel = new CModel();
	mpCoinModel->Load(MODEL_FCOIN);

	// �R�C���𐶐�
	//�X�e�[�W�P�X�^�[�g����
	ClearStage(CVector(10.0f, 0.1f, -2.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////�X�e�[�W�Q�X�^�[�g����
	ClearStage(CVector(10.0f, 0.1f, 46.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////�X�e�[�W�R�X�^�[�g����
	ClearStage(CVector(10.0f, 0.1f, 94.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
	////�Q�[���N���A����
	ClearStage(CVector(10.0f, 0.1f, 142.0f), CVector(), CVector(0.8f, 0.8f, 0.8f));
}

void CAClearStage::ClearStage(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpCoinModel == nullptr) return;

	// �R�C���𐶐����ă��X�g�ɒǉ�
	CACoinClearStage* coin = new CACoinClearStage(mpCoinModel, pos, rot, scale);
	mClearStages.push_back(coin);
}

void CAClearStage::Update()
{
	//if (�v���C���[���R�C���ɐڒn������)
	{
		for (int i = 0; i < mClearStages.size(); i++)
		{
			CACoinClearStage* coin = mClearStages[i];
			if (coin->SCount == 0)
			{
				coin->SCount = 1;
			}
		}
	}
}

//�Փˏ���
//CCollision(�R���C�_�P�A�R���C�_�Q�j
void CAClearStage::Collision(CCollider* m, CCollider* o) {
	switch (m->Type())
	{
	case CCollider::ETRIANGLE3://���R���C�_�̎�
		//�R���C�_��m��y���Փ˂��Ă��邩����
		if (o->Type() == CCollider::ELINE)
		{
			if (CCollider::Collision(m, o)) {
				mEnabled = false;
			}
		}
		break;
	case CCollider::ETRIANGLE:
		if (o->Type() == CCollider::ELINE)
		{
			if (CCollider::Collision(m, o)) {
				mEnabled = false;
			}
		}
		CVector adjust;
		break;
	}
}

void CAClearStage::Collision()
{
	mColliderMesh.ChangePriority();
	mColliderMesh1.ChangePriority();
	//�R���C�_�̗D��x�ύX
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Instance()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Instance()->Collision(&mCollider3, COLLISIONRANGE);
}
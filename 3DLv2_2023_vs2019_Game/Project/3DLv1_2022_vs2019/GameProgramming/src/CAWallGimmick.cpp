#include "CAWallGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
#include "CResourceManager.h"

//�_���Ȃ��
#define MODEL_FWALL "res\\Wall2.obj","res\\Wall2.mtl"

CAWallGimmick::CAWallGimmick()
{
	// ��������
	Init();

	// �^�X�N�}�l�[�W���[�Ɏ��g��ǉ�
	CTaskManager::Instance()->Add(this);
}

CAWallGimmick::~CAWallGimmick()
{
	// �n�}�[��j��
	for (int i = 0; i < mWalls.size(); i++)
	{
		delete mWalls[i];
	}
	// �ꉞ���X�g���N���A���Ă���
	mWalls.clear();

	// �^�X�N�}�l�[�W���[���玩�g����菜��
	CTaskManager::Instance()->Remove(this);
}

void CAWallGimmick::Init()
{
	// Wall�̃��f���ǂݍ���
	/*mpWallModel = new CModel();
	mpWallModel->Load(MODEL_FWALL);*/
	mpWallModel = GET_MODEL("Wall");

	// Wall�𐶐�
	//�X�e�[�W�P�X�^�[�g����
	if (CApplication::StageCount == 0)
	{
		CreateWall(CVector(26.0f, 24.0f, 0.0f), CVector(), CVector(0.0f, 5.0f, 1500.0f));
		CreateWall(CVector(-1.3f, 24.0f, 0.0f), CVector(), CVector(0.0f, 5.0f, 1500.0f));
	}
}

void CAWallGimmick::CreateWall(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpWallModel == nullptr) return;

	// �n�}�[�𐶐����ă��X�g�ɒǉ�
	CAWall* wall = new CAWall(mpWallModel, pos, rot, scale);
	mWalls.push_back(wall);
}

void CAWallGimmick::Update()
{
}
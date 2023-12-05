#include "CStageEntrance.h"
#include "CFloor.h"
#include "CWarp.h"

//�R���X�g���N�^
CStageEntrance::CStageEntrance()
{
	mStageNo = 0;
}

//�f�X�g���N�^
CStageEntrance::~CStageEntrance()
{

}

//�X�e�[�W�ǂݍ���
void CStageEntrance::Load()
{
	// �N���A�y��̃��f���ǂݍ���
	CModel* floorModel = new CModel();
	floorModel->Load("Field\\Object\\cube.obj", "Field\\Object\\cube.mtl");
	mCreateModels.push_back(floorModel);

	CModel* warpModel = new CModel();
	warpModel->Load("Field\\WarpDoor2.obj", "Field\\WarpDoor2.mtl");
	mCreateModels.push_back(warpModel);

	//���ʂ̑���
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, 2.0f, -20.0f), CVector(0.5f, 4.0f, 5.0f));
	AddTask(floor);

	//���[�v�����쐬
	CWarp* warp = new CWarp(warpModel,
		CVector(0.0f, 10.0f, -20.0f), CVector(6.0f, 3.0f, 10.0f));
	AddTask(warp);
}

//�X�e�[�W�j��
void CStageEntrance::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}
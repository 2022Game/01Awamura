#include "CStage5.h"
#include "CClearStage.h"

//�R���X�g���N�^
CStage5::CStage5()
{
	mStageNo = 5;
}

//�f�X�g���N�^
CStage5::~CStage5()
{

}

//�X�e�[�W�ǂݍ���
void CStage5::Load()
{
	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = new CModel();
	clearStageModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");
	mCreateModels.push_back(clearStageModel);

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, -5.0f, -20.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);
}

//�X�e�[�W�j��
void CStage5::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}
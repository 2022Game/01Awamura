#include "CStage4.h"
#include "CClearStage.h"
#include "CKillwood.h"
#include "CSidewood.h"
#include "CBollField.h"

//�R���X�g���N�^
CStage4::CStage4()
{
	mStageNo = 4;
}

//�f�X�g���N�^
CStage4::~CStage4()
{

}

//�X�e�[�W�ǂݍ���
void CStage4::Load()
{
	// �N���A�y��̃��f���ǂݍ���
	CModel* clearStageModel = new CModel();
	clearStageModel->Load("Field\\Object\\cylinder.obj", "Field\\Object\\cylinder.mtl");
	mCreateModels.push_back(clearStageModel);

	//��؂̃��f���ǂݍ���
	CModel* killwoodModel = new CModel();
	killwoodModel->Load("Field\\Killwood.obj", "Field\\Killwood.mtl");
	mCreateModels.push_back(killwoodModel);

	//�|�؂̃��f���ǂݍ���
	CModel* sidewoodModel = new CModel();
	sidewoodModel->Load("Field\\Killbranc.obj", "Field\\Killbranc.mtl");
	mCreateModels.push_back(sidewoodModel);

	//�~�`�y��̃��f���ǂݍ���
	CModel* bollFieldModel = new CModel();
	bollFieldModel->Load("Field\\bollfield.obj", "Field\\bollfield.mtl");
	mCreateModels.push_back(bollFieldModel);

	//�N���A�y����쐬
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//��؂��쐬
	CKillwood* killwood = new CKillwood(killwoodModel,
		CVector(0.0f, 0.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		,0.0f);
	AddTask(killwood);

	//�|�؂��쐬
	CSidewood* sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 15.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		,0.0f);
	AddTask(sidewood);
	sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 6.0f, -30.0f), CVector(5.5f, 5.0f, 5.25f)
		, 0.0f);
	AddTask(sidewood);

	//�~�`�y����쐬
	CBollField* bollField = new CBollField(bollFieldModel,
		CVector(0.0f, -20.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(bollField);
}

//�X�e�[�W�j��
void CStage4::Unload()
{
	//�x�[�X�̃X�e�[�W�j������
	CStageBase::Unload();
}
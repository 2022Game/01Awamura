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
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//��؂̃��f���ǂݍ���
	CModel* killwoodModel = CResourceManager::Get<CModel>("Killwood");

	//�|�؂̃��f���ǂݍ���
	CModel* sidewoodModel = CResourceManager::Get<CModel>("Sidewood");

	//�~�`�y��̃��f���ǂݍ���
	CModel* bollFieldModel = CResourceManager::Get<CModel>("Bollfield");

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
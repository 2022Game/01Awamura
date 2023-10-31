#pragma once
#include "CTask.h"
#include "CClearStage.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CClearStageGimmick : public CTask
{
private:
	std::vector<CClearStage*> mClearStage;	// �N���A�y��̃��X�g
	CModel* mpClearStageModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateClearStage(CModel* model, const CVector& pos, const CVector& scale);
	

	CModel* mpClearModel;


public:
	CClearStageGimmick();
	~CClearStageGimmick();

	// �X�V����
	void Update();
};
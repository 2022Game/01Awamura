#pragma once
#include "CTask.h"
#include "CClearCube.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CClearCubeGimmick : public CTask
{
private:
	std::vector<CClearCube*> mClearCube;	// �N���A�y��̃��X�g
	CModel* mpClearCubeStageModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateClearCubeStage(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpClearCubeModel;
	CColliderMesh* mpColliderMesh;

public:
	CClearCubeGimmick();
	~CClearCubeGimmick();

	// �X�V����
	void Update();
};
#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CLMoveField.h"

class CLMoveFieldGimmick : public CTask
{
private:
	std::vector<CLMoveField*> mLMoveField;	// �N���A�y��̃��X�g
	CModel* mpMoveLModel; //T�����f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateLMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpLMoveField;


public:
	CLMoveFieldGimmick();
	~CLMoveFieldGimmick();

	// �X�V����
	void Update();
};
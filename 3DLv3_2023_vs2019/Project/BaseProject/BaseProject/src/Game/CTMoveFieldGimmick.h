#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CTMoveField.h"

class CTMoveFieldGimmick : public CTask
{
private:
	std::vector<CTMoveField*> mTMoveField;	// �N���A�y��̃��X�g
	CModel* mpMoveTModel; //T�����f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateTMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpTMoveField;


public:
	CTMoveFieldGimmick();
	~CTMoveFieldGimmick();

	// �X�V����
	void Update();
};
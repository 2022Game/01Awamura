#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CIMoveField.h"

class CIMoveFieldGimmick : public CTask
{
private:
	std::vector<CIMoveField*> mIMoveField;	// �N���A�y��̃��X�g
	CModel* mpMoveIModel; //T�����f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateIMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpIMoveField;


public:
	CIMoveFieldGimmick();
	~CIMoveFieldGimmick();

	// �X�V����
	void Update();
};
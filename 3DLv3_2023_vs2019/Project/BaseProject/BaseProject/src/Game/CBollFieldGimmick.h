#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CBollField.h"

class CBollFieldGimmick : public CTask
{
private:
	std::vector<CBollField*> mBollField;	// �N���A�y��̃��X�g
	CModel* mpBollFieldModel;			// �N���A�y��̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateBollField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpBollField;


public:
	CBollFieldGimmick();
	~CBollFieldGimmick();

	// �X�V����
	void Update();
};
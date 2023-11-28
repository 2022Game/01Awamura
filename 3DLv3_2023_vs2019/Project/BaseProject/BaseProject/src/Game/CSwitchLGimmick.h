#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSwitchLObject.h"

class CSwitchLGimmick : public CTask
{
private:
	std::vector<CSwitchLObject*> mLSwitch;	// �N���A�y��̃��X�g
	CModel* mpMoveSwitchLModel;			// �X�C�b�`�̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateSwitch(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSwitch;


public:
	CSwitchLGimmick();
	~CSwitchLGimmick();

	// �X�V����
	void Update();
};
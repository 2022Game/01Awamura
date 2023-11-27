#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSwitchObject.h"

class CSwitchGimmick : public CTask
{
private:
	std::vector<CSwitchObject*> mSwitch;	// �N���A�y��̃��X�g
	CModel* mpMoveSwitchModel;			// �X�C�b�`�̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateSwitch(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSwitch;


public:
	CSwitchGimmick();
	~CSwitchGimmick();

	// �X�V����
	void Update();
};
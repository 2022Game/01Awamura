#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSwitchRObject.h"

class CSwitchRGimmick : public CTask
{
private:
	std::vector<CSwitchRObject*> mRSwitch;	// �N���A�y��̃��X�g
	CModel* mpMoveSwitchRModel;			// �X�C�b�`�̃��f���f�[�^

	// ����������
	void Init();
	// �N���A�y��𐶐����ă��X�g�ɒǉ�
	void CreateSwitch(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSwitch;


public:
	CSwitchRGimmick();
	~CSwitchRGimmick();

	// �X�V����
	void Update();
};
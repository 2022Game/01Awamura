#pragma once
#include "CObjectBase.h"
#include "CColliderMesh.h"
#include "CClearStageGimmick.h"
#include "CFloorGimmick.h"
#include "CWarpGimmick.h"
#include "CAxe.h"
#include "CAxeGimmick.h"
#include "CSlopeGimmick.h"
#include "CClearCubeGimmick.h"
#include "CStoneGimmick.h"
#include "CMoveFieldGimmick.h"
#include "CTMoveFieldGimmick.h"
#include "CIMoveFieldGimmick.h"
#include "CLMoveFieldGimmick.h"
#include "CJMoveFieldGimmick.h"
#include "CSwitchRGimmick.h"
#include "CSwitchLGimmick.h"
#include "CKillwoodGimmick.h"
#include "CSidewoodGimmick.h"
#include "CBollFieldGimmick.h"

class CField : public CObjectBase 
{
public:
	CField();
	~CField();

	void Update();
	void Render();

	//���ʂ̃X�e�[�W�����Ǘ��p�ϐ�
	static int mClearCount;
	static int mStageCount;
	static int mClearCountSwitch;
	static int mStageReset;
	static int mStageCreateSwitch;
	static int mStartSwitch;
	static int mDeleteSwitch;

private:
	void CreateFieldObjects();

	int mDeleteCount;
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	//�ʏ�N���A�X�e�[�W
	CClearStageGimmick* mpClearStageGimmick;
	//�l�p�N���A�X�e�[�W
	CClearCubeGimmick* mpClearCubeGimmick;
	//�ʏ�y��
	CFloorGimmick* mpFloorGimmick;
	//���[�v��Q��
	CWarpGimmick* mpWarpGimmick;
	//��
	CAxeGimmick* mpAxeGimmick;
	//�⓹
	CSlopeGimmick* mpSlopeGimmick;
	//��
	CStoneGimmick* mpStoneGimmick;
	//��]����\���y��
	CMoveFieldGimmick* mpMoveFieldGimmick;
	//��]����T���y��
	CTMoveFieldGimmick* mpTMoveFieldGimmick;
	//��]����I���y��
	CIMoveFieldGimmick* mpIMoveFieldGimmick;
	//��]����J���y��
	CJMoveFieldGimmick* mpJMoveFieldGimmick;
	//��]����L���y��
	CLMoveFieldGimmick* mpLMoveFieldGimmick;
	//�E�X�C�b�`
	CSwitchRGimmick* mpSwitchRGimmick;
	//��switch
	CSwitchLGimmick* mpSwitchLGimmick;
	//�E�C�̑��
	CKillwoodGimmick* mpKillwoodGimmick;
	//�E�C�̓|��
	CSidewoodGimmick* mpSidewoodGimmick;
	//�~�`�y��
	CBollFieldGimmick* mpBollFieldGimmick;

	CModel* mpCubeModel;
	CModel* mpCylinderModel;
	CModel* mpClearModel;
	//CModel* mpFloorModel;
	//CStageManager* mpStageManager;
};
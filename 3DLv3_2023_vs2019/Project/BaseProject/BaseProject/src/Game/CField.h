#pragma once
#include "CObjectBase.h"
#include "CColliderMesh.h"
#include "CClearStageGimmick.h"
#include "CFloorGimmick.h"
#include "CWarpGimmick.h"
#include "CAxe.h"
#include "CAxeGimmick.h"

class CField : public CObjectBase 
{
public:
	CField();
	~CField();

	void Update();
	void Render();

	//共通のステージ生成管理用変数
	static int mClearCount;
	static int mStageCount;
	static int mClearCountSwitch;
	static int mStageReset;
	static int mStageCreateSwitch;
	static int mStartSwitch;

private:
	void CreateFieldObjects();

	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CClearStageGimmick* mpClearStageGimmick;
	CFloorGimmick* mpFloorGimmick;
	CClearStageGimmick* mpClearStageGimmick2;
	CWarpGimmick* mpWarpGimmick;
	CAxeGimmick* mpAxeGimmick;
	CModel* mpCubeModel;
	CModel* mpCylinderModel;
	CModel* mpClearModel;
	CModel* mpAxeModel;
	//CModel* mpFloorModel;
	//CStageManager* mpStageManager;
};
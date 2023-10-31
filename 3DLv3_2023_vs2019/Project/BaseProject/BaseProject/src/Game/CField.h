#pragma once
#include "CObjectBase.h"
#include "CColliderMesh.h"
#include "CClearStageGimmick.h"
#include "CStageManager.h"
#include "CFloorGimmick.h"

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

private:
	void CreateFieldObjects();

	CModel* mpModel;
	CColliderMesh* mpColliderMesh;

	CClearStageGimmick* mpClearStageGimmick;
	CFloorGimmick* mpFloorGimmick;
	CClearStageGimmick* mpClearStageGimmick2;
	CModel* mpCubeModel;
	CModel* mpCylinderModel;
	CModel* mpClearModel;
	//CModel* mpFloorModel;
	//CStageManager* mpStageManager;
};
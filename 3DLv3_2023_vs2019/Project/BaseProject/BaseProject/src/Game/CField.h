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
#include "CStornGimmick.h"
#include "CMoveFieldGimmick.h"

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
	static int mDeleteSwitch;

private:
	void CreateFieldObjects();

	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	//通常クリアステージ
	CClearStageGimmick* mpClearStageGimmick;
	//四角クリアステージ
	CClearCubeGimmick* mpClearCubeGimmick;
	//通常土台
	CFloorGimmick* mpFloorGimmick;
	//ワープ障害物
	CWarpGimmick* mpWarpGimmick;
	//斧
	CAxeGimmick* mpAxeGimmick;
	//坂道
	CSlopeGimmick* mpSlopeGimmick;
	//岩
	CStornGimmick* mpStornGimmick;
	//回転する土台
	CMoveFieldGimmick* mpMoveFieldGimmick;

	CModel* mpCubeModel;
	CModel* mpCylinderModel;
	CModel* mpClearModel;
	//CModel* mpFloorModel;
	//CStageManager* mpStageManager;
};
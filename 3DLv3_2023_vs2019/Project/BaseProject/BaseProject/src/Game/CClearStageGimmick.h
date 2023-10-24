#pragma once
#include "CTask.h"
#include "CClearStage.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CClearStageGimmick : public CTask
{
private:
	std::vector<CClearStage*> mClearStage;	// クリア土台のリスト
	CModel* mpClearStageModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateClearStage(CModel* model, const CVector& pos, const CVector& scale);
	

	CModel* mpClearModel;


public:
	CClearStageGimmick();
	~CClearStageGimmick();

	// 更新処理
	void Update();
};
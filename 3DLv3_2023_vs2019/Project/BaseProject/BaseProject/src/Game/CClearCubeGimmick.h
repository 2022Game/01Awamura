#pragma once
#include "CTask.h"
#include "CClearCube.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CClearCubeGimmick : public CTask
{
private:
	std::vector<CClearCube*> mClearCube;	// クリア土台のリスト
	CModel* mpClearCubeStageModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateClearCubeStage(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpClearCubeModel;
	CColliderMesh* mpColliderMesh;

public:
	CClearCubeGimmick();
	~CClearCubeGimmick();

	// 更新処理
	void Update();
};
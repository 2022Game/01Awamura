#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSlope.h"

class CSlopeGimmick : public CTask
{
private:
	std::vector<CSlope*> mSlope;	// クリア土台のリスト
	CModel* mpSlopeModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateSlope(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSlope;


public:
	CSlopeGimmick();
	~CSlopeGimmick();

	// 更新処理
	void Update();
};
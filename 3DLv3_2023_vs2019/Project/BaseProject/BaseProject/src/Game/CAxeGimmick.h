#pragma once
#include "CTask.h"
#include "CAxe.h"
#include "CColliderMesh.h"
#include "CCollider.h"

class CAxeGimmick : public CTask
{
private:
	std::vector<CAxe*> mAxe;	// クリア土台のリスト
	CModel* mpAxe;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// 斧を生成してリストに追加
	void CreateAxe(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpAxeModel;
	CColliderMesh* mpColliderMesh;

public:
	CAxeGimmick();
	~CAxeGimmick();

	// 更新処理
	void Update();
};
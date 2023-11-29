#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CSidewood.h"

class CSidewoodGimmick : public CTask
{
private:
	std::vector<CSidewood*> mSidewood;	// クリア土台のリスト
	CModel* mpSidewoodModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateSidewood(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpSidewood;

	int randpos;


public:
	CSidewoodGimmick();
	~CSidewoodGimmick();

	// 更新処理
	void Update();
};
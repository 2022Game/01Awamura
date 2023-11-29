#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CKillwood.h"

class CKillwoodGimmick : public CTask
{
private:
	std::vector<CKillwood*> mKillwood;	// クリア土台のリスト
	CModel* mpKillwoodModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateKillwood(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpKillwood;

	int randpos;


public:
	CKillwoodGimmick();
	~CKillwoodGimmick();

	// 更新処理
	void Update();
};
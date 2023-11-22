#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CMoveField.h"

class CMoveFieldGimmick : public CTask
{
private:
	std::vector<CMoveField*> mMoveField;	// クリア土台のリスト
	CModel* mpMoveTenModel;			// 十字のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpMoveField;


public:
	CMoveFieldGimmick();
	~CMoveFieldGimmick();

	// 更新処理
	void Update();
};
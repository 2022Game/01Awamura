#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CLMoveField.h"

class CLMoveFieldGimmick : public CTask
{
private:
	std::vector<CLMoveField*> mLMoveField;	// クリア土台のリスト
	CModel* mpMoveLModel; //T字モデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateLMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpLMoveField;


public:
	CLMoveFieldGimmick();
	~CLMoveFieldGimmick();

	// 更新処理
	void Update();
};
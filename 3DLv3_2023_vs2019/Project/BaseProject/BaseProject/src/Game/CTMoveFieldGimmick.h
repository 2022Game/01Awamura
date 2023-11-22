#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CTMoveField.h"

class CTMoveFieldGimmick : public CTask
{
private:
	std::vector<CTMoveField*> mTMoveField;	// クリア土台のリスト
	CModel* mpMoveTModel; //T字モデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateTMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpTMoveField;


public:
	CTMoveFieldGimmick();
	~CTMoveFieldGimmick();

	// 更新処理
	void Update();
};
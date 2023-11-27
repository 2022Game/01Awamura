#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CJMoveField.h"

class CJMoveFieldGimmick : public CTask
{
private:
	std::vector<CJMoveField*> mJMoveField;	// クリア土台のリスト
	CModel* mpMoveJModel; //T字モデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateJMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpJMoveField;


public:
	CJMoveFieldGimmick();
	~CJMoveFieldGimmick();

	// 更新処理
	void Update();
};
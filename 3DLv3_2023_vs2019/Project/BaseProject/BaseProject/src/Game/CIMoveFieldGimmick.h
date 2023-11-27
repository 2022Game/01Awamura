#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CIMoveField.h"

class CIMoveFieldGimmick : public CTask
{
private:
	std::vector<CIMoveField*> mIMoveField;	// クリア土台のリスト
	CModel* mpMoveIModel; //T字モデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateIMoveField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpIMoveField;


public:
	CIMoveFieldGimmick();
	~CIMoveFieldGimmick();

	// 更新処理
	void Update();
};
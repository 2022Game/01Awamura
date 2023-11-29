#pragma once
#include "CTask.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CBollField.h"

class CBollFieldGimmick : public CTask
{
private:
	std::vector<CBollField*> mBollField;	// クリア土台のリスト
	CModel* mpBollFieldModel;			// クリア土台のモデルデータ

	// 初期化処理
	void Init();
	// クリア土台を生成してリストに追加
	void CreateBollField(CModel* model, const CVector& pos, const CVector& scale);


	CModel* mpBollField;


public:
	CBollFieldGimmick();
	~CBollFieldGimmick();

	// 更新処理
	void Update();
};
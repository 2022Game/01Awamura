#ifndef CACLEARSTAGE_H
#define CACLEARSTAGE_H
#include "CTask.h"
#include "CACoinClearStage.h"
#include "CCollider.h"
#include "CColliderMesh.h"
#include "CColliderTriangle.h"
#include "CColliderLine.h"

class CAClearStage : public CTask
{
private:
	std::vector<CACoinClearStage*> mClearStages;	// コインのリスト
	CModel* mpCoinModel;			// コインのモデルデータ

	// 初期化処理
	void Init();
	// コインを生成してリストに追加
	void ClearStage(CVector& pos, CVector& rot, CVector& scale);
	//コライダ
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
	CColliderMesh mColliderMesh1;
	CColliderMesh mColliderMesh;

public:
	CAClearStage();
	~CAClearStage();
	//衝突処理
	//Collision(コライダ１、コライダ２）
	void Collision(CCollider* m, CCollider* o);
	void Collision();

	// 更新処理
	void Update();
};

#endif
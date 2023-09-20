#ifndef CAWOODGIMMICK_H
#define CAWOODGIMMICK_H
#include "CTask.h"
#include "CAWood.h"
#include "CColliderLine.h"

class CAWoodGimmick : public CTask
{
private:
	CColliderLine mColliderLine11;
	CColliderLine mColliderLine12;
	CColliderLine mColliderLine13;
	std::vector<CAWood*> mWoods;	// 木のリスト
	CModel* mpWoodModel;			// 木のモデルデータ
	int randnow;
	int randnow2;
	int randnow3;
	int randnow4;
	int randnow5;
	int randnow6;
	int randnow7;
	int randnow8;
	int randnow9;
	int randnow10;
	int randnow11;
	int randnow12;
	int randnow13;
	int randnow14;
	int randnow15;

	// 初期化処理
	void Init();
	// ハマーを生成してリストに追加
	void CreateWood(CVector& pos, CVector& rot, CVector& scale);

public:
	CAWoodGimmick();
	~CAWoodGimmick();

	// 更新処理
	void Update();
};

#endif
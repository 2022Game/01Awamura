#ifndef CAWOODGIMMICK_H
#define CAWOODGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAWood.h"

class CAWoodGimmick : public CTask
{
private:
	std::vector<CAWood*> mWoods;	// 木のリスト
	CModel* mpWoodModel;			// 木のモデルデータ

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
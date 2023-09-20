#ifndef CAWALLGIMMICK_H
#define CAWALLGIMMICK_H
#include "CTask.h"
//#include "CACoin.h"
#include "CAWall.h"

class CAWallGimmick : public CTask
{
private:
	std::vector<CAWall*> mWalls;	// コインのリスト
	CModel* mpWallModel;			// コインのモデルデータ

	// 初期化処理
	void Init();
	// ハマーを生成してリストに追加
	void CreateWall(CVector& pos, CVector& rot, CVector& scale);

public:
	CAWallGimmick();
	~CAWallGimmick();

	// 更新処理
	void Update();
};

#endif
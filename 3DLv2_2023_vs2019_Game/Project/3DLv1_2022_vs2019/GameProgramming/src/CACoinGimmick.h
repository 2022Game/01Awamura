#ifndef CACOINGIMMICK_H
#define CACOINGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAHamah.h"

class CACoinGimmick : public CTask
{
private:
	std::vector<CACoin*> mCoins;	// コインのリスト
	CModel* mpCoinModel;			// コインのモデルデータ

	// 初期化処理
	void Init();
	// コインを生成してリストに追加
	void CreateCoin(CVector& pos, CVector& rot, CVector& scale);
	void CreateCoinEnd(CVector& pos, CVector& rot, CVector& scale);

public:
	CACoinGimmick();
	~CACoinGimmick();

	// 更新処理
	void Update();
};

#endif
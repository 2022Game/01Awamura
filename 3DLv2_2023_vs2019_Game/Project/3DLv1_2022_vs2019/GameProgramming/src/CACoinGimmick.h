#ifndef CACOINGIMMICK_H
#define CACOINGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CCharacter.h"

class CACoinGimmick : public CTask ,public CCharacter
{
private:
	std::vector<CACoin*> mCoins;	// コインのリスト
	CModel* mpCoinModel;			// コインのモデルデータ
	int randnow;
	int randnow2;
	int randnow3;
	int randnow4;
	int randnow5;
	int randnow6;

	// 初期化処理
	void Init();
	// コインを生成してリストに追加
	void CreateCoin(CVector& pos, CVector& rot, CVector& scale);

public:
	CACoinGimmick();
	~CACoinGimmick();

	// 更新処理
	void Update();
};

#endif
#ifndef CAHAMAHGIMMICK_H
#define CAHAMAHGIMMICK_H
#include "CTask.h"
#include "CACoin.h"
#include "CAHamah.h"

class CAHamahGimmick : public CTask
{
private:
	std::vector<CAHamah*> mHamahs;	// ハマーのリスト
	CModel* mpHamahModel;			// ハマーのモデルデータ

	// 初期化処理
	void Init();
	// ハマーを生成してリストに追加
	void CreateHamah(CVector& pos, CVector& rot, CVector& scale);

public:
	CAHamahGimmick();
	~CAHamahGimmick();

	// 更新処理
	void Update();
};

#endif
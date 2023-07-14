#ifndef CAHAMAHGIMMICK_H
#define CAHAMAHGIMMICK_H
#include "CTask.h"
#include "CAHamah.h"

#define MODEL_FHAMAH "res\\apple2.obj","res\\apple2.mtl"

class CAHamahGimmick : public CTask
{
private:
	std::vector<CAHamah*> mHamahs;	// ハマーのリスト
	CModel* mpHamahModel;			// ハマーのモデルデータ
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
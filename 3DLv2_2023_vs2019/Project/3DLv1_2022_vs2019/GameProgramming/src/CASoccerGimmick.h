#ifndef CASOCCERGIMMICK_H
#define CASOCCERGIMMICK_H
#include "CTask.h"
#include "CASoccer.h"
#include "CColliderLine.h"

class CASoccerGimmick : public CTask
{
private:
	CColliderLine mColliderLine7;
	CColliderLine mColliderLine8;
	CColliderLine mColliderLine19;
	CColliderLine mColliderLine20;
	CColliderLine mColliderLine21;
	CColliderLine mColliderLine9;
	std::vector<CASoccer*> mSoccers;	// Soccerのリスト
	CModel* mpSoccerModel;			// Soccerのモデルデータ
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
	// Soccerを生成してリストに追加
	void CreateSoccer(CVector& pos, CVector& rot, CVector& scale);

public:
	CASoccerGimmick();
	~CASoccerGimmick();

	// 更新処理
	void Update();
};

#endif
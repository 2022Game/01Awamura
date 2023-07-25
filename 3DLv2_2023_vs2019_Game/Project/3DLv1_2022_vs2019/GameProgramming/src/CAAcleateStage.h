//#ifndef CAACLEATESTAGE_H
//#define CAACLEATESTAGE_H
//
//#include "CTask.h"
//#include "CACoinClearStage.h"
//#include "CCollider.h"
//#include "CColliderMesh.h"
//#include "CColliderTriangle.h"
//#include "CColliderLine.h"
//#include "CACoin.h"
//#include "CAHamah.h"
//#include "CASoccer.h"
//#include "CAWood.h"
//#include "CAWall.h"
//
//class CAAcleateStage : public CTask
//{
//private:
//	CColliderLine mColliderLine7;
//	CColliderLine mColliderLine8;
//	CColliderLine mColliderLine9;
//	std::vector<CASoccer*> mSoccers;	// Soccerのリスト
//	CModel* mpSoccerModel;			// Soccerのモデルデータ
//	std::vector<CAHamah*> mHamahs;	// ハマーのリスト
//	CModel* mpHamahModel;			// ハマーのモデルデータ
//	std::vector<CACoin*> mCoins;	// コインのリスト
//	CModel* mpCoinModel;			// コインのモデルデータ
//	std::vector<CAWall*> mWalls;	// 壁のリスト
//	CModel* mpWallModel;			//　壁のモデルデータ
//	std::vector<CAWood*> mWoods;	// 木のリスト
//	CModel* mpWoodModel;			// 木のモデルデータ
//	std::vector<CACoinClearStage*> mClearStages;	// コインのリスト
//	CModel* mpClearStageModel;			// コインのモデルデータ
//	int randnow;
//	int randnow2;
//	int randnow3;
//	int randnow4;
//	int randnow5;
//	int randnow6;
//	int randnow7;
//	int randnow8;
//	int randnow9;
//	int randnow10;
//
//	// 初期化処理
//	void Init();
//	// Soccerを生成してリストに追加
//	void CreateSoccer(CVector& pos, CVector& rot, CVector& scale);
//	// コインを生成してリストに追加
//	void CreateCoin(CVector& pos, CVector& rot, CVector& scale);
//	// ハマーを生成してリストに追加
//	void CreateHamah(CVector& pos, CVector& rot, CVector& scale);
//	// ハマーを生成してリストに追加
//	void CreateWall(CVector& pos, CVector& rot, CVector& scale);
//	// コインを生成してリストに追加
//	void ClearStage(CVector& pos, CVector& rot, CVector& scale);
//	// ハマーを生成してリストに追加
//	void CreateWood(CVector& pos, CVector& rot, CVector& scale);
//
//public:
//	CAAcleateStage();
//	~CAAcleateStage();
//
//	// 更新処理
//	void Update();
//};
//
//#endif
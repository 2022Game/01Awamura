#include "CAWallGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"

//神聖なる木
#define MODEL_FWALL "res\\Wall2.obj","res\\Wall2.mtl"

CAWallGimmick::CAWallGimmick()
{
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	CTaskManager::Instance()->Add(this);
}

CAWallGimmick::~CAWallGimmick()
{
	// ハマーのモデルデータを破棄
	if (mpWallModel != nullptr)
	{
		delete mpWallModel;
	}

	// ハマーを破棄
	for (int i = 0; i < mWalls.size(); i++)
	{
		delete mWalls[i];
	}
	// 一応リストもクリアしておく
	mWalls.clear();

	// タスクマネージャーから自身を取り除く
	CTaskManager::Instance()->Remove(this);
}

void CAWallGimmick::Init()
{
	// Wallのモデル読み込み
	/*mpWallModel = new CModel();
	mpWallModel->Load(MODEL_FWALL);*/
	mpWallModel = CApplication::Wall();

	// Wallを生成
	//ステージ１スタート生成
	if (CApplication::StageCount == 1)
	{
		CreateWall(CVector(10.0f, 22.9f, 1.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
	}
	////ステージ２スタート生成
	if (CApplication::StageCount == 2)
	{
		CreateWall(CVector(10.0f, 22.9f, 51.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
	}
	////ステージ３スタート生成
	if (CApplication::StageCount == 3)
	{
		CreateWall(CVector(10.0f, 22.9f, 100.5f), CVector(), CVector(1.8f, 5.8f, 2.8f));
	}
}

void CAWallGimmick::CreateWall(CVector& pos, CVector& rot, CVector& scale)
{
	if (mpWallModel == nullptr) return;

	// ハマーを生成してリストに追加
	CAWall* wall = new CAWall(mpWallModel, pos, rot, scale);
	mWalls.push_back(wall);
}

void CAWallGimmick::Update()
{
}
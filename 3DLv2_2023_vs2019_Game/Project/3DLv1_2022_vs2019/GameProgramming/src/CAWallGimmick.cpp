#include "CAWallGimmick.h"
#include "CTaskManager.h"
#include "CApplication.h"
#include "CResourceManager.h"

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
	mpWallModel = GET_MODEL("Wall");

	// Wallを生成
	//ステージ１スタート生成
	if (CApplication::StageCount == 0)
	{
		CreateWall(CVector(26.0f, 24.0f, 0.0f), CVector(), CVector(0.0f, 5.0f, 1500.0f));
		CreateWall(CVector(-1.3f, 24.0f, 0.0f), CVector(), CVector(0.0f, 5.0f, 1500.0f));
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
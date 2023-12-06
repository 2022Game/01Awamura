#include "CSlopeGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"



//int rand(void);
//void srand(unsigned int seed);

CSlopeGimmick::CSlopeGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CSlopeGimmick::~CSlopeGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mSlope.size(); i++)
	{
		mSlope[i]->Kill();
	}
	// 一応リストもクリアしておく
	mSlope.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CSlopeGimmick::Init()
{
	// 坂道土台のモデル読み込み
	mpSlopeModel = CResourceManager::Get<CModel>("Slope");
	// 坂道の土台を生成
	if (CField::mStageCount == 2)
	{
		
	}
}

void CSlopeGimmick::CreateSlope(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpSlopeModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CSlope* warp = new CSlope(mpSlopeModel, pos, scale);
	mSlope.push_back(warp);
}

void CSlopeGimmick::Update()
{

}
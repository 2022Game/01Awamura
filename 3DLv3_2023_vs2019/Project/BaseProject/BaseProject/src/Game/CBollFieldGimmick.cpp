#include "CBollFieldGimmick.h"
#include "CApplication.h"
#include "CTaskManager.h"
#include "CField.h"

#include <stdlib.h>

#include "time.h"

//int rand(void);
//void srand(unsigned int seed);

CBollFieldGimmick::CBollFieldGimmick()
{
	//srand((unsigned int)time(NULL));
	// 初期処理
	Init();

	// タスクマネージャーに自身を追加
	//CTaskManager::Instance()->Add(this);

	//mpColliderMesh = new CColliderMesh(this, ELayer::eClearObject, mpClearModel);
}

CBollFieldGimmick::~CBollFieldGimmick()
{
	//// クリア土台を破棄
	for (int i = 0; i < mBollField.size(); i++)
	{
		mBollField[i]->Kill();
	}
	// 一応リストもクリアしておく
	mBollField.clear();

	// タスクマネージャーから自身を取り除く
	//CTaskManager::Instance()->Remove(this);
}

void CBollFieldGimmick::Init()
{
	// クリア土台のモデル読み込み
	mpBollFieldModel = CResourceManager::Get<CModel>("Bollfield");

	if (CField::mStageCount == 4)
	{
		
	}
}

void CBollFieldGimmick::CreateBollField(CModel* model, const CVector& pos, const CVector& scale)
{
	if (mpBollFieldModel == nullptr) return;

	// クリア土台を生成してリストに追加
	CBollField* warp = new CBollField(mpBollFieldModel, pos, scale);
	mBollField.push_back(warp);
}

void CBollFieldGimmick::Update()
{

}
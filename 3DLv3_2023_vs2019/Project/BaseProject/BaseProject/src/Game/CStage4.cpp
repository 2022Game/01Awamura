#include "CStage4.h"
#include "CClearStage.h"
#include "CKillwood.h"
#include "CSidewood.h"
#include "CBollField.h"

//コンストラクタ
CStage4::CStage4()
{
	mStageNo = 4;
}

//デストラクタ
CStage4::~CStage4()
{

}

//ステージ読み込み
void CStage4::Load()
{
	// クリア土台のモデル読み込み
	CModel* clearStageModel = CResourceManager::Get<CModel>("Clearstage");

	//大木のモデル読み込み
	CModel* killwoodModel = CResourceManager::Get<CModel>("Killwood");

	//倒木のモデル読み込み
	CModel* sidewoodModel = CResourceManager::Get<CModel>("Sidewood");

	//円形土台のモデル読み込み
	CModel* bollFieldModel = CResourceManager::Get<CModel>("Bollfield");

	//クリア土台を作成
	CClearStage* coin = new CClearStage(clearStageModel,
		CVector(0.0f, 0.0f, -70.0f), CVector(1.0f, 1.0f, 1.0f));
	AddTask(coin);

	//大木を作成
	CKillwood* killwood = new CKillwood(killwoodModel,
		CVector(0.0f, 0.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		,0.0f);
	AddTask(killwood);

	//倒木を作成
	CSidewood* sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 15.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f)
		,0.0f);
	AddTask(sidewood);
	sidewood = new CSidewood(sidewoodModel,
		CVector(0.0f, 6.0f, -30.0f), CVector(5.5f, 5.0f, 5.25f)
		, 0.0f);
	AddTask(sidewood);

	//円形土台を作成
	CBollField* bollField = new CBollField(bollFieldModel,
		CVector(0.0f, -20.0f, -30.0f), CVector(5.0f, 5.0f, 5.0f));
	AddTask(bollField);
}

//ステージ破棄
void CStage4::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}
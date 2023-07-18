#include "CClearScene.h"
#include "main.h"
#include "CSceneManager.h"

//コンストラクタ
CClearScene::CClearScene()
	:CSceneBase(EScene::eTitle)
	, mBgImage(nullptr)
{
}

//デストラクタ
CClearScene::~CClearScene()
{

}

//シーン読み込み
void CClearScene::Load()
{
	//ここでタイトル画面に必要な
	//リソースの読み込みやクラスの生成を行u

	mBgImage = new CImage("Start.png");
	mBgImage->SetColor(1.0f, 1.0f, 0.0f, 1.0f);
	mBgImage->SetPos(0.0f, 0.0f);
	mBgImage->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//シーンの更新処理
void CClearScene::Update()
{
	if (mInput.PushKey(VK_RETURN))
	{
		CSceneManager::Instance()->LoadScene(EScene::eGame);
	}
	else
	{
		if (mBgImage != nullptr)
		{
			mBgImage->Render();
		}
	}
}
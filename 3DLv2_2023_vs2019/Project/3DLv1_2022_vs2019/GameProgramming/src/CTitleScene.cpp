#include "CTitleScene.h"
#include "main.h"
#include "CSceneManager.h"

//コンストラクタ
CTitleScene::CTitleScene()
	:CSceneBase(EScene::eTitle)
	,mBgImage(nullptr)
{
}

//デストラクタ
CTitleScene::~CTitleScene()
{

}

//シーン読み込み
void CTitleScene::Load()
{
	//ここでタイトル画面に必要な
	//リソースの読み込みやクラスの生成を行u

	mBgImage = new CImage("Start1.png");
	mBgImage->SetColor(1.0f, 1.0f, 0.0f, 1.0f);
	mBgImage->SetPos(0.0f, 0.0f);
	mBgImage->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//シーンの更新処理
void CTitleScene::Update()
{
	if (mInput.PushKey(VK_RETURN))
	{
		CApplication::StartCount = 1;
		CApplication::StageTime = 1;
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
#include "CSceneManager.h"
#include "CTitleScene.h"
#include "CGameScene.h"

CSceneManager* CSceneManager::mpInstance = nullptr;

//インスタンスを取得
CSceneManager* CSceneManager::Instance()
{
	//CSceneManager::Instance()->LoadScene(EScene::eGame); //使用例
	//インスタンスが存在しない場合は新しく生成する
	if (mpInstance == nullptr)
	{
		mpInstance = new CSceneManager();
	}
	return mpInstance;
}

//インスタンスを破棄
void CSceneManager::ClearInstance()
{
	delete mpInstance;
	mpInstance = nullptr;
}

//コンストラクタ
CSceneManager::CSceneManager()
	:mpScene(nullptr)
{

}

//デストラクタ
CSceneManager::~CSceneManager()
{
	//読み込んでいるシーンがあれば、破棄する
	UnloadScene();
}

//シーン読み込み
void CSceneManager::LoadScene(EScene scene)
{
	//すでにシーンが読み込まれていたら、
	//そのシーンを破棄
	UnloadScene();

	//読み込むシーンの種類に合わせて
	//生成するシーンのクラスを変更する
	switch (scene)
	{
		//タイトルシーン
	case EScene::eTitle: mpScene = new CTitleScene(); break;
		//ゲームシーン
	case EScene::eGame: mpScene = new CGameScene(); break;
	}

	//シーンを新しく生成できたら、
	//シーン読み込み開始
	if (mpScene != nullptr)
	{
		mpScene->Load();
	}
}

//読み込んでいるシーンを破棄
void CSceneManager::UnloadScene()
{
	delete mpScene;
	mpScene = nullptr;
}

//読み込んでいるシーンの更新処理
void CSceneManager::Update()
{
	//シーンが読み込まれていなければ、処理しない
	if (mpScene == nullptr)return;
	mpScene->Update();
}
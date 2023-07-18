#pragma once
#include "CSceneBase.h"
#include "CInput.h"
#include "CImage.h"
#include "CFont.h"

//タイトルシーン
class CClearScene : public CSceneBase
{
public:
	//コンストラクタ
	CClearScene();
	//デストラクタ
	~CClearScene();

	//シーン読み込み
	void Load();
	//シーンの更新処理
	void Update();

private:
	CInput mInput;
	CImage* mBgImage;
	CFont mFont;
};
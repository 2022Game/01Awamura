#include "CApplication.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"

#include "CCollisionManager.h"

#include "CBillBoard.h"
#include "CEnemy3.h"
#include "CCamera.h"

//クラスのstatic変数
CTexture CApplication::mTexture;
//CCamera CApplication::mCamera;

CUi* CApplication::spUi = nullptr;
CApplication::~CApplication()
{
	delete spUi;	//インスタンスUiの削除
}
CUi* CApplication::Ui()
{
	return spUi;
}

//#define MODEL_FILE2 "res\\knight\\knight_low.X" //敵

#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル
//モデルデータの指定
#define MODEL_OBJ "res\\f14.obj", "res\\f14.mtl"
//敵輸送機モデル
#define MODEL_C5 "res\\c5.obj", "res\\c5.mtl"

//背景モデルデータの指定
#define MODEL_BACKGROUND  "res\\sky.obj", "res\\sky.mtl"


//CTaskManager CApplication::mTaskManager;

//CTaskManager* CApplication::TaskManager()
//{
//	return &mTaskManager;
//}

//CCamera* CApplication::Camera()
//{
//	return &mCamera;
//}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{
	//カメラの設定
	mActionCamera.Set(5.0f, -15.0f, 180.0f);
	//3Dモデルファイルの読み込み
	mModelX.Load(MODEL_FILE);
	mKnight.Load("res\\knight\\knight_low.X");
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:移動
	mKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:待機
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//3ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//4ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//5だ三ー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//6だ、いー
	mKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7:attack1
	mKnight.SeparateAnimationSet(0, 520, 615, "attack2");//8:attack2
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//9:ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//10ダミー
	mKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:DOWN
	//キャラクタークラスの更新
	mXPlayer.Init(&mModelX);
	//敵の初期設定
	mXEnemy.Init(&mKnight);
	//敵の配置
	mXEnemy.Position(CVector(7.0f, 0.0f, 0.0f));
	mpPaladin = new CPaladin();
	mpPaladin->Position(CVector(-1.0f, 0.0f, 5.0f));
	mFont.Load("FontG.png", 1, 4096 / 64);
	AnimaScene = 0;
	AnimaFrame = 60;
	mXEnemy.ChangeAnimation(2, true, 200);
	mpPaladin->ChangeAnimation(1, true, 10);
}

void CApplication::Update()
{
	//色んなアニメーションを出す
	/*while (AnimaScene < mModelX.AnimationSet().size())
	{
		mCharacter.ChangeAnimation(AnimaScene, true, AnimaFrame);
		AnimaFrame--;
		if (AnimaFrame < 0)
		{
			AnimaFrame = 60;
			AnimaScene++;
		}
		if (AnimaScene == mModelX.AnimationSet().size())
		{
			AnimaScene = 0;
		}
		break;
	}*/
	//mModelX.AnimationSet().size();
	//キャラクタークラスの更新
	mpPaladin->Update();
	mXPlayer.Update();
	//敵の更新
	mXEnemy.Update();
	mInput.Update();
	/*mModelX.AnimationSet()[0]->Time(
		mModelX.AnimationSet()[0]->Time() + 1.0f);
	mModelX.AnimationSet()[0]->Time(
		(int)mModelX.AnimationSet()[0]->Time() %
		(int)(mModelX.AnimationSet()[0]->MaxTime() + 1));*/
	//最初のアニメーションの現在時間を４５にする
	//mModelX.AnimationSet()[0]->Time(); //課題１６で削除
	//最初のアニメーションの重みを1.0(100%)にする
	//mModelX.AnimationSet()[0]->Weight(1.0f);
	//フレームの変換行列をアニメーションで更新する
	mModelX.AnimateFrame();
	//フレームの合成行列を計算する
	//mModelX.Frames()[0]->AnimateCombined(&mMatrix);
	//カメラの設定
	mActionCamera.Position(mXPlayer.Position()
		+ CVector(0.0f, 2.0f, 0.0f));
	mActionCamera.Update();
	mActionCamera.Render();
	//モデルビュー行列の取得
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//逆行列の取得
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);

	//衝突処理
	CCollisionManager::Instance()->Collision();
	//頂点にアニメーションを適用する
	//mModelX.AnimateVertex();
	//モデル描画
	//mModelX.Render();
	mXPlayer.Render();
	//コライダの描画
	CCollisionManager::Instance()->Render();
	//敵の描画
	mXEnemy.Render();

	mpPaladin->Render();
	//2D描画開始
	CCamera::Start(0, 800, 0, 600);

	mFont.Draw(20, 20, 10, 12, "3D PROGRAMMING");

	//２D描画終了
	CCamera::End();
}

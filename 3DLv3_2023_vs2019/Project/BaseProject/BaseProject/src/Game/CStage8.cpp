#include "CStage8.h"
#include "CClearCube.h"
#include "CFloor.h"
#include "Maths.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CIceField.h"
#include "CCube.h"
#include "CGameManager.h"

//コンストラクタ
CStage8::CStage8()
{
	mStageNo = 8;
}

//デストラクタ
CStage8::~CStage8()
{

}

//壁にぶつかるまで移動して、通ったマスを移動ルートに設定する
int CStage8::PaveTheRoute(int x, int y, int moveX, int moveY)
{
	int moved = 0;

	//壁にぶつかるか、範囲外に出るまで繰り返す
	while (0 <= x && x < BLOCK_COUNT_X
		&& 0 <= y && y < BLOCK_COUNT_Y)
	{
		//現在のマスにブロックが配置されていたらループ終了
		if (mBlockData[x][y] == 1)break;
		
		//通れるマスであれば移動ルートに設定
		mBlockData[x][y] = 2;
		//次のマスへ移動
		x += moveX;
		y += moveY;
		//移動したマスの数を加算
		moved += abs(moveX) + abs(moveY);
	}

	return max(moved - 1,0);
}

//ブロックの配置データを作成
void CStage8::CreateBlockData()
{
	//ブロックの配置データを初期化
	memset(mBlockData, 0, sizeof(mBlockData));

	int x = 0; //横方向の現在位置
	int y = 0; //縦方向の現在位置

	//スタート位置から前方3列目にランダムで壁を配置する。
	x = Math::Rand(0, BLOCK_COUNT_X - 1);
	mBlockData[x][1] = 1;

	int moveX = 0; //左右の移動量
	int moveY = 1; //前後の移動量
	int moved = 0; //移動したマスの数

	//ゴールにたどり着くまで繰り返す
	while (true)
	{
		//壁にぶつかるまでまっすぐ進んで
		//mBlockDataに歩いたルートの場所に２を入れる
		moved = PaveTheRoute(x, y, moveX, moveY);
		//前回が縦方向の移動であれば、次は横方向の移動を行う
		if (moveX == 0)
		{
			//縦方向の現在位置に移動したマス分加算
			y += moved;

			//次は左右どちらに移動するかランダムに決定
			bool isLeft = Math::Rand(0, 1) == 0;
			//決定した方向に移動できるマスの数を求める
			moved = isLeft ? x - 1 : (BLOCK_COUNT_X - 1) - x - 1;
			//1マスも進めないのであれば、
			if (moved <= 0)
			{
				//移動方向を反転して、移動できるマスの数を再計算
				isLeft = !isLeft;
				moved = isLeft ? x - 1 : (BLOCK_COUNT_X - 1) - x - 1;
			}
			//各方向の移動量を設定
			//今回は左右の移動なので、前後の移動量は0にする
			moveX = isLeft ? -1 : 1;
			moveY = 0;

			//移動するマスの数をランダムで決定する
			moved = moved > 1 ? Math::Rand(1, moved) : moved;
			//移動先のマスにブロックを配置する
			mBlockData[x + moveX * (moved + 1)][y] = 1;
		}
		//前回が横方向の移動であれば、次は縦方向の移動を行う
		else
		{
			//横方向の現在位置に移動したマス分加算
			x += moveX * moved;
			//各咆哮の移動量を設定
			//今回は前移動なので、左右の移動量は０にする
			moveX = 0;
			moveY = 1;
			//移動できるマスの数を求める
			moved = (BLOCK_COUNT_Y - 1) - y;
			//移動できるマスの数が３マス以上であれば
			if (moved >= 3)
			{
				//壁を配置する
				moved = moved > 3 ? Math::Rand(2, moved - 1) : moved - 1;
				mBlockData[x][y + moved + 1] = 1;
			}
			//移動できるマスが２マス以下であれば
			else
			{
				//そのままゴールまでルートを設定して
				//このループを抜ける
				moved = PaveTheRoute(x, y, moveX, moveY);
				break;
			}
		}
	}

	//作成したブロックの配置データから情報を取得
	std::vector<int>emptyList; //何もないマスのリスト
	int blockCount = 0; //配置されている壁の数
	int routeCount = 0; //移動ルートが設定されているマスの数
	for (int i = 0; i < BLOCK_COUNT_X; i++)
	{
		for (int j = 0; j < BLOCK_COUNT_Y; j++)
		{
			if (mBlockData[i][j] == 0) emptyList.push_back(i * BLOCK_COUNT_Y + j);
			else if (mBlockData[i][j] == 1) blockCount++;
			//else if (mBlockData[i][j] == 2) routeCount++;
		}
	}
	
	for (int i = 0; i < BLOCK_COUNT_X; i++)
	{
		for (int j = 0; j < BLOCK_COUNT_Y; j++)
		{
			if (mBlockData[i][j] == 0) mBlockCheck++;
			if (mBlockCheck == BLOCK_COUNT_Y);
		}
	}

	//既に配置しているブロック数が最大値より小さいならば、
	//空いている場所にランダムでブロックを配置する
	if (blockCount < MAX_BLOCK_COUNT)
	{
		for (int i = 0; i < BLOCK_COUNT_X; i++)
		{
			int mBlockZeroCount = 0;
			for (int j = 0; j < BLOCK_COUNT_Y; j++)
			{
				if (mBlockData[i][j] == 0)
				{
					mBlockZeroCount++;
				}
			}
			if (BLOCK_COUNT_Y == mBlockZeroCount)
			{
				if (mBlockData[x][y] == 0)
				{
					//mBlockData[x][y] = 1;
				}
			}
			mBlockZeroCount = 0;
		}
		//新しく配置するブロックの数を求める
		int count = min(MAX_BLOCK_COUNT - blockCount, emptyList.size());
		for (int i = 0; i < count; i++)
		{
			int index = Math::Rand(0, emptyList.size() - 1);
			auto itr = emptyList.begin() + index;
			int ix = *itr / BLOCK_COUNT_Y;
			int iy = *itr % BLOCK_COUNT_Y;
			mBlockData[ix][iy] = 1;
			emptyList.erase(itr);
		}
	}

	//作成したブロックの配置データから
	//実際に配置する壁のオブジェクトを生成
	CModel* cubeModel = CResourceManager::Get<CModel>("Cube");
	for (int i = 0; i < BLOCK_COUNT_X; i++)
	{
		//配置するX座標を求める
		float posX = Math::Lerp(-100.0f, 100.0f, (float)i / (BLOCK_COUNT_X - 1));
		for (int j = 0; j < BLOCK_COUNT_Y; j++)
		{
			//配置する壁のZ座標を求める
			float posZ = Math::Lerp(-35.0f, -260.0f, (float)j / (BLOCK_COUNT_Y - 1));
		
			//何もない場所であれば、次のマスへ
			if (mBlockData[i][j] == 0)continue;
			if (mBlockData[i][j] == 2)continue;

			bool isRoute = mBlockData[i][j] == 2;
			float posY = isRoute ? -9.9f : 10.0f;

			//Cubeオブジェクトを作成
			CCube* cube = new CCube
			(
				cubeModel,
				CVector(posX, 10.0f, posZ), 
				CVector(0.5f, 4.0f, 0.5f)
			);

			CColor color = isRoute ? CColor::magenta : CColor::white;
			cube->SetColor(color);
			cube->SetEnableCol(!isRoute);

			AddTask(cube);
		}
	}
}

//ステージ読み込み
void CStage8::Load()
{
	//普通の足場読み込み
	CModel* floorModel = CResourceManager::Get<CModel>("FieldCube");

	//壁読み込み
	CModel* cubeModel = CResourceManager::Get<CModel>("Cube");

	//滑る足場読み込み
	CModel* icefieldModel = CResourceManager::Get<CModel>("IceField");

	// クリア土台のモデル読み込み
	CModel* clearCubeStageModel = CResourceManager::Get<CModel>("Clearcube");


	//普通の足場
	CFloor* floor = new CFloor(floorModel,
		CVector(0.0f, -10.0f, 0.0f), CVector(4.5f, 4.0f, 1.0f));
	AddTask(floor);

	//ブロックの配置データを作成
	CreateBlockData();

	//滑る足場
	CIceField* icefield = new CIceField(icefieldModel,
		CVector(0.0f, -10.0f, -150.0f), CVector(4.5f, 4.0f, 5.0f));
	AddTask(icefield);

	//クリア土台を作成
	CClearCube* coin = new CClearCube(clearCubeStageModel,
		CVector(0.0f, -10.0f, -300.0f), CVector(4.5f, 4.0f, 1.0f));
	AddTask(coin);

	//プレイヤーの開始位置を設定
	CPlayer* player = CPlayer::Instance();
	CVector playerPos = CVector(0.0f, 30.0f, 0.0f);
	if (player != nullptr)
	{
		player->SetStartPosition(playerPos);
	}

	//カメラの位置と向きを設定
	CCamera* mainCamera = CCamera::MainCamera();
	if (mainCamera != nullptr)
	{
		CVector eye = playerPos + CVector(0.0f, 375.0f, 130.0f);
		CVector at = playerPos;
		CVector forward = (at - eye).Normalized();
		CVector side = CVector::Cross(forward, CVector::back);
		CVector up = CVector::Cross(side, forward);
		mainCamera->LookAt(eye, at, up);
		mainCamera->SetFollowTargetTf(player);
	}
}

//ステージ破棄
void CStage8::Unload()
{
	//ベースのステージ破棄処理
	CStageBase::Unload();
}
#include "CFpenB.h"
#include "CApplication.h"

#define PENGIN 37,60,30,2	//テクスチャマッピング
#define PENGINL 7,29,62,34
#define PENGINL2 29,7,62,34
#define PENGINN 39,63,62,34
#define PENGINN2 63,39,62,34

#define VELOCITY2 -2.0f

void CFpenB::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CFpenB::Collision(CCharacter* m, CCharacter* o)
{
	//めり込み調整変数を宣言する
	float x, y;
	switch (o->Tag())
	{
	case ETag::EBLOCK2:
		//折り返しに当たった時
		if (CRectangle::Collision(o, &x, &y))
		{
			//めり込まない位置まで戻す
			X(X() + x);
			Y(Y() + y);
			//X軸速度を反転させる
			mVx = -mVx;
		}
		break;
	case ETag::EKABEX:
		if (CRectangle::Collision(o, &x, &y))
		{
			//めり込まない位置まで戻す
			X(X() + x);
			Y(Y() + y);
			//X軸速度を反転させる
			mVx = -mVx;
		}
		break;
	case ETag::EBLOCK3:
		if (CRectangle::Collision(o, &x, &y))
		{
			//めり込まない位置まで戻す
			X(X() + x);
			Y(Y() + y);
			//X軸速度を反転させる
			mVx = -mVx;
		}
		break;
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EBLOCK1:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EBLOCKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EBLOCKKK:
		if (CRectangle::Collision(o, &x, &y))
		{
			mEnabled = false;
		}
		break;
	case ETag::EKABEY:
		if (CRectangle::Collision(o, &x, &y))
		{
			//めり込まない位置まで戻す
			X(X() + x);
			Y(Y() + y);
			//X軸速度を反転させる
			mVx = -mVx;
		}
		break;
	case ETag::EPLAYER:
		if (CRectangle::Collision(o))
		{
		}
		break;
	}
}

CFpenB::CFpenB(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, PENGIN);
	mTag = ETag::EENEMY;
	//X軸速度の初期値を移動速度にする
	mVx = VELOCITY2;
}

void CFpenB::Update()
{
	switch (mState)
	{
	case EState::EMOVE:
		//X軸速度分、X座標を更新する
		X(X() - mVx);
		const int PITCH = 32;//画像を切り替える間隔
		if ((int)X() % PITCH < PITCH / 2)
		{
			if (mVx < 0.0f) //左へ移動
			{
				Texture(Texture(), PENGINN2);
			}
			else
			{
				//通常の画像を設定
				Texture(Texture(), PENGINN);
			}
		}
		else
		{
			if (mVx < 0.0f) //左へ移動
			{
				Texture(Texture(), PENGINL2);
			}
			else
			{
				//2番目の画像を設定
				Texture(Texture(), PENGINL);
			}
		}
		break;
	}
}
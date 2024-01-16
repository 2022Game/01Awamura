#include "CCleardelta.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "CGameManager.h"

bool CCleardelta::mMoveswitch = false;

CCleardelta::CCleardelta(CModel* model, const CVector& pos, const CVector& scale)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mMoveDir(0.0f, 0.0f, 0.0f)
	, mMoveSpeed(0.0f, 0.0f, 0.0f)
{
	mpColliderSphere = new CColliderSphere(this, ELayer::eMove, 1.0f, false, 100.0f);
	mpColliderSphere->Position(0.0f, -0.5f, 0.0f);
	//mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);

	mpColliderSphere->SetCollisionLayers({ELayer::eClearObject,ELayer::eMove});
}

CCleardelta::~CCleardelta()
{
	SAFE_DELETE(mpColliderSphere);
}

void CCleardelta::Update()
{
		//mMoveswitch = false;
		////ˆÚ“®‘¬“x‚É‡‚í‚¹‰ñ“]‚³‚¹‚é
		Rotate(0.0f, 1.0f, 0.0f);

		if (CGameManager::StageNo() == 4)
		{
		//d—Í‰ÁZ
		mMoveSpeed.Y(-10.0f);

		Position(Position() + mMoveSpeed * Time::DeltaTime());

		if (CPlayer::mResetCount == true)
		{
			Position(mDefaultPos);
			mMoveswitch = false;
			//Position(0.0f,0.0f,-30.0f);
			//mResetKillwood = true;
		}
	}
}

void CCleardelta::Collision(CCollider* self, CCollider* other, const CHitInfo& hit)
{
	if (self == mpColliderSphere)
	{
		if (other->Layer() == ELayer::eClearObject)
		{
			mMoveSpeed.Y(0.0f);
			Position(Position() + hit.adjust * hit.weight);
			mMoveswitch = true;
		}
	}
}

void CCleardelta::Render()
{
	mpModel->Render(Matrix());
}
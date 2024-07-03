#include "CMoveField.h"
#include "CCollider.h"
#include "CPlayer.h"
#include "Maths.h"
#include "CGameManager.h"

#define ROTATE_Y 0.1f

CMoveField::CMoveField(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mRotateSpeedY(rotateSpeedY)
	, randmodelspeedY(0.0f)
	, randmodelspeedY2(0.0f)
	, randmodelspeedYNo6(0.0f)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
	randmodelspeedY = Math::Rand(0.5f, 3.0f) * 0.5f;

	randmodelspeedY2 = Math::Rand(0.5f, 3.0f) * 0.5f;

	randmodelspeedYNo6 = Math::Rand(0.5f, 2.0f) * 0.5f;
}

CMoveField::~CMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CMoveField::Update()
{
	//ˆÚ“®
	mMoveSpeed = CVector(0.0f, 0.0f, 0.0f);

	Position(Position() + mMoveSpeed);

	if (CPlayer::mSwitchRObject == true)
	{
		Rotate(0.0f, randmodelspeedY, 0.0f);
	}
	if (CPlayer::mSwitchLObject == true)
	{
		Rotate(0.0f, -randmodelspeedY2, 0.0f);
	}
	else
	{
		Rotate(0.0f, 0.0f, 0.0f);
	}

	if (CGameManager::StageNo() == 6)
	{
		Rotate(0.0f, randmodelspeedYNo6, 0.0f);
	}
}

void CMoveField::Render()
{
	mpModel->Render(Matrix());
}
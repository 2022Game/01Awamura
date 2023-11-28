#include "CTMoveField.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"

CTMoveField::CTMoveField(CModel* model, const CVector& pos, const CVector& scale ,float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CTMoveField::~CTMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CTMoveField::Update()
{
	if (CPlayer::mSwitchRObject == true)
	{
		Rotate(0.0f, mRotateSpeedY, 0.0f);
	}
	if (CPlayer::mSwitchLObject == true)
	{
		Rotate(0.0f, -mRotateSpeedY, 0.0f);
	}
	else
	{
		Rotate(0.0f, 0.0f, 0.0f);
	}
}

void CTMoveField::Render()
{
	mpModel->Render(Matrix());
}
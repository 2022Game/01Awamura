#include "CIMoveField.h"
#include "Maths.h"
#include "CCollider.h"
#include "CPlayer.h"

CIMoveField::CIMoveField(CModel* model, const CVector& pos, const CVector& scale,float rotateSpeedY)
	: mpModel(model)
	, mDefaultPos(pos)
	, mElapsedTime(0.0f)
	, mRotateSpeedY(rotateSpeedY)
{
	mpColliderMesh = new CColliderMesh(this, ELayer::eField, mpModel, true);
	Position(mDefaultPos);
	Scale(scale);
}

CIMoveField::~CIMoveField()
{
	SAFE_DELETE(mpColliderMesh);
}

void CIMoveField::Update()
{
	////ˆÚ“®
	//mMoveSpeed = CVector(0.0f, 0.0f, 0.0f);

	//Position(Position() + mMoveSpeed);

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

void CIMoveField::Render()
{
	mpModel->Render(Matrix());
}
#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"
#include "CColliderLine.h"
#include "System.h"

class CAxe : public CRideableObject
{
public:
	CAxe(CModel* model, const CVector& pos, const CVector& scale
	,float rotateTime,float rotateAngle);
	~CAxe();

	void Update();
	void Render();

private:
	void SetClearColor(float r, float g, float b, float a);
	/// <summary>
	/// 画面のクリアカラーを設定（CColor）
	/// </summary>
	/// <param name="color">設定する色</param>
	//void SetClearColor(const CColor& color);
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	//テストライン
	CColliderLine* mpColliderLine2;
	CColliderLine* mpColliderLine3;
	CColliderLine* mpColliderLine4;
	CColliderLine* mpColliderLine22;
	CColliderLine* mpColliderLine33;
	CColliderLine* mpColliderLine44;

	CVector mDefaultPos;
	CVector mMoveVec;
	//斧の回転の１ループに掛かる時間
	float mRotateTime;
	//斧の回転角度(-mRotateAngle～mRotateAngleまで回転）
	float mRotateAngle;
	float mElapsedTime;
};
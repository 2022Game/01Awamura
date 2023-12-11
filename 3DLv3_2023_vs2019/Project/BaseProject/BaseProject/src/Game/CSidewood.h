#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"

class CSidewood : public CRideableObject
{
public:
	CSidewood(CModel* model, const CVector& pos, const CVector& scale, float rotateSpeedY);
	~CSidewood();

	void Update();
	void Render();

	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="self">衝突した自身のコライダー</param>
	/// <param name="other">衝突した相手のコライダー</param>
	/// <param name="hit">衝突した時の情報</param>
	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit) override;

private:
	int mTime;
	int Time;
	bool mIsGrounded;
	float randmodelspeedY;
	int randx;
	int mKillCount;
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;
	CColliderSphere* mpColliderSphere;

	CVector mDefaultPos;
	CVector mMoveVec;
	float mElapsedTime;
	float mRotateSpeedY;
	CVector mMove;
	float mMoveTime;
	//CVector mDefaultPos;
	//CVector mMoveVec;
	////斧の回転の１ループに掛かる時間
	//float mRotateTime;
	////斧の回転角度(-mRotateAngle～mRotateAngleまで回転）
	//float mRotateAngle;
	//float mElapsedTime;
	CVector mMoveSpeed;	// 移動速度
	CVector mMoveDir; // 移動方向
	//作成したタスクを追加
	void AddTask(CTask* task);
};
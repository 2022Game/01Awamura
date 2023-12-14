#pragma once
#include "CRideableObject.h"
#include "CModel.h"
#include "CColliderMesh.h"
#include "CCollider.h"
#include "CColliderSphere.h"

class CNeedle : public CRideableObject
{
public:
	CNeedle(CModel* model, const CVector& pos, const CVector& scale);
	~CNeedle();

	void Update();
	void Render();

	void Collision(CCollider* self, CCollider* other, const CHitInfo& hit) override;
private:
	CModel* mpModel;
	CColliderMesh* mpColliderMesh;

	CColliderSphere* mpColliderSphere;

	CVector mDefaultPos;
};
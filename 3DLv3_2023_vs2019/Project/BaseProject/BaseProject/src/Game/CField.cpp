#include "CField.h"

CField::CField()
	: CObjectBase(ETag::eField, ETaskPriority::eBackground)
{
	//仮のフィールドデータ　ピンクな背景モデルが有れば入れる
	mpModel = CResourceManager::Get<CModel>("Field");
}

CField::~CField()
{
}

void CField::Update()
{
}

void CField::Render()
{
	mpModel->Render(Matrix());
}

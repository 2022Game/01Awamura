#include "CField.h"

CField::CField()
	: CObjectBase(ETag::eField, ETaskPriority::eBackground)
{
	//���̃t�B�[���h�f�[�^�@�s���N�Ȕw�i���f�����L��Γ����
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

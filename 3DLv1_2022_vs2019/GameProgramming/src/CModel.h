#pragma once
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
#include "CVertex.h"
#ifndef CMODEL_H
#define CMODEL_H
/*
���f���N���X
���f���f�[�^�̓��͂�\��

*/
class CModel {
public:
	//���f���t�@�C���̓���
	//Load�i���f���t�@�C����,�}�e���A���t�@�C�����j
	void Load(char* obj, char* mtl);
	//�`��
	void Render();
	~CModel();
	//�`��
	//Render�y�s��j
	void Render(const CMatrix &m);
private:
	//���_�̔z��
	CVertex* mpVertexes;
	void CreateVertexBuffer();
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
	//�}�e���A���|�C���^�̉ϒ��z��
	std::vector<CMaterial*> mpMaterials;
};

#endif
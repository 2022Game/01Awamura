#pragma once
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
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
private:
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
};

#endif
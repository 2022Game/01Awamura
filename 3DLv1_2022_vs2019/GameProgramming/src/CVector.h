#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H

/*
�x�N�g���N���X
�x�N�g���f�[�^�������܂�
*/
class CVector {
public:
	//�e���ł̒l�̐ݒ�
	//Set(X���W,Y���W,Z���W�j
	void Set(float x, float y, float z);
	//X�̒l�𓾂�
	float X()const;
	//Y�̒l�𓾂�
	float Y()const;
	//Z�̒l�𓾂�
	float Z()const;
	//�f�t�H���g�R���g���N�^
	CVector();
	//�R���g���N�^
	//CVector(X���W,Y���W,Z���W�j
	CVector(float x, float y, float z);
private:
	//�RD�e���ł̒l��ݒ�
	float mX, mY, mZ;
};
#endif
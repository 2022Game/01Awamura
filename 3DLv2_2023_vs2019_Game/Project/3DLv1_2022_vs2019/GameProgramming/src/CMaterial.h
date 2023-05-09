#include "CTexture.h"
#ifndef CMATERIAL_H
#define CMATERIAL_H
#define MATERIAL_NAME_LEN 64//���O�̒���

/*
�}�e���A���N���X
�}�e���A���f�[�^������
*/
class CMaterial {
public:
	//�f�t�H���g�R���g���N�^
	CMaterial();
	//�}�e���A����L���ɂ���
	void Enabled();
	//�}�e���A���𖳌��ɂ���
	void Disabled();
	//�}�e���A���̖��O�̎擾
	char* Name();
	//�}�e���A���̖��O��ݒ肷��
	//Name(�}�e���A���̖��O�j
	void Name(char* name);
	//mDiffuse�z��̎擾
	float* Diffuse();
	//�e�N�X�`���̎擾
	CTexture* Texture();
	//���_���̐ݒ�
	//VertexNum�i���_���j
	void VertexNum(int num);
	//���_���̎擾
	int VertexNum();
private:
	//�e�N�X�`��
	CTexture mTexture;
	//�}�e���A����
	char mName[MATERIAL_NAME_LEN + 1];
	//�g�U���̐FRGBA
	float mDiffuse[4];
	//�}�e���A�����̒��_��
	int mVertexNum;
};

#endif

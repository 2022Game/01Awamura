#ifndef CMATRIX_H
#define CMATRIX_H
/*
�}�g���N�X�N���X
4��4��̍s��f�[�^�������܂�
*/
class CMatrix {
public:
	//�\���m�F�p
	//�S�~�S�̍s�����ʏo��
	void Print();
	//�f�t�H���g�R���X�g���N�^
	CMatrix();
	//�P�ʍs��̍쐬
	CMatrix Identity();
	//�g��k���s��̍쐬
	//Scale(�{��X,�{��Y,�{��Z�j
	CMatrix Scale(float sx, float sy, float sz);
	//�s��l�̎擾
	//M(�s,��j
	//mM[�s][��]���擾
	float M(int r, int c)const;
	//��]�s��iY���j�̍쐬
	//RotateY(�p�x�j
	CMatrix RotateY(float degree);
	//��]�s��iZ���j�̍쐬
	//RotateZ(�p�x�j
	CMatrix RotateZ(float degree);
	//��]�s��iX���j�̍쐬
	//RotateZ�i�p�x�j
	CMatrix RotateX(float degree);
	//�ړ��s��̍쐬
	//Translate(�ړ���X,�ړ���Y,�ړ���Z�j
	CMatrix Translate(float mx, float my, float mz);
	//�s��l�̑��
	//M�y�s��A�񐔁A�l�z
	void M(int row, int col, float value);
	//�����Z�q�̃I�[�o�[���[�h
	//CMatrix * CMatrix �̉��Z���ʂ�Ԃ�
	const CMatrix operator*(const CMatrix& m)const;
	//�s��̎擾
	float* M()const;
	//�t�s��擾
	CMatrix Transpose();
private:
	//�S�~�S�̍s��f�[�^��ݒ�
	float mM[4][4];
};
#endif
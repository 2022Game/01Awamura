#pragma once

class Cmy
{
private:
	float mX; //X���W
	float mY; //Y���W
	float mW; //��
	float mH; //����
public:
	//bool Collision(�l�p�`�̃|�C���^, X�����|�C���^,Y�����|�C���^)
	//�߂�l
	//true:�Փ˂��Ă���
	//false;�Փ˂��Ă��Ȃ�
	bool Collision(Cmy* pRect, float* ax, float* ay);
	Cmy();
	~Cmy();
	void Render();
	void Render(float x, float y, float w, float h);
	void Set(float x, float y, float w, float h);
	float X();
	float Y();
	float W();
	float H();
	void Y(float y);
	void X(float x);
	//bool Collision(�l�p�`�̃|�C���^)
	//�߂�l
	//true:�Փ˂��Ă���
	//false;�Փ˂��Ă��Ȃ�
	bool Collision(Cmy* pRect);
};
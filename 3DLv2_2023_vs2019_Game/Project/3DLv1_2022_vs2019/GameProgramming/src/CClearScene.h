#pragma once
#include "CSceneBase.h"
#include "CInput.h"
#include "CImage.h"
#include "CFont.h"

//�^�C�g���V�[��
class CClearScene : public CSceneBase
{
public:
	//�R���X�g���N�^
	CClearScene();
	//�f�X�g���N�^
	~CClearScene();

	//�V�[���ǂݍ���
	void Load();
	//�V�[���̍X�V����
	void Update();

private:
	CInput mInput;
	CImage* mBgImage;
	CFont mFont;
};
#include "CTitleScene.h"
#include "main.h"
#include "CSceneManager.h"

//�R���X�g���N�^
CTitleScene::CTitleScene()
	:CSceneBase(EScene::eTitle)
	,mBgImage(nullptr)
{

}

//�f�X�g���N�^
CTitleScene::~CTitleScene()
{

}

//�V�[���ǂݍ���
void CTitleScene::Load()
{
	//�����Ń^�C�g����ʂɕK�v��
	//���\�[�X�̓ǂݍ��݂�N���X�̐������s��
	mBgImage = new CImage("white.png");
	mBgImage->SetColor(1.0f, 0.0f, 0.0f, 1.0f);
	mBgImage->SetPos(0.0f, 0.0f);
	mBgImage->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//�V�[���̍X�V����
void CTitleScene::Update()
{
	if (mInput.PushKey(VK_SPACE))
	{
		CSceneManager::Instance()->LoadScene(EScene::eGame);
	}
	else
	{
		if (mBgImage != nullptr)
		{
			mBgImage->Render();
		}
	}
}
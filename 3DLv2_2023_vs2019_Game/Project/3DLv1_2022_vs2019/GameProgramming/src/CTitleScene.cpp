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
	//���\�[�X�̓ǂݍ��݂�N���X�̐������su

	mBgImage = new CImage("Start1.png");
	mBgImage->SetColor(1.0f, 1.0f, 0.0f, 1.0f);
	mBgImage->SetPos(0.0f, 0.0f);
	mBgImage->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//�V�[���̍X�V����
void CTitleScene::Update()
{
	if (mInput.PushKey(VK_RETURN))
	{
		CApplication::StartCount = 1;
		CApplication::StageTime = 1;
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
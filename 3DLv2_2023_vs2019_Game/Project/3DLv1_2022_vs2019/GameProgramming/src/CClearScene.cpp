#include "CClearScene.h"
#include "main.h"
#include "CSceneManager.h"

//�R���X�g���N�^
CClearScene::CClearScene()
	:CSceneBase(EScene::eTitle)
	, mBgImage(nullptr)
{
}

//�f�X�g���N�^
CClearScene::~CClearScene()
{

}

//�V�[���ǂݍ���
void CClearScene::Load()
{
	//�����Ń^�C�g����ʂɕK�v��
	//���\�[�X�̓ǂݍ��݂�N���X�̐������su

	mBgImage = new CImage("Start.png");
	mBgImage->SetColor(1.0f, 1.0f, 0.0f, 1.0f);
	mBgImage->SetPos(0.0f, 0.0f);
	mBgImage->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//�V�[���̍X�V����
void CClearScene::Update()
{
	if (mInput.PushKey(VK_RETURN))
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
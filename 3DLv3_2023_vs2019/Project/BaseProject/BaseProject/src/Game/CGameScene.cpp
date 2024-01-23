#include "CGameScene.h"
#include "CSceneManager.h"
#include "CField.h"
#include "CPlayer.h"
#include "CCamera.h"
#include "CField.h"
#include "Cinput.h"
#include "CStageManager.h"
#include "CGameManager.h"
#include "CGameMenu.h"
#include "CGameCamera.h"
#include "CGameCamera2.h"
#include "CBGMManager.h"

//�R���X�g���N�^
CGameScene::CGameScene()
	: CSceneBase(EScene::eGame)
	, mpGameMenu(nullptr)
{
}

//�f�X�g���N�^
CGameScene::~CGameScene()
{
}

//�V�[���ǂݍ���
void CGameScene::Load()
{
	// �w�i�F�ݒ�
	System::SetClearColor(0.1921569f, 0.3019608f, 0.4745098f, 1.0f);

	//�����ŃQ�[�����ɕK�v��
	//���\�[�X�̓ǂݍ��݂�N���X�̐������s��

	//�w�i
	//CResourceManager::Load<CModel>("Field", "Field\\Dublesky3.obj");
	CResourceManager::Load<CModel>("Field", "Field\\RainbowSphere.obj");
	//CResourceManager::Load<CModel>("Field", "Field\\Object\\Clearrainbow.obj");

	//�v���C���[
	CResourceManager::Load<CModelX>("Player", "Character\\Player\\Beardman.x");
	
	//�y��A��Q��
	CResourceManager::Load<CModel>("Stone", "Field\\Stone.obj");  //��
	CResourceManager::Load<CModel>("Ifield", "Field\\Object\\Ifield.obj"); //I���y��
	CResourceManager::Load<CModel>("Jfield", "Field\\Object\\Jfield.obj"); //J���y��
	CResourceManager::Load<CModel>("Lfield", "Field\\Object\\Lfield.obj"); //L���y��
	CResourceManager::Load<CModel>("Tenfield", "Field\\Object\\10field.obj"); //�\���y��
	CResourceManager::Load<CModel>("TenfieldPurple", "Field\\Object\\10fieldPurple.obj"); //�\���y��
	CResourceManager::Load<CModel>("TenfieldSkyblue", "Field\\Object\\10fieldSkyblue.obj"); //�\���y��
	CResourceManager::Load<CModel>("TenfieldYellow", "Field\\Object\\10fieldYellow.obj"); //�\���y��
	CResourceManager::Load<CModel>("Tfield", "Field\\Object\\Tfield.obj"); //T���y��
	CResourceManager::Load<CModel>("Axe", "Field\\ono7.obj"); //��
	CResourceManager::Load<CModel>("Bollfield", "Field\\bollfield2.obj"); //�~�`�y��
	CResourceManager::Load<CModel>("Clearcube", "Field\\Object\\Clearcube.obj"); //�N���A�l�p�y��
	CResourceManager::Load<CModel>("Clearstage", "Field\\Object\\cylinder.obj"); //�N���A�~�`�y��
	CResourceManager::Load<CModel>("Cube", "Field\\Object\\cube.obj"); //�l�p�y��
	CResourceManager::Load<CModel>("Killwood", "Field\\Killwood.obj"); //���
	CResourceManager::Load<CModel>("Sidewood", "Field\\Killbranc.obj"); //�|��
	CResourceManager::Load<CModel>("SideDownwood", "Field\\Killbranc2.obj"); //�㉺�ɓ����|��
	CResourceManager::Load<CModel>("Slope", "Field\\Object\\slopecube.obj"); //�⓹
	CResourceManager::Load<CModel>("Lswitch", "Field\\Object\\switchBlue.obj"); //���X�C�b�`
	CResourceManager::Load<CModel>("Rswitch", "Field\\Object\\switchRed.obj"); //�E�X�C�b�`
	CResourceManager::Load<CModel>("Warp", "Field\\WarpDoor2.obj"); //���[�v�h�A
	CResourceManager::Load<CModel>("Cleardelta", "Field\\Cleardelta.obj"); //�O�p�N���A��Q��
	CResourceManager::Load<CModel>("Needle", "Field\\Object\\needle.obj"); //�j
	CResourceManager::Load<CModel>("Transparent", "Field\\Object\\transparent.obj"); //�����p�y��
	CResourceManager::Load<CModel>("Cubecol", "Field\\Object\\cubecol.obj");
	CResourceManager::Load<CModel>("IceField", "Field\\IceField.obj");
	CResourceManager::Load<CModel>("Cube2", "Field\\Object\\Cube2.obj"); //�l�p��
	//CResourceManager::Load<CModel>("Rainbow12345", "Field\\Rainbow12345.obj");//�e�X�g�p

	CResourceManager::Load<CModel>("FieldCube", "Field\\Object\\cube.obj");
	CResourceManager::Load<CModel>("FieldCylinder", "Field\\Object\\cylinder.obj");
	
	CResourceManager::Load<CSound>("SlashSound", "Sound\\SE\\slash.wav");


	// �Q�[��BGM��ǂݍ���
	CBGMManager::Instance()->Play(EBGMType::eGame);
	// �Q�[��BGM��ǂݍ���
	//mpGameBGM = CResourceManager::Load<CSound>("GameBGM", "Sound\\BGM\\game.wav");
	// �Q�[��BGM�̃��[�v�͈͂�ݒ�
	//mpGameBGM->SetLoopRange(0, 2801203);
	// �Q�[��BGM�����[�v�Đ��J�n
	//mpGameBGM->PlayLoop();

	new CField();

	CPlayer* player = new CPlayer();
	//player->Scale(1.0f, 1.0f, 1.0f);

	//CGameCamera* mainCamera = new CGameCamera
	//CCamera* mainCamera = new CCamera
	//CGameCamera* mainCamera = new CGameCamera
	// CGameCamera�̃e�X�g
	//CGameCamera* mainCamera = new CGameCamera
	//(
	//	//CVector(5.0f, -15.0f, 180.0f),
	//	CVector(0.0f, 50.0f, 75.0f),
	//	player->Position()
	//);

	// CGameCamera2�̃e�X�g
	CVector atPos = player->Position() + CVector(0.0f, 10.0f, 0.0f);
	CGameCamera2* mainCamera = new CGameCamera2
	(
		atPos + CVector(0.0f, 0.0f, 40.0f),
		atPos
		////CVector(5.0f, -15.0f, 180.0f),
		//CVector(0.0f, 50.0f, 75.0f),
		//player->Position()
	);
	mainCamera->SetFollowTargetTf(player);

	//�Q�[���J�n����
	CGameManager::GameStart();

	// �Q�[�����j���[���쐬
	mpGameMenu = new CGameMenu();
}

//�V�[���̍X�V����
void CGameScene::Update()
{
	// BGM�Đ����łȂ���΁ABGM���Đ�
	//if (!mpGameBGM->IsPlaying())
	//{
	//	mpGameBGM->PlayLoop(-1, 1.0f, false, 1.0f);
	//}

	// �Q�[�����j���[���J���ĂȂ���΁A[�l]�L�[�Ń��j���[���J��
	if (!mpGameMenu->IsOpened())
	{
		if (CInput::PushKey('M'))
		{
			mpGameMenu->Open();
		}
	}
}

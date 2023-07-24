#include "CApplication.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"

#include "CCollisionManager.h"

#include "CBillBoard.h"
#include "CEnemy3.h"
#include "CCamera.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
//CCamera CApplication::mCamera;

CUi* CApplication::spUi = nullptr;
CApplication::~CApplication()
{
	delete spUi;	//�C���X�^���XUi�̍폜
}
CUi* CApplication::Ui()
{
	return spUi;
}

//#define MODEL_FILE2 "res\\knight\\knight_low.X" //�G

#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
//���f���f�[�^�̎w��
#define MODEL_OBJ "res\\f14.obj", "res\\f14.mtl"
//�G�A���@���f��
#define MODEL_C5 "res\\c5.obj", "res\\c5.mtl"

//�w�i���f���f�[�^�̎w��
#define MODEL_BACKGROUND  "res\\sky.obj", "res\\sky.mtl"


//CTaskManager CApplication::mTaskManager;

//CTaskManager* CApplication::TaskManager()
//{
//	return &mTaskManager;
//}

//CCamera* CApplication::Camera()
//{
//	return &mCamera;
//}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{
	//�J�����̐ݒ�
	mActionCamera.Set(5.0f, -15.0f, 180.0f);
	//3D���f���t�@�C���̓ǂݍ���
	mModelX.Load(MODEL_FILE);
	mKnight.Load("res\\knight\\knight_low.X");
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:�ړ�
	mKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:�ҋ@
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//3�_�~�[
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//4�_�~�[
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//5���O�[
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//6���A���[
	mKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7:attack1
	mKnight.SeparateAnimationSet(0, 520, 615, "attack2");//8:attack2
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//9:�_�~�[
	mKnight.SeparateAnimationSet(0, 10, 80, "walk");//10�_�~�[
	mKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:DOWN
	//�L�����N�^�[�N���X�̍X�V
	mXPlayer.Init(&mModelX);
	//�G�̏����ݒ�
	mXEnemy.Init(&mKnight);
	//�G�̔z�u
	mXEnemy.Position(CVector(7.0f, 0.0f, 0.0f));
	mpPaladin = new CPaladin();
	mpPaladin->Position(CVector(-1.0f, 0.0f, 5.0f));
	mFont.Load("FontG.png", 1, 4096 / 64);
	AnimaScene = 0;
	AnimaFrame = 60;
	mXEnemy.ChangeAnimation(2, true, 200);
	mpPaladin->ChangeAnimation(1, true, 10);
}

void CApplication::Update()
{
	//�F��ȃA�j���[�V�������o��
	/*while (AnimaScene < mModelX.AnimationSet().size())
	{
		mCharacter.ChangeAnimation(AnimaScene, true, AnimaFrame);
		AnimaFrame--;
		if (AnimaFrame < 0)
		{
			AnimaFrame = 60;
			AnimaScene++;
		}
		if (AnimaScene == mModelX.AnimationSet().size())
		{
			AnimaScene = 0;
		}
		break;
	}*/
	//mModelX.AnimationSet().size();
	//�L�����N�^�[�N���X�̍X�V
	mpPaladin->Update();
	mXPlayer.Update();
	//�G�̍X�V
	mXEnemy.Update();
	mInput.Update();
	/*mModelX.AnimationSet()[0]->Time(
		mModelX.AnimationSet()[0]->Time() + 1.0f);
	mModelX.AnimationSet()[0]->Time(
		(int)mModelX.AnimationSet()[0]->Time() %
		(int)(mModelX.AnimationSet()[0]->MaxTime() + 1));*/
	//�ŏ��̃A�j���[�V�����̌��ݎ��Ԃ��S�T�ɂ���
	//mModelX.AnimationSet()[0]->Time(); //�ۑ�P�U�ō폜
	//�ŏ��̃A�j���[�V�����̏d�݂�1.0(100%)�ɂ���
	//mModelX.AnimationSet()[0]->Weight(1.0f);
	//�t���[���̕ϊ��s����A�j���[�V�����ōX�V����
	mModelX.AnimateFrame();
	//�t���[���̍����s����v�Z����
	//mModelX.Frames()[0]->AnimateCombined(&mMatrix);
	//�J�����̐ݒ�
	mActionCamera.Position(mXPlayer.Position()
		+ CVector(0.0f, 2.0f, 0.0f));
	mActionCamera.Update();
	mActionCamera.Render();
	//���f���r���[�s��̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//�t�s��̎擾
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);

	//�Փˏ���
	CCollisionManager::Instance()->Collision();
	//���_�ɃA�j���[�V������K�p����
	//mModelX.AnimateVertex();
	//���f���`��
	//mModelX.Render();
	mXPlayer.Render();
	//�R���C�_�̕`��
	CCollisionManager::Instance()->Render();
	//�G�̕`��
	mXEnemy.Render();

	mpPaladin->Render();
	//2D�`��J�n
	CCamera::Start(0, 800, 0, 600);

	mFont.Draw(20, 20, 10, 12, "3D PROGRAMMING");

	//�QD�`��I��
	CCamera::End();
}

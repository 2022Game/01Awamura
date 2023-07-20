#pragma once
#include "CSceneBase.h"
#include "CAClearStage.h"
#include "CACoinClearStage.h"
#include "CACoin.h"
#include "CACoinGimmick.h"
#include "CAHamah.h"
#include "CAHamahGimmick.h"
#include "CAWood.h"
#include "CAWoodGimmick.h"
#include "CAWall.h"
#include "CAWallGimmick.h"
#include "CCharacterManager.h"
#include "CASoccerGimmick.h"
#include "CPlayer.h"

//�^�C�g���V�[��
class CGameScene : public CSceneBase
{
private:
	CColliderLine mColliderLine;
	CColliderLine mColliderLine2;
	CColliderLine mColliderLine3;
	CColliderLine mColliderLine4;
	CColliderLine mColliderLine5;
	CColliderLine mColliderLine6;
	CColliderLine mColliderLine7;
	CColliderLine mColliderLine8;
	CColliderLine mColliderLine9;
	CColliderLine mColliderLine10;
	CColliderTriangle mColliderTriangle;
	CColliderTriangle mColliderTriangle2;
	CColliderTriangle mColliderTriangle3;
	CColliderTriangle mColliderTriangle4;
	CColliderMesh mColliderMesh;
	CPlayer* player;
	CAClearStage* mpClearStage;
	CACoinGimmick* mpCoinGimmick;
	CAHamahGimmick* mpHamahGimmick;
	CAWallGimmick* mpWallGimmick;
	CAWoodGimmick* mpWoodGimmick;
	CASoccerGimmick* mpSoccerGimmick;
	CPlayer* mpPlayer;
	CModel mModelCoin;
	//Hamah���f��
	CModel mModelHamah;
	//Wall���f��
	CModel mModelWall;
	//Wood���f��
	CModel mModelWood;
public:
	//�R���X�g���N�^
	CGameScene();
	//�f�X�g���N�^
	~CGameScene();

	//�V�[���ǂݍ���
	void Load();
	//�V�[���̍X�V����
	void Update();
};
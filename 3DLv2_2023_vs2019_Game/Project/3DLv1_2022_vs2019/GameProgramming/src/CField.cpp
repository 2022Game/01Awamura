#include "CField.h"
#include "CTaskManager.h"

//�R���X�g���N�^
CField::CField()
{
	//�|�[�Y�̎�ނ�ݒ�
	SetPauseType(TaskPauseType::eGame);
	//�^�X�N�̗D��x�ݒ�
	mPriority = (int)TaskPriority::eBackground;
	//�^�X�N�}�l�[�W���[�Ɏ��M��ǉ�
	CTaskManager::Instance()->Add(this);

	//�w�i�̃��f���f�[�^�ǂ݂���
	mModel = new CModel();
	mModel->Load("res\\sky.obj", "res\\sky.mtl");
	//�ǂݍ��񂾔w�i�̃��f���f�[�^�ŃR���C�_���쐬
	mColliderMesh.Set(nullptr, nullptr, mModel);
}

//�f�X�g���N�^
CField::~CField()
{
	//�^�X�N�}�l�[�W���[���玩�M����菜��
	CTaskManager::Instance()->Remove(this);

	//�q�[�̃��f���Ł[����j��
	delete mModel;
	mModel = nullptr;
}

//�X�V����
void CField::Update()
{

}

//�`�揈��
void CField::Render()
{
	if (mModel == nullptr) return;
		//�q�[���f����`��
		mModel->Render();
}
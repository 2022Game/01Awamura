#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <ctype.h>
#include "CMatrix.h"
#include "CVertex.h"
/*
*IsDelimiter(c)
* c��\t\r\n�X�y�[�X�Ȃǂ̋󔒕���
* �܂���,:�Ȃǂ̕����ł����
* ��؂蕶���Ƃ���true��Ԃ�
*/
bool CModelX::IsDelimiter(char c)
{
	//isspace(c)
	//c���󔒕����Ȃ�O�ȊO��Ԃ�
	if (isspace(c) != 0)
		return true;
	/*
	strchr(������A�����j
	������ɕ������܂܂�Ă���΁A
	�������������ւ̃|�C���^��Ԃ�
	������Ȃ�������NULL��Ԃ�
	*/
	if (strchr(",;\"", c) != NULL)
		return true;
	//��؂蕶���ł͂Ȃ�
	return false;
}

/*
GetToken
������f�[�^����A�P����P�擾����
*/
char* CModelX::GetToken() {
	char* p = mpPointer;
	char* q = mToken;
	//�^�u(\t)��()���s(\r)(\n),:"�̋�؂蕶���ȊO�ɂȂ�܂œǂݔ�΂�
	while (*p != '\0' && IsDelimiter(*p))p++;
	if(*p == '{'|| *p == '}'){
		//{�܂���}�Ȃ�mToken�ɑ�������̕�����
		*q++ = *p++;
	}
	else {
		//�^�u(\t)�󔒁i�j���s(\r)(\n),�G"�̋�؂蕶���A
		//�܂��́A�p�̕����ɂȂ�܂ł�Token�ɑ������
		while (*p != '\0' && !IsDelimiter(*p) && *p != '}')
			*q++ = *p++;
	}
	*q = '\0'; //mToken�̍Ō��\0����
	mpPointer = p; //���̓ǂݍ��ރ|�C���g���X�V����

	//����mToken��//�̏ꍇ��,�R�����g�Ȃ̂ŉ��s�܂œǂݔ�΂�
	/*
	strcmp(������P�A������Q�j
	������P�ƕ�����Q���������ꍇ�A�O��Ԃ��܂��B
	������P�ƕ�����Q���������Ȃ��ꍇ�A�O�ȊO��Ԃ��܂��B
	*/
	if (!strcmp("//", mToken)) {
		//���s�܂œǂݔ�΂�
		while (*p != '\0' && !strchr("\r\n", *p))p++;
		//�ǂݍ��݈ʒu�̍X�V
		mpPointer = p;
		//�P����擾����(�ċA�Ăяo���j
		return GetToken();
	}
	return mToken;
}

CModelX::CModelX()
	:mpPointer(nullptr)
{
	//mToken��������
	memset(mToken, 0, sizeof(mToken));
}

CModelX::~CModelX()
{
	if (mFrame.size() > 0)
	{
		delete mFrame[0];
	}
}

CModelXFrame::~CModelXFrame()
{
}

//�R���X�g���N�^
CMesh::CMesh()
	:mVertexNum(0)
	,mpVertex(nullptr)
{}
//�f�X�g���N�^
CMesh::~CMesh() {
	SAFE_DELETE_ARRAY(mpVertex);
}

/*
Init
Mesh�̃f�[�^����荞��
*/
void CMesh::Init(CModelX* model) {
	int n;
	n = 0;
	model->GetToken(); //{or���O
	if (!strchr(model->Token(), '{')) {
		//���O�̏ꍇ,�����o
		model->GetToken();//�o
	}

	//���_���̎擾
	mVertexNum = atoi(model->GetToken());
	//���_�����G���A�m��
	mpVertex = new CVector[mVertexNum];
	//���_�����f�[�^����荞��
	for (int i = 0; i < mVertexNum; i++) {
		mpVertex[i].X(atof(model->GetToken()));
		mpVertex[i].Y(atof(model->GetToken()));
		mpVertex[i].Z(atof(model->GetToken()));
	}
#ifdef _DEBUG
	printf("VertexNum:%i\n", mVertexNum);
	while (n != mVertexNum)
	{
		printf("%f\t", mpVertex[n].X());
		printf("%f\t", mpVertex[n].Y());
		printf("%f\n", mpVertex[n].Z());
		n = n + 1;
	}
#endif
}

void CModelX::Load(char* file) {
	//
	//�t�@�C���T�C�Y���擾����
	//
	FILE* fp; //�t�@�C���|�C���^�ϐ��̍쐬
	fp = fopen(file, "rb"); //�t�@�C�����I�[�v������
	if (fp == NULL) { //�G���[�`�F�b�N
		printf("fopen error:%s\n", file);
		return;
	}
	//�t�@�C���̍Ō�ֈړ�
	fseek(fp, 0L, SEEK_END);
	//�t�@�C���T�C�Y�̎擾
	int size = ftell(fp);
	//�t�@�C���T�C�Y+�P�o�C�g���̗̈���m��
	char* buf = mpPointer = new char[size + 1];
	//
	//�t�@�C������RD���f���̃f�[�^��ǂݍ���
	//
	//�t�@�C���̐擪�ֈړ�
	fseek(fp, 0L, SEEK_SET);
	//�m�ۂ����̈�Ƀt�@�C���T�C�Y���f�[�^��ǂݍ���
	fread(buf, size, 1, fp);
	//�Ō��\0��ݒ肷��i������̏I�[�j
	buf[size] = '\0';
	fclose(fp); //�t�@�C�����N���[�Y����
	//printf("%s", buf);
	//������̍Ō�܂ŌJ��Ԃ�
	while (*mpPointer != '\0') {
		GetToken(); //�P��̎擾
		//�P�ꂪFrame�̏ꍇ
		if (strcmp(mToken, "Frame") == 0) {
		   //�t���[�����쐬����
			new CModelXFrame(this);
		}
	}
	SAFE_DELETE_ARRAY(buf); //�m�ۂ����̈���J������
}

/*
SkipNode
�m�[�h��ǂݔ�΂�
*/
void CModelX::SkipNode() {
	//�������I�������I��
	while (*mpPointer != '\0') {
		GetToken(); //���̒P��擾
		//{�����������烋�[�v�I��
		if (strchr(mToken, '{'))break;
	}
	int count = 1;
	//�������I��邩�A�J�E���g���O�ɂȂ�����I��
	while (*mpPointer != '\0' && count > 0) {
		GetToken(); //���̒P��擾
		//{��������ƃJ�E���g�A�b�v
		if (strchr(mToken, '{'))count++;
		//}��������ƃJ�E���g�_�E��
		else if (strchr(mToken, '}'))count--;
	}
}

char* CModelX::Token()
{
	return mToken;
}

/*
CModelXFrame
model:CModelX�C���X�^���X�ւ̃|�C���^
�t���[�����쐬����
�ǂݍ��ݒ���Frame��������΁A�t���[�����쐬���A
�q�t���[���ɒǉ�����
*/
CModelXFrame::CModelXFrame(CModelX* model)
	:mpName(nullptr)
	,mpMesh(nullptr)
	, mIndex(0)
{
	//���݂̃t���[���z��̗v�f�����擾���ݒ肷��
	mIndex = model->mFrame.size();
	//CModelX�̃t���[���z��ɒǉ�����
	model->mFrame.push_back(this);
	//�ϊ��s���P�ʍs��ɂ���
	mTransformMatrix.Identity();
	//���̒P��i�t���[�����̗\��j���擾����
	model->GetToken(); //frame name
	//�t���[�������G���A���m�ۂ���
	mpName = new char[strlen(model->mToken) + 1];
	//�t���[�������R�s�[����
	strcpy(mpName, model->mToken);
	//���̒P��({�̗\��j���擾����
	model->GetToken(); //�o
	//�����������Ȃ�����I���
	while (*model->mpPointer != '\0') {
		//���̒P��擾
		model->GetToken(); //Frame
		//�p�������̏ꍇ�͏I��
		if (strchr(model->mToken, '}'))break;
		//�V���ȃt���[���̏ꍇ�́A�q�t���[���ɒǉ�
		if (strcmp(model->mToken, "Frame") == 0) {
			//�t���[�����쐬���A�q�t���[���̔z��ɒǉ�
			mChild.push_back(new CModelXFrame(model));
		}
		else if(strcmp(model->mToken, "FrameTransformMatrix") == 0) {
			model->GetToken(); //{
				for (int i = 0; i < mTransformMatrix.Size(); i++) {
					mTransformMatrix.M()[i] = atof(model->GetToken());
				}
				model->GetToken();//}
		}
		else if (strcmp(model->mToken, "Mesh") == 0) {
			mpMesh = new CMesh();
			mpMesh->Init(model);
		}
		else {
			//��L�ȊO�̗v�f�͓ǂݔ�΂�
			model->SkipNode();
		}
	}
	//�f�o�b�O�o�[�W�����̂ݗL��
#ifdef _DEBUG
	//printf("%s\n", mpName);
	//printf("%f\t", mTransformMatrix.M()[0]);
	//printf("%f\t", mTransformMatrix.M()[1]);
	//printf("%f\t", mTransformMatrix.M()[2]);
	//printf("%f\n", mTransformMatrix.M()[3]);
	//printf("%f\t", mTransformMatrix.M()[4]);
	//printf("%f\t", mTransformMatrix.M()[5]);
	//printf("%f\t", mTransformMatrix.M()[6]);
	//printf("%f\n", mTransformMatrix.M()[7]);
	//printf("%f\t", mTransformMatrix.M()[8]);
	//printf("%f\t", mTransformMatrix.M()[9]);
	//printf("%f\t", mTransformMatrix.M()[10]);
	//printf("%f\n", mTransformMatrix.M()[11]);
	//printf("%f\t", mTransformMatrix.M()[12]);
	//printf("%f\t", mTransformMatrix.M()[13]);
	//printf("%f\t", mTransformMatrix.M()[14]);
	//printf("%f\n", mTransformMatrix.M()[15]);
#endif
}


#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <ctype.h>
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
		    printf("%s", mToken); //Frame�o��
			GetToken(); //Frame�����擾
			printf("%s\n", mToken); //Frame�����o��
		}
		//AnimationSet�̏ꍇ
		if (strcmp(mToken, "AnimationSet") == 0) {
			printf("%s", mToken);
			GetToken();
			printf("%s\n", mToken); 
		}
	}
	SAFE_DELETE_ARRAY(buf); //�m�ۂ����̈���J������
}
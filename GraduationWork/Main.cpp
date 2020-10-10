#include "lib/UrLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);	//�E�B���h�E���[�h�ɂ���
	SetGraphMode(800, 600, 32);	//�E�B���h�E�T�C�Y��ݒ肷��

	if (UrLib::Init() < 0)		// UR���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);	//����ʂ�`��Ώۂ�

	//���C������
	UrLib::Update();

	UrLib::End();			// UR���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

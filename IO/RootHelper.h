#pragma once
#include "AdminMap.h"
#include "Root.h"
#include <cstring>
class RootHelper
{
public:
	RootHelper() {}
	bool Login(const char* password);
	bool Logout();
	//************************************
	// ������ : TestPassword
	// ��  �� : ��������
	// ����ֵ : bool : �Ƿ�ɹ�
	// ��  �� : const char * password : ���Ե�����
	//************************************
	bool TestPassword(const char* password);
	//************************************
	// ������ : ChangePassword
	// ��  �� : �޸�����
	// ����ֵ : bool : �Ƿ�ɹ�
	// ��  �� : const char * oldpw : ԭ����
	// ��  �� : const char * newpw : ������
	//************************************
	bool ChangePassword(const char* oldpw, const char* newpw);
	//************************************
	// ������ : AddAdmin
	// ��  �� : ���ͼ�����Ա
	// ����ֵ : ID : ���ɵ�ͼ�����Ա���
	// ��  �� : const char * name : ͼ�����Ա�û���
	// ��  �� : const char * password : ͼ�����Ա����
	//************************************
	ID AddAdmin(const char * name, const char * password);
	//************************************
	// ������ : RemoveAdmin
	// ��  �� : �Ƴ�ͼ�����Ա
	// ����ֵ : bool : �Ƿ�ɹ�
	// ��  �� : const ID id : ͼ�����Ա���
	//************************************
	bool RemoveAdmin(const ID id);
	const char * GetAdminName(const ID id);
	//************************************
	// ������ : Save
	// ��  �� : �������ļ�
	// ����ֵ : bool : �Ƿ�ɹ�
	//************************************
	bool Save()const;
private:
	const char*adminMapPath{ "admin" };
	const char*rootPath{ "root" };
	Root root{ Root::ReadRoot(rootPath) };
	AdminMap adminMap{ AdminMap::ReadMap(adminMapPath) };
	bool Loggedin{ false };
};


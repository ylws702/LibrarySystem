#pragma once
#include <fstream>
using namespace std;
typedef long long unsigned ID;
class Root
{
	friend class RootHelper;
	Root();
	bool SetName(const char *name);
	bool SetPassword(const char *password);
	char name[16];
	char password[32];
	static Root ReadRoot(const char* path);
	//������:
	//path:�б�Ҫ����ĵ�ַ
	//����ֵ:
	//�ļ�����ɹ�����true,ʧ�ܷ���false
	bool WriteRoot(const char* path)const;
};


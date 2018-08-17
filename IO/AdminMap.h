#pragma once
#include "Admin.h"
#include <map>
#include <fstream>
using namespace std;
class AdminMap
{
	friend class AdminHelper;
	friend class RootHelper;
	AdminMap() {}
	bool Add(const Admin& admin);
	bool Delete(const ID id);
	bool Find(const ID id, Admin& result)const;
	bool Find(const char* name, Admin& result)const;
	static AdminMap ReadMap(const char* path);
	//������:
	//path:�б�Ҫ����ĵ�ַ
	//����ֵ:
	//�ļ�����ɹ�����true,ʧ�ܷ���false
	bool WriteMap(const char* path)const;
	map<ID, Admin> adminMap;
};


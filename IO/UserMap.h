#pragma once
#include <map>
#include <fstream>
#include <cstring>
#include "User.h"
class UserMap
{
	friend class UserHelper;
	friend class AdminHelper;
	UserMap() {}
	bool Add(const User& user);
	bool Delete(ID id);
	bool Find(ID id, User& result)const;
	bool Find(const char* name, User& result)const;
	static UserMap ReadMap(const char* path);
	//������:
	//path:�б�Ҫ����ĵ�ַ
	//����ֵ:
	//�ļ�����ɹ�����true,ʧ�ܷ���false
	bool WriteMap(const char* path)const;
	//DEBUG�ú���,����ʱɾ��
	//void Print();
	map<ID, User> userMap;
};


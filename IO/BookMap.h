#pragma once
#include "Book.h"
#include <map>
#include <fstream>
using namespace std;
class BookMap
{
	friend class UserHelper;
	friend class AdminHelper;
	BookMap() {}
	bool Add(const Book& book);
	bool Delete(ID id);
	static BookMap ReadMap(const char* path);
	//������:
	//path:�б�Ҫ����ĵ�ַ
	//����ֵ:
	//�ļ�����ɹ�����true,ʧ�ܷ���false
	bool WriteMap(const char* path)const;
	map<ID, Book> bookMap;
//public:
//	//DEBUG�ú���,����ʱɾ��111
//	void Print();
};


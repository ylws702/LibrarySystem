#pragma once
#include "AdminMap.h"
#include "UserMap.h"
#include "BookMap.h"
#include <cstring>
#include <list>
class AdminHelper
{
public:
	//Ĭ�Ϲ��캯��
	AdminHelper() {}
	//************************************
	// ������ : Login
	// ��  �� : ��¼
	// ����ֵ : bool : �Ƿ�ɹ�,ʧ�ܿ�����Ϊ�ñ�ŵ�ͼ�����Ա������
	//                ���û�������ȷ�����벻��ȷ
	// ��  �� : const ID id : ���
	// ��  �� : const char * name : �û���
	// ��  �� : const char * password : ����
	//************************************
	bool Login(const ID id,const char * name, const char* password);
	//************************************
	// ������ : Logout
	// ��  �� : ע��
	// ����ֵ : bool : �Ƿ�ɹ�
	//************************************
	bool Logout();
	//************************************
	// ������ : TestPassword
	// ��  �� : ��֤password�Ƿ�Ϊ��ǰ��¼ͼ�����Ա������
	// ����ֵ : bool : �����Ƿ���֤�ɹ�,δ��¼�᷵��false
	// ��  �� : const char * password : Ҫ��֤������
	//************************************
	bool TestPassword(const char* password);
	//************************************
	// ������ : ChangePassword
	// ��  �� : ��������,���Զ��������ļ�
	// ����ֵ : bool : �Ƿ�ɹ�,ʧ�ܿ�����Ϊδ��¼�������������д���ļ�ʧ��
	// ��  �� : const char * oldpw : ������
	// ��  �� : const char * newpw : ������
	//************************************
	bool ChangePassword(const char* oldpw, const char* newpw);
	//************************************
	// ������ : AddBook
	// ��  �� : ʹ��ȫ����Ϣ���ͼ��
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��ͼ�������б��л���Ϣ�ַ��������᷵��false
	// ��  �� : const ID id : ���
	// ��  �� : const char * title : ����
	// ��  �� : const char * author : ����
	// ��  �� : const char * press : ������
	// ��  �� : const char * date : ��������
	// ��  �� : const char * type : ����
	// ��  �� : const int number : ����
	//************************************
	bool AddBook(const ID id, 
		const char* title,
		const char* author,
		const char* press,
		const char* date,
		const char* type,
		const int number);
	//************************************
	// ������ : RemoveBook
	// ��  �� : ɾ��ָ����ŵ�ͼ�鲢ɾ����Ӧ���û����ļ�¼
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��false
	// ��  �� : const ID id : ͼ����
	//************************************
	bool RemoveBook(const ID id);
	//************************************
	// ������ : RemoveAllBooks
	// ��  �� : ɾ������ͼ�鲢ɾ�������û����ļ�¼
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��᷵��false
	//************************************
	bool RemoveAllBooks();
	//************************************
	// ������ : GetBookTitle
	// ��  �� : ��ȡָ����ŵ�ͼ��ı���
	// ����ֵ : const char* : ����,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetBookTitle(const ID id)const;
	//************************************
	// ������ : GetBookAuthor
	// ��  �� : ��ȡָ����ŵ�ͼ�������
	// ����ֵ : const char* : ����,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetBookAuthor(const ID id)const;
	//************************************
	// ������ : GetBookPress
	// ��  �� : ��ȡָ����ŵ�ͼ��ĳ�����
	// ����ֵ : const char* : ������,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetBookPress(const ID id)const;
	//************************************
	// ������ : GetBookDate
	// ��  �� : ��ȡָ����ŵ�ͼ��ĳ�������
	// ����ֵ : const char* : ��������,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetBookDate(const ID id)const;
	//************************************
	// ������ : GetBookType
	// ��  �� : ��ȡָ����ŵ�ͼ�������
	// ����ֵ : const char* : ����,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetBookType(const ID id)const;
	//************************************
	// ������ : GetBookExist
	// ��  �� : ��ȡָ����ŵ�ͼ���Ƿ��ڹ���
	// ����ֵ : bool : �Ƿ��ڹ���,δ��¼�᷵��false
	// ��  �� : const ID id : ���
	//************************************
	bool GetBookExist(const ID id)const;
	//************************************
	// ������ : SetBookTitle
	// ��  �� : ����ָ����ŵ�ͼ��ı���
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼���������᷵��false
	// ��  �� : const ID id : ���
	// ��  �� : const char * title : ����
	//************************************
	bool SetBookTitle(const ID id,const char* title);
	//************************************
	// ������ : SetBookAuthor
	// ��  �� : ����ָ����ŵ�ͼ�������
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼�������������᷵��false
	// ��  �� : const ID id : ���
	// ��  �� : const char * author : ����
	//************************************
	bool SetBookAuthor(const ID id, const char* author);
	//************************************
	// ������ : SetBookPress
	// ��  �� : ����ָ����ŵ�ͼ��ĳ�����
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��������������᷵��false
	// ��  �� : const ID id : ���
	// ��  �� : const char * press : ������
	//************************************
	bool SetBookPress(const ID id, const char* press);
	//************************************
	// ������ : SetBookDate
	// ��  �� : ����ָ����ŵ�ͼ��ĳ�������
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��������ڹ����᷵��false
	// ��  �� : const ID id : ���
	// ��  �� : const char * date : ��������
	//************************************
	bool SetBookDate(const ID id, const char* date);
	//************************************
	// ������ : SetBookType
	// ��  �� : ����ָ����ŵ�ͼ�������
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼�����͹����᷵��false
	// ��  �� : const ID id : ���
	// ��  �� : const char * type : ����
	//************************************
	bool SetBookType(const ID id, const char* type);
	//************************************
	// ������ : GetBookRestCount
	// ��  �� : ��ȡָ����ŵ�ͼ��Ĺ���ʣ����
	// ����ֵ : unsigned int : ����ʣ����,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��0
	// ��  �� : const ID id : ���
	//************************************
	unsigned int GetBookRestCount(const ID id)const;
	//************************************
	// ������ : GetBookTotalCount
	// ��  �� : ��ȡָ����ŵ�ͼ�������
	// ����ֵ : unsigned int : ͼ������,δ��¼��ָ����ŵ�ͼ�鲻���ڻ᷵��0
	// ��  �� : const ID id : ���
	//************************************
	unsigned int GetBookTotalCount(const ID id)const;
	//************************************
	// ������ : GetAllBooks
	// ��  �� : ��ȡȫ��ͼ����
	// ����ֵ : std::list<ID> : ȫ��ͼ��������,δ��¼�᷵�ؿ�����
	//************************************
	list<ID> GetAllBooks()const;
	//************************************
	// ������ : GetBorrowedBooks
	// ��  �� : ��ȡȫ���н����ͼ����
	// ����ֵ : std::list<ID> : �н����ͼ��������,δ��¼�᷵�ؿ�����
	//************************************
	list<ID> GetBorrowedBooks()const;
	//************************************
	// ������ : GetNotBorrowedBooks
	// ��  �� : ��ȡȫ��δ�����ͼ����
	// ����ֵ : std::list<ID> : δ�����ͼ��������,δ��¼�᷵�ؿ�����
	//************************************
	list<ID> GetNotBorrowedBooks()const;
	//************************************
	// ������ : AddUser
	// ��  �� : ʹ��ȫ����Ϣ�����ͨ�û�
	// ����ֵ : bool : �Ƿ�ɹ�
	// ��  �� : const ID id : �Ƿ�ɹ�,δ��¼���û��Ѵ����л���Ϣ�ַ��������᷵��false
	// ��  �� : const char * name : �û���
	// ��  �� : const char * password : ����
	// ��  �� : const int gender : �Ա�
	// ��  �� : const int type : ����
	//************************************
	bool AddUser(const ID id,
		const char * name,
		const char * password,
		const int gender,
		const int type);
	//************************************
	// ������ : RemoveUser
	// ��  �� : ɾ��ָ����ŵ��û�
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��ָ����ŵ��û������ڻ᷵��false
	// ��  �� : const ID id : �û����
	//************************************
	bool RemoveUser(const ID id);
	//************************************
	// ������ : GetUserName
	// ��  �� : ��ȡָ����ŵ��û���
	// ����ֵ : const char* : �û���,δ��¼��ָ����ŵ��û������ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetUserName(const ID id);
	//************************************
	// ������ : GetUserGender
	// ��  �� : ��ȡָ����ŵ��û��Ա�
	// ����ֵ : const char* : �Ա�,δ��¼��ָ����ŵ��û������ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetUserGender(const ID id);
	//************************************
	// ������ : GetUserType
	// ��  �� : ��ȡָ����ŵ��û�����
	// ����ֵ : const char* : ����,δ��¼��ָ����ŵ��û������ڻ᷵��nullptr
	// ��  �� : const ID id : ���
	//************************************
	const char* GetUserType(const ID id);
	//************************************
	// ������ : ReportLoss
	// ��  �� : ��ָ����ŵ��û���ʧ,ʹ���޷���¼
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��ָ����ŵ��û������ڻ᷵��false
	// ��  �� : const ID id : ���
	//************************************
	bool ReportLoss(const ID id);
	//************************************
	// ������ : UndoReportLoss
	// ��  �� : ���ָ������û��Ĺ�ʧ,ʹ���ܹ���¼
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��ָ����ŵ��û������ڻ᷵��false
	// ��  �� : const ID id : ���
	//************************************
	bool UndoReportLoss(const ID id);
	//************************************
	// ������ : Accept
	// ��  �� : ���ջ���
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼��ָ����ŵ��û������ڻ�ָ����ŵ�ͼ�鲻���ڻ᷵��false
	// ��  �� : const ID userID : �û����
	// ��  �� : const ID bookID : ͼ����
	//************************************
	bool Accept(const ID userID, const ID bookID);
	//************************************
	// ������ : Save
	// ��  �� : ��ͼ�����Ա��Ϣ,�û���Ϣ��ͼ����Ϣ�������ļ�
	// ����ֵ : bool : �Ƿ�ɹ�,δ��¼���ļ�����ʧ�ܻ᷵��false
	//************************************
	bool Save()const;
	//************************************
	// ������ : FindBookByTitle
	// ��  �� : ������ؼ��ֲ���ͼ��
	// ����ֵ : std::list<ID> : ͼ��������,δ��¼�᷵�ؿ�����
	// ��  �� : const char * title : ����ؼ���
	//************************************
	list<ID> FindBookByTitle(const char* title)const;
	//list<ID> OverdueBookList()const;
private:
	//ͼ�����Ա��Ϣ�ļ�·��
	const char*adminMapPath{ "admin" };
	//�û���Ϣ�ļ�·��
	const char*userMapPath{ "user" };
	//�鼮��Ϣ�ļ�·��
	const char*bookMapPath{ "book" };
	////��־�ļ�·��
	//const char*logPath{ "log.txt" };
	//������ʱ��
	const unsigned int overdueDays{ 90 };
	//�Ƿ��¼
	bool Loggedin{ false };
	//ͼ�����Ա��Ϣ
	AdminMap adminMap{ AdminMap::ReadMap(adminMapPath) };
	//��¼��ͼ�����Ա
	Admin admin{ Admin(0) };
	//�û���Ϣ
	UserMap userMap{ UserMap::ReadMap(userMapPath) };
	//�鼮��Ϣ
	BookMap bookMap{ BookMap::ReadMap(bookMapPath) };
};


#pragma once
typedef long long unsigned ID;
class Admin
{
	//��Ԫ��:ͼ�����Աӳ��
	friend class AdminMap;
	//��Ԫ��:ͼ�����Ա����
	friend class AdminHelper;
	//��Ԫ��:ϵͳ����Ա����
	friend class RootHelper;
public:
	//ɾ��Ĭ�Ϲ��캯��
	Admin() = delete;
	//************************************
	// ������ : Admin
	// ��  �� : ʹ�ñ�Ź���ͼ�����Ա
	// ��  �� : const ID id : ͼ�����Ա���
	//************************************
	Admin(const ID id);
	//************************************
	// ������ : Admin
	// ��  �� : ʹ��ȫ����Ϣ����ͼ�����Ա
	// ��  �� : const ID id : ͼ�����Ա���
	// ��  �� : const char * name : 
	// ��  �� : const char * password : 
	//************************************
	Admin(const ID id, const char *name, const char *password);
private:
	//************************************
	// ������ : SetName
	// ��  �� : ����ͼ�����Ա�û���
	// ����ֵ : bool : �Ƿ�ɹ�,ʧ�ܿ������û�������
	// ��  �� : const char * name : ���õ��û���
	//************************************
	bool SetName(const char *name);
	//************************************
	// ������ : SetPassword
	// ��  �� : ����ͼ�����Ա����
	// ����ֵ : bool : �Ƿ�ɹ�,ʧ�ܿ������������
	// ��  �� : const char * password : ���õ�����
	//************************************
	bool SetPassword(const char *password);
	//ͼ�����Ա���,Ĭ��Ϊ0
	ID id{ 0 };
	//ͼ�����Ա�û���
	char name[16];
	//ͼ�����Ա����
	char password[32];
};

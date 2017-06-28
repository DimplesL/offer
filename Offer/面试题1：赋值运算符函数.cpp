/*
*
* ������1����ֵ���������
*
*/

#include <cstring>

//���Ͷ���
class CMyString
{
public:
	CMyString(char *pch = nullptr) :pdata(pch) {}
	CMyString(const CMyString& str) = default;
	CMyString& operator=(const CMyString &str);
	~CMyString(void) = default;
private:
	char *pdata;
};

/*
//һ��д��
CMyString & CMyString::operator=(const CMyString & str) //�������ͣ���������
{
	if (this != &str) {			 //�ж��Ƿ���ͬһ��
		delete[] pdata;			 //ɾ����ǰʵ���ڴ�
		pdata = nullptr;		 //���ָ��
		pdata = new char[strlen(str.pdata) + 1];	//�����µ��ڴ�
		strcpy(pdata, str.pdata);//������������		
	}
	return *this; //������������
}
*/


//�쳣��ȫ
CMyString & CMyString::operator=(const CMyString & str)//�������ͣ���������
{
	if (this != &str) {			//�ж��Ƿ���ͬһ��
		CMyString tmp_str(str);	//������ʱʵ�����뿪���ú�ͻ��Ƿ���ʱʵ��
		
		//��������
		char *ptmp = tmp_str.pdata; 
		tmp_str.pdata = pdata;
		pdata = ptmp;
	}

	return *this; //������������
}



/*
*
* ������1����ֵ���������
*
*/

#include <cstring>

class CMyString
{
public:
	CMyString(char *pdata = nullptr);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString &str);
	~CMyString(void);
private:
	char *pdata;
};

//һ��д��
CMyString & CMyString::operator=(const CMyString & str)
{
	if (this != &str) {
		delete[] pdata;
		pdata = nullptr;
		pdata = new char[strlen(str.pdata) + 1];
		strcpy(pdata, str.pdata);
	}
	return *this;
}

//�쳣��ȫ
CMyString & CMyString::operator=(const CMyString & str)
{
	if (this != &str) {
		CMyString tmp_str(str);
		char *ptmp = tmp_str.pdata;
		tmp_str.pdata = pdata;
		pdata = ptmp;
	}

	return *this;
}



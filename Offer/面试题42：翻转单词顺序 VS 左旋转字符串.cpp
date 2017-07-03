/*
*
* ������42����ת����˳�� VS ����ת�ַ���
*
*/

#include <string>

using namespace std;

void reverse(string &str, int beg, int end)
{
	while (end > beg){
		swap(str[beg], str[end]);
		end--;
		beg++;
	}
}
//��ת����˳��
//I am a student. ==> student. a am I
string ReverseSentence(string str) 
{
	if (!str.size()) {
		return str;
	}
	//��ת����
	reverse(str, 0, str.size() - 1);
	//��ת����
	int start = 0; 
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			reverse(str, start, i - 1);
			start = i + 1;
		}
	}
	//�����˷�ת���һ�����ʣ�����û�пո�����
	reverse(str, start, str.size() - 1);

	return str;
}

//����ת�ַ���
//
string LeftRotateString(string str, int n) 
{
	if (!str.size() || n > str.size() || n < 1) {
		return str;
	}
	//��ת����
	reverse(str, 0, str.size() - 1);
	//��תǰ�沿�֣�ʹ��˳��
	reverse(str, 0, str.size() - n - 1);
	//��ת���沿�֣�ʹ��˳��
	reverse(str, str.size() - n, str.size() - 1);

	return str;
}
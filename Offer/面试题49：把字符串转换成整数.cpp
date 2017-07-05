/*
*
* ������49�����ַ���ת��������
* ��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
* ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0 
*
*/
#include <cctype>
#include <string>

using namespace std;

int StrToInt(string str) 
{ 
	long long result = 0;
	if (!str.size()) {
		return result;
	}
	bool minus = false;
	int idx = 0;
	//���˵��ո�
	while (isspace(str[idx])){
		idx++;
	}
	//�����ŵ��ж�
	if (str[idx] == '-') {
		minus = true;
		idx++;
	}
	if (str[idx] == '+') {
		minus = false;
		idx++;
	}
	if (idx >= str.size()) {
		return 0;
	}
	//�ַ�ת����
	for (int i = idx; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + str[i] - '0';
		}
		else {
			return 0;
		}
	}
	//���
	result = minus ? -result : result;
	//��Χ�ж�
	if (result > INT_MAX || result < INT_MIN) {
		return 0;
	}
	return result;

}
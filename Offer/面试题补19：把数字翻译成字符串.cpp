/*
*
* �����ⲹ20�������ַ�����ַ���
* ����һ�����֣����ǰ������¹������������ַ�����0����ɡ�a��, 
* 1����ɡ�b��...,25����ɡ�z��, һ�����ֿ����ж��ַ��룬
* ����12258��5�ַ��룬�ֱ�Ϊbccfi��bwfi��bczi��mcfi��mzi��
* ��ʵ��һ����������������һ�������ж����в�ͬ�ķ��뷽����
*
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//�ݹ�
int getTransCount(const string & numstr, int i)
{
	int len = numstr.size();

	//�������ȣ�ֻ��һ�ֿ���
	if (i >= len - 1) {
		return 1;
	}
	//[i]��[i+1]������ϳ�һ���ַ���,�����ַ���
	if (i + 1 < len ) {
		int sum = (numstr[i] - '0') * 10 + numstr[i + 1] - '0';
		if (sum > 9 && sum < 26) {
			return getTransCount(numstr,i+1) + getTransCount(numstr,i+2);
		}
	}
	//������ϳ�һ���ַ���
	return getTransCount(numstr, i + 1);
}
//��̬�滮,�Ӻ���ǰ������¼
int getTransCount(const string & numstr)
{
	int len = numstr.size();
	vector<int>  dp(len);
	int cur = 0;
	for (int i = len - 1; i >= 0; i--) {
		cur = 0;
		//��ǰ����Ϊ����
		if (i < len - 1) {
			cur = dp[i + 1];
		}else{
			cur = 1;
		}
		//�����ܲ�����ϳ�һ���ַ�
		if (i < len - 1) {
			int sum = (numstr[i] - '0') * 10 + numstr[i + 1] - '0';
			if (sum > 9 && sum < 26) {
				if (i < len - 2) {
					cur += dp[i + 2];
				}
				else {
					cur += 1;
				}
			}
		}
		dp[i] = cur;
	}
	return dp[0];
}

//������ֵķ������
int getTransCount(int number)
{
	if (number < 0) {
		return 0;
	}
	string numstring = to_string(number);
	//�ݹ鷽ʽ
	return getTransCount(numstring,0);
	//�ǵݹ鷽ʽ
	return getTransCount(numstring);
}

//ţ������û�и���Ŀ����Ӧ��������
//��Ԫ����
void test(char *testname, int index, int expect)
{
	int result = getTransCount(index);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("num0", 0, 1);
	test("num10", 10, 2);
	test("num126", 126, 2);
	test("num426", 426, 1);
	test("num12258", 12258, 5);

	return 0;
}
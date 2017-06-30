/*
*
* �����ⲹ22��������ظ��ַ������ַ���
* ����ַ������ҳ�һ��������ظ��ַ������ַ��������������ַ����ĳ��ȡ�
* �����ַ�����arabcacfr���У�������ظ��ַ������ַ����ǡ�acfr��������Ϊ4�� 
*
*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int longestSubStringWithoutDuplication(const string &str)
{
	if (str.size() == 0) {
		return 0;
	}
	//��ʷ�����ǰ�
	int max = 0, cur = 0;
	vector<int> hash(26, -1);
	//����ÿһ���ַ�
	for (int i = 0; i < str.size(); i++) {
		int preidx = hash[str[i] - 'a'];
		//֮ǰΪ�洢�������ظ��ַ�������ڵ�ǰ�δ�ظ����룬��cur++;
		if (preidx < 0 || i - preidx > cur) {
			cur++;
		}
		//�洢���������ظ�
		else {
			cur = i - preidx; //(i-1) - preidx + 1��
		}
		//�洢�ַ���Ӧ���±�����
		hash[str[i] - 'a'] = i;

		if (cur > max) {
			max = cur;
		}
	}
	return max;
}

//ţ������û�и���Ŀ����Ӧ��������
//��Ԫ����
void test(char *testname,string str, int expect)
{
	int result = longestSubStringWithoutDuplication(str);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("num0", "h", 1);
	test("num10", "hihi", 2);
	test("num126", "arabcacfr", 4);
	test("num12258", "", 0);

	return 0;
}
/*
*
* �����ⲹ19������������ĳһλ������
* ������0123456789101112131516...�ĸ�ʽ���л���һ���ַ������У�
* ����������У���5Ϊ��5����19Ϊ��4���ȵȣ���дһ���������������nλ��Ӧ�����֡�
*
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int digitAtIndex(int index)
{
	int digits;
	for (digits = 1; ; digits++) {
		//����digitsλ���ĸ�������2λ��10-99����90��������Ϊ2*90
		int count = (digits == 1) ? 10 : 9 * (int)pow(10, digits - 1);
		//index���䳤�ȱȽ�
		if (index < digits * count) {
			break;
		}
		else {
			index -= digits * count;
		}
	}
	//��Ӧdigitsλ������ʼ��ֵ����3λ������ʼ��ֵΪ100
	int begin = (digits == 1) ? 0 : pow(10, digits - 1);
	//��index��Ӧ����ֵ
	int result = begin + index / digits;
	//����ֵ�ж�Ӧ��λ
	for (int j = 1; j < (digits - index % digits); j++) {
		result /= 10;
	}
	result %= 10;

	return result;
}
//ţ������û�и���Ŀ����Ӧ��������
//��Ԫ����
void test(char *testname, int index, int expect)
{
	int result = digitAtIndex(index);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("index0", 0, 0);
	test("index1", 1, 1);
	test("index9", 9, 9);
	test("index10", 10, 1);
	test("index189", 189, 9);  // ����99�����һλ��9
	test("index190", 190, 1);  // ����100�ĵ�һλ��1
	test("index1000", 1000, 3); // ����370�ĵ�һλ��3
	test("index1001", 1001, 7); // ����370�ĵڶ�λ��7
	test("index1002", 1002, 0); // ����370�ĵ���λ��0
	return 0;
}
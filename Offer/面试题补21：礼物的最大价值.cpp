/*
*
* �����ⲹ21�����������ֵ
* ��һ��m*n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ����ֵ��>0����
* ����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��
* ֱ���������̵����½ǡ�����һ�����̼��������������������������õ����ټ�ֵ�����
*
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000
int maxval[MAX][MAX];

int getMaxValue(const int *gift, int row, int col)
{
	//�߽�
	if (gift == nullptr || row < 1 || col < 1) {
		return 0;
	}
	//����ÿһ��λ��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int up = 0, left = 0;
			//�����ֵ
			if (i > 0) {
				up = maxval[i - 1][j];
			}
			//�����ֵ
			if (j > 0) {
				left = maxval[i][j - 1];
			}
			//��ǰλ�����ֵ
			maxval[i][j] = max(up, left) + gift[i * col + j];
		}
	}
	return maxval[row - 1][col - 1];
}

//ţ������û�и���Ŀ����Ӧ��������
//��Ԫ����
void test(char *testname, int *gift, int row, int col, int expect)
{
	int result = getMaxValue(gift,row,col);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	int values1[] = {
		  1, 2, 3 ,
		 4, 5, 6 ,
		 7, 8, 9 
	};

	int values2[] = {1, 10, 3, 8 };
	int values3[] = { 3 };

	test("test1", values1, 3, 3, 29);
	test("test2", values2, 4, 1, 22);
	test("test3", values2, 1, 4, 22);
	test("test4", values3, 1, 1, 3);
	test("test5", nullptr ,0, 0, 0);
	

	return 0;
}
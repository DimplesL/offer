/*
*
* ������20��˳ʱ���ӡ����
* ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
* ���磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
* �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) 
{
	vector<int> result;
	if (matrix.size() == 0) {
		return result;
	}
	int start = 0;
	int row = matrix.size();
	int col = matrix[0].size();

	//ѭ����������Ϊ��һ��������ʵÿ�ε�ǰ��������������2
	while (row > start * 2 && col > start * 2) {
		int endx = row - start;
		int endy = col - start;

		//����
		for (int i = start; i < endy; i++) {
			result.push_back(matrix[start][i]);
		}
		//����
		for (int i = start + 1; i < endx; i++) {
			result.push_back(matrix[i][endy - 1]);
		}
		//����,�����ظ�
		for (int i = endy - 2; start != endx - 1 && i >= start; i--) {
			result.push_back(matrix[endx - 1][i]);
		}
		//����,�����ظ�
		for (int i = endx - 2; start != endy - 1 && i > start; i--) {
			result.push_back(matrix[i][start]);
		}
		start++;
	}
	return result;
}
/*
*
* ������20��˳ʱ���ӡ����
*
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> result;
	if (matrix.size() == 0) {
		return result;
	}
	int start = 0;
	int row = matrix.size();
	int col = matrix[0].size();
	while ((row + 1) / 2 > start && (col + 1) / 2 > start) {
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
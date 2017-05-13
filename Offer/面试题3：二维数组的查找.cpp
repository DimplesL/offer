/*
*
* ������3����ά����Ĳ���
*
*/

#include <vector>

using std::vector;

bool Find(int target, vector<vector<int>> array) 
{
	if (array.size() == 0 || array[0].size() == 0) {
		return false;
	}
	int row = 0;
	int col = array[0].size() - 1;
	//�����Ͻǲ��ң��������ӣ������С
	while (row < array.size() && col >= 0) {
		if (array[row][col] == target) {
			return true;
		}
		if (array[row][col] < target) {
			row++;
		}
		else {
			col--;
		}
	}
	return false;
}
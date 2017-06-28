/*
*
* ������3����ά����Ĳ���
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
* ÿһ�ж����մ��ϵ��µ�����˳������
* �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
* ����:
* 1   2    8     9
* 2   4    9    12
* 4   7    10  13
* 6   8    11  15
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
		//Ŀ��ֵ������
		if (array[row][col] < target) {
			row++;
		}
		//Ŀ��ֵС������
		else {
			col--;
		}
	}
	return false;
}
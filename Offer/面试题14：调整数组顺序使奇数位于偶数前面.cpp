/*
*
* ������14����������˳��ʹ����λ��ż��ǰ��
* ����һ���������飬ʵ��һ�����������������������ֵ�˳��
* ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
* ����֤������������ż����ż��֮������λ�ò��䡣
*
*/
#include <vector>
#include <functional>
using std::vector;
using std::swap;

void reOrderArray(vector<int> &array)
{
	if (array.size() <= 1) {
		return;
	}
	int j = 0;//j֮��ı�ʾż��
	for (int i = 0; i < array.size(); i++) {
		//���i���������򽻻�λ��
		if (array[i] & 1 == 1) {
			swap(array[i], array[j]);
			j++;
		}
	}
}
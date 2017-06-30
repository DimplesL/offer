/*
*
* ������34������
* ��ֻ��������2��3��5��������������Ugly Number����
* ����6��8���ǳ�������14���ǣ���Ϊ����������7��
* ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
*
*/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int GetUglyNumber_Solution(int index) 
{
	if (index < 7) {
		return index;
	}
	//��������
	vector<int> result(index);
	//��2��3��5��Ӧ���±�����
	int m2 = 0, m3 = 0, m5 = 0;
	//1�ǵ�һ������
	result[0] = 1;
	for (int i = 1; i < index; i++) {
		//�ҵ���2��3��5��С��һ��
		int val = min(result[m2] * 2, min(result[m3] * 3, result[m5] * 5));
		//����ǳ�2�õ��ģ���2���±�+1
		if (val == result[m2] * 2) {
			result[i] = val;
			m2++;
		}
		//����ǳ�3�õ��ģ���3���±�+1
		if (val == result[m3] * 3) {
			result[i] = val;
			m3++;
		}
		//����ǳ�5�õ��ģ���5���±�+1
		if (val == result[m5] * 5) {
			result[i] = val;
			m5++;
		}
	}
	return result[index - 1];
}

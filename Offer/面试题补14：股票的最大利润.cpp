/*
*
* �����ⲹ15����Ʊ���������
* �����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У�
* ���������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�
*
*/

#include <vector>

using namespace std;

//���Ĳ�ֵ
int maxDiff(const vector<int> num)
{
	if (!num.size()) {
		return 0;
	}

	int min = num[0];		//��Сֵ
	int diff = num[0] - min;//���
	for (int i = 1; i < num.size(); ++i) {
		//������Сֵ
		if (num[i] < min) {
			min = num[i];
		}
		//��ǰ���
		int tmp = num[i] - min;
		//���²��
		if (tmp > diff) {
			diff = tmp;
		}
	}
	return diff;
}

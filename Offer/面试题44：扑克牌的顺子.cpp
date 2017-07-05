/*
*
* ������44���˿��Ƶ�˳��
* �Ȱ������������ͳ�������д�С���ĸ�����
* ���ͳ������֮�����������������֮��Ŀ�ȱ������
* �����ȱ�Ŀ���С�ڻ��ߵ��ڴ�С���ĸ�������ô������������ģ�������ǲ������ġ�
*
*/

#include <vector>
#include <algorithm>

using namespace std;


bool IsContinuous(vector<int> numbers) 
{
	if (!numbers.size()) {
		return false;
	}
	//1 ͳ��0�ĸ���,��Ϊ��С������0
	int zero_num = 0;
	for (auto v : numbers) {
		if (v == 0) {
			zero_num++;
		}
	}
	if (zero_num == 4) {
		return true;
	}
	//2 ����
	sort(numbers.begin(), numbers.end());

	//3 ͳ�Ƽ��
	int small = zero_num;
	int big = small + 1;
	int gap = 0;
	while (big < numbers.size()){
		//��ȿ϶�����˳��
		if (numbers[big] == numbers[small]) {
			return false;
		}
		//��¼���
		gap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	//�Ƚϼ���ʹ�С���ĸ���
	return zero_num >= gap;

}
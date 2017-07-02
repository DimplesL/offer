/*
*
* ������40��������ֻ����һ�ε�����
* һ�����������������������֮�⣬���������ֶ����������Ρ�
* ��д�����ҳ�������ֻ����һ�ε����֡�
*
*/

#include <vector>
#include <iostream>

using namespace std;

//��һλΪ1���±�
unsigned int find_first_bit1(int num)
{
	int idx = 0;
	while (((num & 1) == 0) && (idx < 8 *sizeof(int))){
		num >>= 1;
		idx++;
	}
	return idx;
}

//�жϸ�λ�Ƿ���1
bool is_bit1(int num, unsigned int idx)
{
	num >>= idx;
	return (num & 1);
}

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
	if (data.size() < 2) {
		return;
	}
	//���������
	int allor = 0;
	for (auto v : data) {
		allor ^= v;
	}
	//��һλΪ1���±�
	unsigned int idx = find_first_bit1(allor);
	//���飬������ú���
	*num1 = *num2 = 0;
	for (auto v : data) {
		//����
		if (is_bit1(v,idx)) {
			*num1 ^= v; //����
		}else{
			*num2 ^= v;
		}
	}
}


//�ڶ��棺����
/*
*
* ��Ŀ����������Ψһ����һ�ε�����
* ��һ�������г���һ������ֻ������һ��֮�⣬�������ֶ����������Σ����ҳ��Ǹ�ֻ����һ�ε����֡�
*
*/
int findNumberAppearOnce(vector<int> data)
{
	if (data.size() == 0) {
		return -1;
	}
	int allbit[32] = { 0 };
	//����ÿһ����
	for (int i = 0; i < data.size(); i++) {
		//����ÿһλ,����ÿһλ֮��
		int mask = 1;
		for (int j = 31; j >= 0; j--) {
			int bit = data[i] & mask;
			if (bit != 0){
				allbit[j] += 1;
			}
			mask <<= 1;
		}
	}
	int result = 0;
	//ȡ��
	for (int i = 0; i < 32; i++) {
		result = result << 1;
		result += allbit[i] % 3;
	}
	return result;
}
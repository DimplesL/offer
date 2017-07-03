/*
*
* ������43��n�����ӵĵ���
*
*/

#include <iostream>
#include <cmath>

using namespace std;

const int max_val = 6;

//���ģ��������
//originalΪ��ʼֵ��n��������ʼֵΪn
//currentΪ��ǰ���Ӹ���
//������֮��
//�Ͷ�Ӧ�Ĵ���
void probalility(int original, int current, int sum, int *probabilities)
{
	if (current == 1) {
		probabilities[sum - original]++;
	}
	else{
		//ÿ�����Ӷ������ֿ���
		for (int i = 1; i <= max_val; i++) {
			probalility(original, current - 1, i + sum, probabilities);
		}
	}
}
//�������
void probalility(int number, int *probabilities)
{
	for (int i = 1; i <= max_val; i++) {
		probalility(number, number, i, probabilities);
	}
}


void PrintPrabability(int number)
{
	if (number < 1) {
		return;
	}
	//����ռ�
	int max_sum = number * max_val;
	int *probabilities = new int[max_sum];
	for (int i = number; i <= max_sum; i++) {
		probabilities[i] = 0;
	}
	//������ܵ����
	probalility(number, probabilities);

	//�������
	int total = pow(double(max_val), number);
	for (int i = number; i <= max_sum; i++) {
		double ratio = (double)probabilities[i - number] / total;
		cout << i << " " << ratio << endl;
	}
}

/*
int main(void)
{
	PrintPrabability(3);
	getchar();
	return 0;
}
*/
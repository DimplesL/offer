/*
*
* ������12����ӡ1������nλ��
* ����n����˳���ӡ��1������nλ10����������n=3,�����1,2,3...999
*
*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

//ģ���1
void increment(vector<int> &num)
{
	//ĩβλ��1
	num[0]++;
	for (int i = 0; i < num.size() - 1; i++) {
		//�����λ
		if (num[i] == 10) {
			num[i] = 0;
			num[i + 1]++;
		}else{ //һ������λ������Ҫ����
			break;
		}
	}
}

void print(const vector<int> &num)
{
	bool isfind = false;
	for (int i = num.size() - 1; i >= 0; i--) {
		if (num[i] != 0) {
			isfind = true;
		}
		if (isfind) {
			cout << num[i];
		}
	}
	cout << endl;
}

void print_1_to_max_n_digits(int n)
{
	if (n <= 0) {
		return;
	}
	//����ռ䲢��0
	vector<int> number(n+1,0);
	while (1){
		//����һλ
		increment(number);
		//��������
		if(number[n] == 1){
			break;
		}
		print(number);
	}
}



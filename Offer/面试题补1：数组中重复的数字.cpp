/*
*
* �����ⲹ1���������ظ�������
*
*/


#include <functional>

using namespace std;


//�޸�����
bool duplicate(int numbers[], int length, int* duplication)
{
	if (!numbers || length <= 0) {
		return false;
	}

	//��������±����ֵ
	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			swap(numbers[i], numbers[numbers[i]]);
		}
	}

	return false;
}


int countRange(const int *numbers, int length, int start, int end)
{
	if (!numbers || length <= 0) {
		return -1;
	}
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (numbers[i] >= start && numbers[i] <= end) {
			count++;
		}
	}
	return count;
}

//δ�޸�����
int getDuplication(const int *numbers, int length)
{
	if (!numbers || length <= 0) {
		return -1;
	}
	//���ö��ֲ��ң�ͳ�ƴ���
	int start = 1;
	int end = length;
	while (end >= start) {
		int mid = start + (end - start) >> 1;
		int count = countRange(numbers, length, start, mid);
		if (end == start) { //ֻ��һ��Ԫ����
			if (count > 1) {
				return start;
			}
			else {
				break;
			}
		}
		if (count > (mid - start + 1)) { //start-mid���ظ�
			end = mid;
		}else{							 //mid+1-end���ظ�
			start = mid + 1;
		}
	}
	return -1;
}
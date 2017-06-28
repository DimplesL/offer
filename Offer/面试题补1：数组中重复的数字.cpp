/*
*
* �����ⲹ1���������ظ�������
* ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�
* ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
* Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
* ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
*
*/


#include <functional>

using namespace std;


//�޸�����
bool duplicate(int numbers[], int length, int* duplication)
{
	//����ֵ���
	if (!numbers || length <= 0) {
		return false;
	}
	//�����Ƿ�Ϸ�
	for (int i = 0; i<length; ++i)
	{
		if (numbers[i] <= 0 || numbers[i] > length - 1) {
			return false;
		}
	}
	//��������±����ֵ,������ظ��������������mӦ�������±�Ϊm��λ��
	for (int i = 0; i < length; i++) {
		int m = numbers[i];
		while (m != i) {		   //��i������Ӧ��ֵҲӦ��Ϊi
			if (m == numbers[m]) { //λ��m���Ѿ�����m�ˣ�˵���ظ�
				*duplication = m;
				return true;
			}
			swap(m, numbers[m]);   //������ֵ
		}
	}

	return false;
}


//��һ�ַ���
bool duplicate(int numbers[], int length, int* duplication)
{
	//����ֵ���
	if (!numbers || length <= 0) {
		return false;
	}
	//�����Ƿ�Ϸ�
	for (int i = 0; i<length; ++i)
	{
		if (numbers[i] <= 0 || numbers[i] > length - 1) {
			return false;
		}
	}
	//�����±꣬����ֵm��Ӧ���±�λ��m����length�����λ��m��Ӧ����ֵ����length��˵���������ظ�
	for (int i = 0; i < length; i++) {
		int m = numbers[i];
		//��ֵ�Ѿ�����length��������
		if (m >= length) {
			m -= length;
		}
		if (numbers[m] >= length) {
			*duplication = m;
			return true;
		}
		numbers[m] += length;
	}

	return false;
}

//���㷶Χ[start,end]�ڵĸ���
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
		//����[start,mid]֮�������
		int count = countRange(numbers, length, start, mid);
		if (end == start) { //ֻ��һ������
			if (count > 1) {
				return start; //��������֮������ָ�����Լ1
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
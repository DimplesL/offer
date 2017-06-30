/*
*
* �����ⲹ10���������е���λ��
* ��εõ�һ���������е���λ����������������ж�����������ֵ��
* ��ô��λ������������ֵ����֮��λ���м����ֵ��
* ������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ
*
*/

#include <queue>
#include <functional>

using namespace std;
//���ѣ�ά��С����
priority_queue<int, vector<int>, less<int>>  maxheap;
//��С�ѣ�ά��������
priority_queue<int,vector<int>, greater<int>> minheap;

void Insert(int num)
{
	//��ǰֵ��С���������ѣ����������С��
	if (!maxheap.size() || num <= maxheap.top()) {
		maxheap.push(num);
	}else{
		minheap.push(num);
	}
	//ά�������ѵ�ƽ�⣬���Ѵ�С��С����С�ѣ���Ȼ���ܱ���С�Ѵ�2����
	if (maxheap.size() == minheap.size() + 2) {
		minheap.push(maxheap.top());
		maxheap.pop();
	}
	if (maxheap.size() == minheap.size() - 1) {
		maxheap.push(minheap.top());
		minheap.pop();
	}
}

double GetMedian()
{
	//�����Ѵ�Сһ�£������ѵ�ͷ����С�ѵ�ͷ֮�ͳ���2������λ��
	if (maxheap.size() == minheap.size()) {
		return (double)(maxheap.top() + minheap.top()) / 2;
	}
	//���򷵻����ѵ�ͷ
	else {
		return (double)maxheap.top();
	}
}


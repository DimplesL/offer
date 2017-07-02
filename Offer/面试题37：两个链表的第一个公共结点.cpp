/*
*
* ������37����������ĵ�һ���������
*
*/

#include <cmath>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

//���������
unsigned int get_length(ListNode *head)
{
	unsigned int count = 0;
	//����һ������
	while (head != nullptr){
		count++;
		head = head->next;
	}
	return count;
}

//���ҵ�һ����������
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	if (!pHead1 || !pHead2) {
		return nullptr;
	}
	//���㳤��
	int length1 = get_length(pHead1);
	int length2 = get_length(pHead2);

	//�������������ȣ��ҳ��ϳ�����
	ListNode *longhead, *shorthead;
	if (length1 > length2) {
		longhead = pHead1;
		shorthead = pHead2;
	}
	else {
		longhead = pHead2;
		shorthead = pHead1;
	}
	//�ϳ��������߳���ֻ��
	for (int i = 0; i < abs(length1 - length2); i++) {
		longhead = longhead->next;
	}
	//��������ͬ�ߣ���ȼ���һ������
	while (longhead && shorthead && longhead != shorthead){
		longhead = longhead->next;
		shorthead = shorthead->next;
	}
	//���ؽ���
	return longhead;
}
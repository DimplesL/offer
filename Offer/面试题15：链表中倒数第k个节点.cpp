/*
*
* ������15�������е�����k���ڵ�
* ����һ����������������е�����k����㡣
*
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	//����ֵ�ж�
	if (pListHead == nullptr || k == 0) {
		return nullptr;
	}
	ListNode* a = pListHead;
	ListNode* b = pListHead;

	//ͷָ������k-1����Ҫ�ж��Ƿ��������Ƿ�С��k
	for (unsigned int i = 0; i < k - 1; i++) {
		if (a->next != nullptr) { //�Ƿ��к����ڵ�
			a = a->next;
		}else{
			return nullptr;
		}
	}
	
	//Ѱ�����һ���ڵ�
	while (a->next != nullptr){
		a = a->next;
		b = b->next;
	}

	return b;
}

//�м�ڵ�
ListNode* find_middle(ListNode* pListHead)
{
	//һ����һ����
	ListNode *slow = pListHead, *quick = pListHead;
	//�����������������һ��
	while (quick && quick->next){
		slow = slow->next;
		quick = quick->next->next;
	}
	//���ļ�Ϊ�м�ڵ�
	return slow;
}

/*
int main(void)
{
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	cout << find_middle(root)->val << endl;
	getchar();
	return 0;
}
*/
/*
*
* �����ⲹ3�������л�����ڽ��
* һ�������а����������ҳ�������Ļ�����ڽ�㡣
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	//ͷ����Ϊ�գ�����ͷ����һ���ڵ�Ҳ��Ϊ��
	if (!pHead || !pHead->next) {
		return nullptr;
	}

	ListNode *slow = pHead->next; //��ָ��
	ListNode *quick = pHead->next->next;//��ָ��

	//�ڻ�������,��������������һ��
	while (quick && quick->next && slow != quick) {
		slow = slow->next;
		quick = quick->next->next;
	}
	if (slow != quick) {
		return nullptr;
	}
	//Ѱ���뻷�ڵ�
	quick = pHead;
	while (quick != slow) {
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}
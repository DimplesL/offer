/*
*
* �����ⲹ3�������л�����ڽ��
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (!pHead || !pHead->next) {
		return nullptr;
	}

	ListNode *slow = pHead->next;
	ListNode *quick = pHead->next->next;

	while (quick && quick->next && slow != quick) {
		slow = slow->next;
		quick = quick->next->next;
	}
	if (slow != quick) {
		return nullptr;
	}
	quick = pHead;
	while (quick != slow) {
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}
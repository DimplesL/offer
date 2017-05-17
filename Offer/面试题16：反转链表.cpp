/*
*
* ������16����ת����
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* pHead) 
{
	ListNode *pre = nullptr;
	while (pHead != nullptr) {
		ListNode *next = pHead->next;
		pHead->next = pre;
		pre = pHead;
		pHead = next;
	}
	return pre;
}
/*
*
* �����ⲹ4��ɾ���������ظ��Ľ��
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (!pHead || !pHead->next)
		return pHead;
	ListNode **cur = &pHead;
	while (*cur) {
		if ((*cur)->next && (*cur)->val == (*cur)->next->val) {
			int val = (*cur)->val; //�ظ�ֵ
			while ((*cur) && (*cur)->val == val) {
				ListNode * node = *cur;
				*cur = (*cur)->next;
				delete node;
				node = nullptr;
			}
		}
		else
			cur = &((*cur)->next);
	}
	return  pHead;
}
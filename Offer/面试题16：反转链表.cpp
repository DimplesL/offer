/*
*
* ������16����ת����
* ��Ŀ������һ�����������������ͷ��㣬��ת���������ط�ת�������ͷ���
* ˼·��pre cur next�ϸ�ָ�룬pre��¼ǰһ����curΪ��ǰ��
* next��¼��һ����Ϊ�˷�ֹ����nextʱ����Ͽ���
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
	//��Ϊ�գ��ͼ�����ת
	while (pHead != nullptr) {
		ListNode *next = pHead->next; //��¼��һ��λ��
		pHead->next = pre; //��ǰλ�÷�ת
		pre = pHead;       //����pre�͵�ǰλ��
		pHead = next;
	}
	return pre;
}
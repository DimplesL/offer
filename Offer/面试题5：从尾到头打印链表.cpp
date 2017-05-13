/*
*
* ������5����β��ͷ��ӡ����
*
*/

#include <vector>
#include <stack>

using std::stack;
using std::vector;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

//����
void insert(ListNode **head, int value)
{
	ListNode *new_node = new ListNode(value);
	if (*head == nullptr) {
		*head = new_node;
	}
	else {
		ListNode *n = *head;
		while (n->next != nullptr){
			n = n->next;
		}
		n->next = new_node;
	}
}

//ɾ��
void remove(ListNode **head, int value)
{
	if (head == nullptr || *head == nullptr) {
		return;
	}

	ListNode *delete_node = nullptr;
	
	//ͷ�ڵ�����⴦��
	if ((*head)->val == value) {
		delete_node = *head;
		*head = (*head)->next;
	}
	else {
		ListNode *n = *head;
		//����Ѱ��
		while (n->next != nullptr && n->next->val != value){
			n = n->next;
		}
		if (n->next != nullptr && n->next->val != value) {
			delete_node = n->next;
			n->next = n->next->next;
		}
	}
	if (delete_node != nullptr) {
		delete delete_node;
		delete_node = nullptr;
	}
}

//��ͷ��β��ӡ
vector<int> printListFromTailToHead(ListNode* head) {
	stack<int> si;
	while (head != nullptr) {
		si.push(head->val);
		head = head->next;
	}
	vector<int> vi;
	while (!si.empty()) {
		vi.push_back(si.top());
		si.pop();
	}
	return vi;
}
/*
*
* ������13����O(1)ʱ��ɾ������ڵ�
*
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

void delete_node(ListNode **head, ListNode *delete_node)
{
	//��������ж�
	if (!head || !*head || !delete_node) {
		return;
	}

	//����к����ڵ㣬������һ���ڵ����ݣ�������ɾ��
	if (delete_node->next != nullptr) {
		ListNode *node = delete_node->next;
		delete_node->val = node->val;
		delete_node->next = node->next;
		delete node;
		node == nullptr;
	}
	//ɾ����Ӧ�ڵ�
	else {
		//������Ӧ�ĵ�
		while (*head != delete_node) {
			head = &((*head)->next);
		}
		//�޸�
		*head = (*head)->next;
		delete delete_node;
		delete_node = nullptr;
	}
}
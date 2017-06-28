/*
*
* ������26����������ĸ���
* ����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
* ��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
* ��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*
*/

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(nullptr), random(nullptr) {}
};

void clone_node(RandomListNode *phead)
{
	while (phead != nullptr) {
		RandomListNode * pclone = new RandomListNode(phead->label);
		pclone->next = phead->next;
		phead->next = pclone;
		phead = pclone->next;
	}
}

void connect_sibling(RandomListNode *phead)
{
	while (phead != nullptr) {
		if (phead->random != nullptr) {
			phead->next->random = phead->random->next;
		}
		phead = phead->next->next;
	}
}


RandomListNode *cut(RandomListNode *phead)
{
	RandomListNode *newclone = phead->next;
	while (phead != nullptr) {
		RandomListNode *clone = phead->next;
		phead->next = clone->next;
		phead = phead->next;
		if (phead) {
			clone->next = phead->next;
		}
		else {
			clone->next = nullptr;
		}
	}
	return newclone;
}

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}

	clone_node(pHead);
	connect_sibling(pHead);
	return cut(pHead);
}

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}

	//����
	RandomListNode *node = pHead;
	while (node != nullptr){
		RandomListNode *tmp = new RandomListNode(node->label);
		tmp->next = node->next;
		node->next = tmp;
		node = tmp->next;
	}
	//����random��
	node = pHead;
	while (node != nullptr) {
		if (node->random != nullptr) {
			node->next->random = node->random->next;
		}
		node = node->next->next;
	}
	//�������ԭ�����жϿ�
	node = pHead;
	RandomListNode *root = pHead->next;
	while (node->next != nullptr) {
		RandomListNode *tmp = node->next;
		node->next = tmp->next;
		node = tmp;
	}
	return root;
}

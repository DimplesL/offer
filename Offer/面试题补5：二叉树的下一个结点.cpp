/*
*
* �����ⲹ5������������һ�����
* ����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
* ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*
*/

//���Ķ���
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	//����ֵ�ж�
	if (pNode == nullptr) {
		return nullptr;
	}
	//���ҽڵ�
	if (pNode->right != nullptr) {
		TreeLinkNode *root = pNode->right;
		while (root->left != nullptr) {
			root = root->left;
		}
		return root;
	}
	//û���ҽڵ�,�����ϲ���ʱ������·���Ľڵ���ĳ�����ڵ����ڵ�ʱ
	//��ô�ø��ڵ����Ҫ���ҽڵ����һ���ڵ㡣
	TreeLinkNode *node = pNode->next;
	while (node != nullptr && pNode != node->left) {
		pNode = node;
		node = pNode->next;
	}

	return node;
}
/*
*
* ������27��������������˫������
* ����һ�ö��������������ö���������ת����һ�������˫������
* Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*
*/

#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

TreeNode* Convert(TreeNode* pRootOfTree)
{
	//�߽��ж�
	if (pRootOfTree == nullptr) {
		return nullptr;
	}
	if (pRootOfTree->left == nullptr&&pRootOfTree->right == nullptr) {
		return pRootOfTree;
	}
	// 1.�������������˫��������������ͷ�ڵ�
	TreeNode *left = Convert(pRootOfTree->left);
	// 2.��λ��������˫�������һ���ڵ�
	TreeNode *n = left;
	while (n != nullptr && n->right != nullptr) {
		n = n->right;
	}
	// 3.�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������
	if (n != nullptr) {
		pRootOfTree->left = n;
		n->right = pRootOfTree;
	}
	// 4.�������������˫��������������ͷ�ڵ�
	TreeNode *right = Convert(pRootOfTree->right);
	// 5.�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��
	if (right != nullptr) {
		pRootOfTree->left = right;
		right->left = pRootOfTree;
	}
	// 6.���������������Ƿ�Ϊ��ȷ�����صĽڵ㡣
	return left == nullptr ? pRootOfTree : left;
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	//�߽��ж�
	if (pRootOfTree == nullptr) {
		return nullptr;
	}
	//return sub_convert(pRootOfTree,1);
	stack<TreeNode*> st; //�ǵݹ��ջ
	TreeNode* p = pRootOfTree; //������ָ��
	TreeNode* pre,*root;
	bool first = true;
	while (p != nullptr || !st.empty()) {
		//ѭ������������
		while (p != nullptr){
			st.push(p);
			p = p->left;
		}
		//���ʸ��ڵ�
		p = st.top(); st.pop();
		if (first) { //���Σ�����ͷ���
			root = p;
			root->left = nullptr;
			pre = root;
			first = false;
		}else{
			//������ָ����һ���ڵ�
			p->left = pre;
			pre->right = p;
			pre = p; //preΪ��ǰ�ڵ�
		}
		//ת��������
		p = p->right;
	}
	return root;
}

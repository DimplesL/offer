/*
*
* ������23���������´�ӡ������
*
*/


#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

//���У��������
vector<int> PrintFromTopToBottom(TreeNode* root) 
{
	vector<int> result;
	if (root == nullptr) {
		return result;
	}
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		//ͷ��front
		TreeNode *node = que.front(); que.pop();
		result.push_back(node->val);
		//��֤������û�п�ָ�룬�������ټ�����������д�ӡʱ�ܱ�֤��ȷ
		if (node->left != nullptr) {
			que.push(node->left);
		}
		if (node->right != nullptr) {
			que.push(node->right);
		}
	}
	return result;
}
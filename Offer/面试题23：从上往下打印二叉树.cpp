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

vector<int> PrintFromTopToBottom(TreeNode* root) 
{
	vector<int> result;
	if (root == nullptr) {
		return result;
	}
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode *node = que.front(); que.pop();
		if (node != nullptr) {
			result.push_back(node->val);
			que.push(node->left);
			que.push(node->right);
		}
	}
	return result;
}
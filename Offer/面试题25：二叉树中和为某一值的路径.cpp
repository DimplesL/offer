/*
*
* ������25���������к�Ϊĳһֵ��·��
* ����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
* ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
* 
*/

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int> > result;
vector<int> path;

void preorder2(TreeNode *root, int ex) 
{
	//û��Ԫ�أ�ֱ�ӷ���
	if (root == nullptr) {
		return;
	}
	path.push_back(root->val);
	ex -= root->val;
	if (ex < 0) {
		path.pop_back();
		return;
	}
	//�ҵ����������Ľ�
	if (root->left == nullptr && root->right == nullptr && ex == 0) {
		result.push_back(path);
	}
	else {
		preoder(root->left, ex);
		preoder(root->right, ex);
	}
	path.pop_back();
}

//ǰ�����ȱ���
void preoder(TreeNode* root, int expectNumber)
{
	if (root == nullptr) {
		return;
	}
	path.push_back(root->val);
	expectNumber -= root->val;
	if (root->left == nullptr && root->right == nullptr && expectNumber == 0) {
		result.push_back(path);
	}
	else {
		preoder(root->left, expectNumber);
		preoder(root->right, expectNumber);
	}
	//���õ�ķ����ѱ����꣬����
	path.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
{
	if (root == nullptr) {
		return result;
	}
	preoder(root, expectNumber);
	
	return result;
}

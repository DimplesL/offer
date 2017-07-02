/*
*
* ������39�������������
* ����һ�ö����������������ȡ�
* �Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
*
*/

#include <algorithm>
#include <cmath>

using std::max;
using std::abs;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
}; 

//�������
int TreeDepth(TreeNode* pRoot)
{
	//���������нϴ��+1����Ϊ�˲����
	return pRoot==nullptr ? 0 : max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

/* �ж��Ƿ���ƽ������� */
//�Ƿ���ƽ�������
bool isBalanced(TreeNode *root, int &depth)
{
	if (!root) { 
		depth = 0;
		return true; 
	}
	int left = 0, right = 0;
	//����������������������ǲ���ƽ�������
	if (isBalanced(root->left, left) &&
		isBalanced(root->right, right)) {
		//�������������Ĳ�
		int diff = abs(left - right);
		if(diff <= 1){
			depth = max(left, right) + 1;
			return true;
		}
	}
	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
	int depth;
	return isBalanced(pRoot, depth);
}

/*
*
* �����ⲹ9�������������ĵ�k�����
* ����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣
* ���磬 5 / \ 3 7 /\ /\ 2 4 6 8 �У��������ֵ��С˳�����������ֵΪ4��
*
*/

#include <stack>


using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (!pRoot || k <= 0) {
		return nullptr;
	}
	int ith = 0;
	stack<TreeNode*> st;
	TreeNode *cur = pRoot;
	while (cur || !st.empty()){
		//�������
		while (cur) {
			st.push(cur);
			cur = cur->left;
			
		}
		cur = st.top(); st.pop();
		//��i���������ļ�Ϊ��i��Ľڵ�
		if (++ith == k) {
			return cur;
		}
		cur = cur->right;
	}
	return nullptr;
}


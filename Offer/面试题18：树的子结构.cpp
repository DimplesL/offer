/*
*
* ������18�������ӽṹ
* �������ö�����A��B���ж�B�ǲ���A���ӽṹ��
* ��ps������Լ��������������һ�������ӽṹ��
*
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

bool HasSubtreecore(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//pRoot2�Ƚ����ˣ�����ȷ
	if (!pRoot2) {
		return true;
	}
	//pRoot2û�бȽ��꣬��pRoot1�Ƚ����ˣ�����
	if (!pRoot1) {
		return false;
	}
	//�Ƚϸ��ڵ�
	if (pRoot1->val != pRoot2->val) {
		return false;
	}
	//�ݹ�ıȽ���������
	return HasSubtreecore(pRoot1->left, pRoot2->left) &&
		HasSubtreecore(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	//���������������
	if (pRoot1 && pRoot2) { //�ǿղűȽ�
							//���жϸ�
		result = HasSubtreecore(pRoot1, pRoot2);
		//����������㣬�ж�������
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		//��������������㣬�ж�������
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}
	return result;
}

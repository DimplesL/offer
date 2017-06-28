/*
*
* ������6���ؽ�������
* ����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
* ���������ǰ���������������Ľ���ж������ظ������֡�
* ��������ǰ���������{1,2,4,7,3,5,6,8}
* �������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
*
*/

#include <vector>

using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



//������ ǰ����ʼλ�ã�������ʼλ��
TreeNode* reConstruct(const vector<int> &pre, int pre_start, int pre_end,
	const vector<int> &in, int in_start, int in_end)
{
	//��ֹ������û��Ԫ��
	if (pre_start > pre_end || in_start > in_end) {
		return nullptr;
	}
	//������ڵ�
	TreeNode *root = new TreeNode(pre[pre_start]);
	//Ѱ����������и��ڵ��λ��
	for (int i = 0; i < (in_end - in_start + 1); i++) {
		if (in[i + in_start] == pre[pre_start]) { //�ҵ����ڵ�
												  //����������
			root->left = reConstruct(pre, pre_start + 1, pre_start + i,
				in, in_start, in_start + i - 1);
			//����������
			root->right = reConstruct(pre, pre_start + i + 1, pre_end,
				in, in_start + i + 1, in_end);
			break;
		}
	}
	//���ظ��ڵ�
	return root;
}

//�������ĺ���
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	//����ֵ�ж�
	if (!pre.size() || !vin.size() || pre.size() != vin.size()) {
		return nullptr;
	}
	return reConstruct(pre, 0, pre.size() - 1,
		vin, 0, vin.size() - 1);

}



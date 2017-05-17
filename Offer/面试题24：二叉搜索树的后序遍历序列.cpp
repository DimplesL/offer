/*
*
* ������24�������������ĺ����������
*
*/

#include <vector>

using namespace std;

bool subVerifySquenceOfBST(const vector<int> sequence, int beg, int end)
{
	if (beg >= end) {
		return true;
	}
	int root = sequence[end];
	//��������
	int i = beg;
	for (; i < end; i++) {
		if (sequence[i] > root) {
			break;
		}
	}
	//�ж��������Ƿ�Ϸ�
	for (int j = i; j < end; j++) {
		if (sequence[j] < root) {
			return false;
		}
	}

	return subVerifySquenceOfBST(sequence, beg, i - 1)
		&& subVerifySquenceOfBST(sequence, i, end - 1);

}

bool VerifySquenceOfBST(vector<int> sequence) 
{
	if (!sequence.size()) {
		return false;
	}
	return subVerifySquenceOfBST(sequence, 0, sequence.size() - 1);
}

/*
*
* ������36�������е������
* �������е��������֣����ǰ��һ�����ִ��ں�������֣�
* ���������������һ������ԡ�����һ������,�����������е�����Ե�����P��
* ����P��1000000007ȡģ�Ľ������� �����P%1000000007 
*
*/

#include <vector>

using namespace std;

//���κϲ������з���ֵΪ����Եĸ���
long long merge(vector<int> &data, vector<int> &copy_data, int start, int end)
{
	//û�������
	if (start >= end) {
		return 0;
	}
	//���Σ�����
	int mid   = start + (end - start) / 2;
	long long left  = merge(copy_data, data, start, mid);
	long long right = merge(copy_data, data, mid + 1, end);
	//�������б��ұߴ�ģ���ô�ʹ�������ԣ���������Եĸ�������
	long long count = 0;
	int copy_idx = end; //�������±�����
	int i = mid, j = end;
	while (i >= start && j > mid){
		//��߱��ұߴ󣬴��������
		if (data[i] > data[j]){
			count += (j - mid);
			copy_data[copy_idx--] = data[i--];
		}
		//�ұ߱���ߴ󣬲����������
		else {
			copy_data[copy_idx--] = data[j--];
		}

	}
	//���һ����ʣ�࣬��ֱ�ӿ���
	while (i >= start){
		copy_data[copy_idx--] = data[i--];
	}
	while (j >= mid+1) {
		copy_data[copy_idx--] = data[j--];
	}
	//��������õ�����
	for (int k = start; k <= end; k++) {
		data[k] = copy_data[k];
	}
	//��������Եĸ���
	return count + left + right;
}

int InversePairs(vector<int> data) 
{
	if (data.size() < 2) {
		return 0;
	}
	//copy_data��Ϊ�м俽������
	vector<int> copy_data = data;
	//����
	return merge(data, copy_data, 0, data.size()-1) % 1000000007;
}
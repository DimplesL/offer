/*
*
* ������30����С��K����
* ����n���������ҳ�������С��K������
* ��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*
*/

#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> result;
	//����ֵ����
	if (input.size() == 0 || k < 1 || input.size() < k) {
		return result;
	}
	//���ȶ��У�ά����С��k����
	priority_queue<int> pq;
	for (int v : input) {
		//С��k��ʱ��ֱ�ӷ���
		if (pq.size() < k) {
			pq.push(v);
		}else{
			//����������ֵ����v����ջ��ѹ��ֵ
			int max_val = pq.top();
			if (max_val > v) {
				pq.pop();
				pq.push(v);
			}
		}
	}
	while (!pq.empty()){
		result.push_back(pq.top()); pq.pop();
	}
	return result;
}
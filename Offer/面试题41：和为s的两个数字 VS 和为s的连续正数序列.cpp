/*
*
* ������41����Ϊs����������VS��Ϊs��������������
*
*/

#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > result;
	if (sum < 3) {
		return result;
	}

	int small = 1;
	int big = 2;
	int cur = 3;
	while (small < (sum + 1) / 2){
		if (cur == sum) {
			vector<int> vi;
			for (int i = small; i <= big; i++) {
				vi.push_back(i);
			}
			result.push_back(vi);
		}
		while (cur > sum && small < (sum + 1) / 2){
			cur -= small;
			small++;
			if (cur == sum) {
				vector<int> vi;
				for (int i = small; i <= big; i++) {
					vi.push_back(i);
				}
				result.push_back(vi);
				break;
			}
		}
		big++;
		cur += big;
	}

	return result;

}

vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	vector<int> result;
	if (array.size() > 1) {
		int i = 0;
		int j = array.size() - 1;
		//��һ��ͷ���ڶ���β
		while (j > i){
			int two = array[i] + array[j];
			//����������
			if (two == sum) {
				result.push_back(array[i]);
				result.push_back(array[j]);
				break;
			//�ʹ�����ٴ���
			}else if(two > sum){
				j--;
			//��С��������С��
			}else{
				i++;
			}
		}
	}

	return result;
}
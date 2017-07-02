/*
*
* ������38�����������������г��ֵĴ���
* ͳ��һ�����������������г��ֵĴ�����������{1,2,3,3,3,3,4,5}������3,3������4�Σ��򷵻�4
*
*/
#include <vector>

using namespace std;

//���ҵ�һ�γ��ֵ�λ��
int find_first(const vector<int> &data, int k, int start, int end)
{
	while (end >= start){
		int mid = start + (end - start) / 2;
		if (data[mid] > k) {
			end = mid-1;
		}
		else if (data[mid] < k) {
			start = mid + 1;
		//��ֱ�Ӷ��ֲ��ҵĺ������������ȣ���ǰһ��λ��Ҳ�Ǹ��������ܷ���
		//���ǽ�end��Ϊǰһ��λ�ã����Խ���������Ϊ�����ǰһ�����Ǹ���
		}else if(mid > start && data[mid - 1] == k) {
			end = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}

//�������һ�γ��ֵ�λ��
int find_last(const vector<int> &data, int k, int start, int end)
{
	while (end >= start) {
		int mid = start + (end - start) / 2;
		if (data[mid] > k) {
			end = mid - 1;
		}
		else if (data[mid] < k) {
			start = mid + 1;
		}
		//��ֱ�Ӷ��ֲ��ҵĺ������������ȣ��Һ�һ��λ��Ҳ�Ǹ��������ܷ���
		//���ǽ�start��Ϊ��һ��λ�ã����Խ���������Ϊ����Һ�һ�����Ǹ���
		else if (mid < end && data[mid + 1] == k) {
			start = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int GetNumberOfK(vector<int> data, int k) 
{
	if (!data.size()) {
		return 0;
	}
	//��λ��
	int left = find_first(data, k, 0, data.size() - 1);
	//��λ��
	int right = find_last(data, k, 0, data.size() - 1);

	if (left != -1 && right != -1) {
		return right - left + 1;
	}
	return 0;
}

//�ڶ��油��
/*
*
* ��Ŀ����0 - n - 1��ȱʧ������
* һ������Ϊn - 1�ĵ�������������������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0~n - 1��Χ�ڣ�
* ��n������ֻ��һ�����ֲ��ڸø������ڣ��ҳ�������֡�
*
*/

int getMissNum(vector<int> num)
{
	if (num.size() == 0) {
		return -1;
	}
	int start = 0;
	int end = num.size() - 1;
	while (end >= start){
		int  mid = start + (end - start) >> 1;
		//��ȣ����ұ�
		if (num[mid] == mid) {
			start = mid + 1;
		}
		//����ȣ���ǰһ��λ������������±�
		else if (mid == 0 || num[mid - 1] == mid-1){
			return mid;
		}
		//����ȣ���ǰһ��λ�����鲻�������±�
		else {
			end = mid - 1;
		}
	}
	//ȱʧ�����ֲ��������У�������һ��λ��
	if (start == num.size()) {
		return num.size();
	}
	return -1;
}

/*
*
* ��Ŀ������������ֵ�±���ȵ�Ԫ��
* ����һ�������������������ÿһ��Ԫ�ض�����������Ψһ�ģ�
* ����ʵ��һ���ҳ���һ����ֵ�������±��Ԫ�أ�
* ���磬������{ -3,-1,1,3,5 }�У���ֵ3�������±���ȡ�
*
*/

int getNumSameAsIndex(vector<int> num)
{
	if (num.size() == 0) {
		return -1;
	}
	int start = 0;
	int end = num.size() - 1;
	while (end >= start) {
		int  mid = start + (end - start) >> 1;
		//��ȷ��ؼ���
		if (mid == num[mid]) {
			return mid;
		//�±����ֵ�������ұ�
		}else if(mid > num[mid]){
			start = mid + 1;
		//�±�С��ֵ���������
		}else{
			end = mid - 1;
		}
	}	
	return -1;
}
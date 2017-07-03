/*
*
* �����ⲹ14�����е����ֵ
* ����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
* ���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
* ���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� 
*�������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
* {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� 
* {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*
*/

#include <vector>
#include <queue>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (!num.size() || num.size() < size || size <= 0) {
		return result;
	}
	//ǰ���ڴ�С������ȫ������
	deque<int> di;
	for (int i = 0; i < size; ++i) {
		//��ǰֵ��ǰ��Ĳ����ܳ�Ϊ���ڵ����ֵ������ȫ������
		while (!di.empty() && num[i] >= num[di.back()]){
			di.pop_back();
		}
		//ѹ��
		di.push_back(i);
	}
	result.push_back(num[di.front()]);//���

	for (unsigned int i = size; i < num.size(); ++i) {		
		while (!di.empty() && num[i] >= num[di.back()]) {
			di.pop_back();
		}
		//�ж���ǰͷ���������Ƿ����
		if (!di.empty() && di.front() < (i - size)) {
			di.pop_front();
		}
		di.push_back(i);
		result.push_back(num[di.front()]);
	}
	
	return result;

}


//���е����ֵ
//�붨��һ�����в�ʵ�ֺ���max�õ�����������ֵ��
//Ҫ����max��push��pop��ʱ�临�Ӷȶ���O(1)��
template<typename T>
class QueueWithMax
{
public:
	QueueWithMax():cur_idx(0){}
	void push(T v) 
	{
		//�Ȳ����ֵ����֮ǰ���ֵ��
		while (!maxdat.empty() && v > maxdata.back().val){
			maxdata.pop_back();
		}
		//���������
		Data d = { v, cur_idx };
		data.push_back(d);
		maxdata.push_back(d);
		cur_idx++;
	}
	void pop() 
	{
		if (maxdata.empty()) {
			throw new exception("queue is empty.");
		}
		//������������������ֵ���������������ֵ���е���
		if (maxdata.front().index == data.front().index) {
			maxdata.pop_front();
		}
		data.pop_front();
	}
private:
	struct Data {
		T val;
		int index;
	};
	deque<Data> data;
	deque<Data> maxdata;
	int cur_idx; //��¼�Ƿ����
};
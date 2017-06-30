/*
*
* ������29�������г��ִ�������һ�������
* ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬
* ���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
* ��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*
*/

#include <vector>
#include <functional>

using namespace std;

int parition(vector<int> &numbers, int start, int end)
{
	if (start >= end) {
		return end;
	}
	/* static int first = 0;
	if(!first){
	  first = 1;
	  srand((unsigned)time(0));
	}
	int rand_num = start + rand() % (end - start + 1);
	swap(numbers[end],numbers[rand_num]);
	*/
	//���ŵĲ���
	int key = numbers[end];
	int i = start;
	for (int j = start; j < end; j++) {
		if (numbers[j] < key) {
			swap(numbers[i++], numbers[j]);
		}
	}
	//��󽻻���ע�ⲻ����ֵ�����������±��Ӧ������
	swap(numbers[i], numbers[end]);

	return i;
}

//partition����
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.size() == 0) {
		return 0;
	}

	int start = 0;
	int end = numbers.size() - 1;
	int mid = start + (end - start) / 2;
	int idx = 0;
	//���֣�ֱ���������ص�Ϊ�м���
	while ((idx = parition(numbers, start, end)) != mid) {
		if (idx > mid) {
			end = idx - 1;
		}
		else {
			start = idx + 1;
		}
	}
	//��������Ƿ񳬹�һ��
	int result = numbers[mid];
	int times = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == result) {
			times++;
		}
	}
	return times > numbers.size() / 2 ? result : 0;
}


int MoreThanHalfNum_Solution2(vector<int> numbers)
{
	if (numbers.size() == 0) {
		return 0;
	}
	int result = numbers[0]; //��ǰ�洢��ֵ
	int times = 1;			 //����
	for (int i = 1; i < numbers.size(); i++) {
		if (times == 0) { //���ã���ǰ�洢��ֵ�ʹ���
			result = numbers[i];
			times = 1;
		}else if(numbers[i] == result){
			times++;
		}else{
			times--;
		}
	}
	times = 0;
	//У��
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == result) {
			times++;
		}
	}
	return times > numbers.size() / 2 ? result : 0;
}

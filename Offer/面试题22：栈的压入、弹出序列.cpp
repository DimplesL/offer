/*
*
* ������22��ջ��ѹ�롢��������
* ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
* ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
* ����4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
* ��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
*
*/

#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	//������С����һ��
	if (pushV.empty() || popV.empty() 
		|| pushV.size() != popV.size()) {
		return false;
	}

	stack<int> si;
	int idx = 0;
	for (int i = 0; i < pushV.size(); i++) {
		//��ʼ����Ԫ��
		si.push(pushV[i]);
		//��Ⱦ͵�ջ
		while (!si.empty() && si.top() == popV[idx]){
			si.pop();
			idx++;
		}
	}
	return si.empty();
}
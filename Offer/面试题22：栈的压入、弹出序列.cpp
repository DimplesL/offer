/*
*
* ������22��ջ��ѹ�롢��������
*
*/

#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	if (pushV.empty() || popV.empty() 
		|| pushV.size() != popV.size()) {
		return false;
	}

	stack<int> si;
	int idx = 0;
	for (int i = 0; i < pushV.size(); i++) {
		si.push(pushV[i]);
		while (!si.empty() && si.top() == popV[idx]){
			si.pop();
			idx++;
		}
	}
	return si.empty();
}
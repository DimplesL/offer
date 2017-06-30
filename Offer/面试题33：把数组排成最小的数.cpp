/*
*
* ������33���������ų���С����
* ����һ�����������飬����������������ƴ�������ų�һ������
* ��ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}��
* ���ӡ���������������ųɵ���С����Ϊ321323��
*
*/

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string PrintMinNumber(vector<int> numbers)
{
	string result;
	//����ֵ�ж�
	if (!numbers.size()) {
		return result;
	}
	
	vector<string> vs;
	for (auto val : numbers) {
		//ת��Ϊ�ַ���
		stringstream ss;
		ss << val;
		vs.push_back(ss.str());
	}
	//����
	sort(vs.begin(), vs.end(), [](const string &a, const string &b) {
		string s1 = a + b;
		string s2 = b + a;
		return s1 < s2;
	});
	//���
	for (auto val : vs) {
		result += val;
	}
	return result;
}

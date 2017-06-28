/*
*
* ������28���ַ���������
* ����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
* ���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*
*/

#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> result;
void Permutation(string& str, int idx)
{
	//��ֹ����
	if (idx == str.size()) {
		result.push_back(str);
	}else{
		//֮����������
		sort(str.begin() + idx, str.end());
		for (int j = idx; j < str.size(); j++) {
			//�ų���ȵ�
			if (j != idx && str[idx] == str[j]) {
				continue;
			}
			swap(str[idx], str[j]);
			Permutation(str, idx + 1);//�±�+1
			swap(str[idx], str[j]);
		}
	}
}
vector<string> Permutation(string str) {
	//�ǿգ�����
	if (str.size()) {
		Permutation(str, 0);
	}
	return result;
}

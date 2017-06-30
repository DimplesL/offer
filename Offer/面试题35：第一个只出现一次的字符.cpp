/*
*
* ������35����һ��ֻ����һ�ε��ַ�
* ��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
*
*/

#include <string>

using namespace std;


int FirstNotRepeatingChar(string str) 
{
	//����ֵ�ж�
	if (!str.size()) {
		return 0;
	}
	//�ַ�hash��
	const int size = 256;
	unsigned int hash_table[256];
	for (int i = 0; i < size; i++) {
		hash_table[i] = 0;
	}
	//ͳ���ַ������ַ�
	for (auto ch : str) {
		hash_table[ch]++;
	}
	//�ҳ���һ���ַ�����Ϊ1���ַ�
	for (int i = 0; i < str.size(); i++) {
		if (1 == hash_table[str[i]]) {
			return i;
		}
	}
	return 0;
}

//�ַ����е�һ��ֻ����һ�ε��ַ�
//��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
//���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
//���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
class Solution
{
public:
	int idx;
	int occurrence[256];
	Solution():idx(1)
	{
		for (int i = 0; i < 256; ++i) {
			occurrence[i] = 0;
		}
	}
	//����һ���ַ���hash�����ַ���Ӧλ��
	void Insert(char ch)
	{
		//��һ�γ���hashֵΪ����
		if (occurrence[ch] == 0) {
			occurrence[ch] = idx++;
		//�ٴγ���hashֵΪ-1
		}else if(occurrence[ch] > 0){
			occurrence[ch] = -1;
		}
	}
	//�ַ����е�һ���ַ�
	char FirstAppearingOnce()
	{
		char ch;
		int min = INT_MAX;
		//ͳ���±�������С��
		for (int i = 0; i < 256; ++i) {
			if (occurrence[i]>0 && occurrence[i] < min) {
				ch = (char)i;
				min = occurrence[i];
			}
		}
		return ch;
	}
};

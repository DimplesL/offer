/*
*
* ������35����һ��ֻ����һ�ε��ַ�
*
*/

#include <string>

using namespace std;

//��ָoffer��Ŀ
char FirstNotRepeatingChar_offer(string str) 
{
	if (!str.size()) {
		return 0;
	}
	const int size = 256;
	unsigned int hash_table[256];
	for (int i = 0; i < size; i++) {
		hash_table[i] = 0;
	}
	for (auto ch : str) {
		hash_table[ch]++;
	}

	for (int i = 0; i < size; i++) {
		if (hash_table[i] == 1) {
			return i;
		}
	}
	return 0;
}
//ţ����
int FirstNotRepeatingChar(string str) 
{
	if (!str.size()) {
		return 0;
	}
	const int size = 256;
	unsigned int hash_table[256];
	for (int i = 0; i < size; i++) {
		hash_table[i] = 0;
	}
	for (auto ch : str) {
		hash_table[ch]++;
	}

	for (int i = 0; i < str.size(); i++) {
		if (1 == hash_table[str[i]]) {
			return i;
		}
	}
	return 0;
}
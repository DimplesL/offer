/*
*
* ������4���滻�ո�
*
*/

void replaceSpace(char *str)
{
	if (str == nullptr) {
		return;
	}
	int i = 0;
	int newlen = 0;
	int oldlen = 0;
	//���㳤��
	while (str[i] != '\0') {
		oldlen++;
		newlen++;
		if (str[i] == ' ') {
			newlen += 2;
		}
		i++;
	}
	//�����滻
	while (oldlen >= 0 && oldlen < newlen) {
		if (str[oldlen] == ' ') {
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else {
			str[newlen--] = str[oldlen];
		}
		oldlen--;
	}
}
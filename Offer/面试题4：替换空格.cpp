/*
*
* ������4���滻�ո�
* ��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
* ���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*
*/

//�ַ�����������
//����ֵ��Ϊ��ʵ����ʽ����
char *strcpy(char *dst, const char *src)
{
	//����ֵ�ж�
	if (dst == nullptr || src == nullptr) {
		return nullptr;
	}
	//����ֵ
	char *start = dst;
	//����
	while ((*dst++ = *src++))
		;
	return start;
}

void replaceSpace(char *str)
{
	//����ֵ
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
	//���������ھ�����˵��ǰ���пո񣬷���û�пո�
	while (oldlen >= 0 && oldlen < newlen) { 
		//�����ո�,�滻
		if (str[oldlen] == ' ') {
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		//���ǿո�ֱ���滻
		else {
			str[newlen] = str[oldlen];
			newlen--;
		}
		oldlen--;
	}
}
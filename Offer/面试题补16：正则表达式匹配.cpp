/*
 * 
 * �����ⲹ17��������ʽƥ��
 * ��Ŀ����ʵ��һ��������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ�κ�һ���ַ���
 * ��'*'��ʾ��ǰ����ַ����Գ��������(��0��)���ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
 * ���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
 *
 */

bool match(char* str, char* pattern)
{
	//���������ж�
	if (!str || !pattern) {
		return false;
	}
	//ģʽƥ��
	return matchcore(str, pattern);
}

//ƥ�����
bool matchcore(char *str, char *pattern)
{
	//�����ַ�����β����ƥ��ɹ�
	if (*str == '\0' && *pattern == '\0') {
		return true;
	}
	//�ַ���û��������ģʽ�ѽ���ƥ��ʧ��
	if (*str != '\0' && *pattern == '\0') {
		return false;
	}

	//��һ���ַ�'*'
	if (*(pattern + 1) == '*') {
		if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
			//��ǰλ���ַ�ƥ��ʱ
			return matchcore(str + 1, pattern)    //ƥ����
				|| matchcore(str + 1, pattern + 2)//ƥ��0��
				|| matchcore(str, pattern+2);     //����
		}
		//��ƥ�䣬ֻ��������һ��ƥ��λ��
		return matchcore(str, pattern + 2);
	}
	//��Ϊ'*'��ֻ�ܱȽ�
	if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
		return matchcore(str + 1, pattern + 1);
	}
	return false;
}

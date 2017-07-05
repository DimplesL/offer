/*
*
* �����ⲹ18����ʾ��ֵ���ַ���
* ��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
* ���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
* ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
* ��ʾ��ֵ���ַ�����ѭģʽA[.[B]][e|EC]����.B[e|EC],
* ����AΪ��ֵ���������֣�B������С����Ϊ��ֵ��С�����֣�
* C������'e'����'E'Ϊ��ֵ��ָ�����֡�Ҳ��һ������״̬�����⡣
*
*/

//ɨ���޷�������
bool scanUnsignedInteger(char* &str)
{
	const char *before = str; //��¼��ʼλ��
	while (*str != '\0' && *str >= '0' && *str <= '9') {
		str++;
	}
	return str > before; //ɨ����ڵ�����
}

//ɨ���з�������
bool scanInteger(char* &str)
{
	if (*str == '+' || *str == '-') {
		str++;
	}
	return scanUnsignedInteger(str);
}

bool isNumeric(char* string)
{
	if (string == nullptr) {
		return false;
	}
	//ɨ��A����
	bool numeric = scanInteger(string);

	//С������
	if (*string == '.') {
		++string;
		//ʹ��||��ԭ�򣬿���û���������֣�Ҳ����û��С������
		//.123 233. 233.444
		numeric = numeric || scanUnsignedInteger(string);
	}
	//E����e��������������ֵ�ָ������
	if (*string == 'e' || *string == 'E') {
		++string;
		//&&ԭ��1 e|E֮ǰ���������ݣ� e�������������
		numeric = numeric && scanInteger(string);
	}
	return numeric && (*string == '\0');
}

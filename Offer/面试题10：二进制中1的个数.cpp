/*
*
* ������10����������1�ĸ���
*
*/

int  NumberOf1(int n) 
{
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			count++;
		}
		flag <<= 1;
	}
	return count;
}

int  NumberOf1_2(int n)
{
	int count = 0;
	while (n){
		count++;
		n = (n - 1) & n;
	}
	return count;
}

//�ж�һ�������ǲ���2�������η�
bool is2power(int n)
{
	return !((n - 1)&n);
}

//������������m,n,��Ҫ�ı�m�������ж���λ���ܵõ�n
int change(int m, int n)
{
	//�������ͬλ����ͳ��1�ĸ���
	return NumberOf1_2(m^n);
}

/*
* NOTE:
*	��һ��������ȥ1֮���ٺ�ԭ����������λ�����㣬�õ��Ľ���൱���ǰ������Ķ����Ʊ�ʾ�е����ұ�һ��1���0
*/

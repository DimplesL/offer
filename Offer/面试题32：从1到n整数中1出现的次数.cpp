/*
*
* ������32����1��n������1���ֵĴ���
*
*/

int NumberOf1Between1AndN_Solution(int n)
{
	int number = 0;
	for (int i = 1; i <= n; i++) {
		int val = i;
		while (val){
			if (val % 10 == 1) {
				number++;
			}
			val /= 10;
		}
	}
	return number;
}


int NumberOf1Between1AndN_Solution_2(int n)
{
	int count = 0;//1�ĸ���
	int i = 1;//��ǰλ
	int current = 0, after = 0, before = 0;
	while ((n / i) != 0) {
		current = (n / i) % 10; //��λ����
		before = n / (i * 10); //��ǰλ����
		after = n - (n / i)*i; //��λ����
							   //���Ϊ0,����1�Ĵ����ɸ�λ����,���ڸ�λ���� * ��ǰλ��
		if (current == 0) {
			count += before*i;
		}
		//���Ϊ1,����1�Ĵ����ɸ�λ�͵�λ����,��λ*��ǰλ+��λ+1
		else if (current == 1) {
			count += before * i + after + 1;
		}
		//�������1,����1�Ĵ����ɸ�λ����,//����λ����+1��* ��ǰλ��
		else {
			count += (before + 1) * i;
		}
		//ǰ��һλ
		i = i * 10;
	}
	return count;
}
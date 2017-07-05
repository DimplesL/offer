/*
*
* ������45��ԲȦ�е����ʣ�µ�����
* 0,1,...,n-1��n�������ų�һ��ԲȦ��������0��ʼ��
* ÿ�δ����ԲȦ��ɾ����m�����֣�������ԲȦ�����һ�����֡�
*
*/

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1) {
		return -1;
	}
	//�������飬����ģ��
	int *circle = new int[n];
	for (int i = 0; i < n; i++) {
		circle[i] = i;
	}
	int count = n;
	//iΪ�����±��������stepΪ�ߵĲ���
	int i = -1, step = 0;
	//ʣ��ĸ�������0
	while (count > 0) {
		i++;
		if (i == n) {
			i = 0;
		}
		//��λ���Ѿ���ɾ����
		if (circle[i] == -1) {
			continue;
		}
		step++;
		//�Ѿ�����m��
		if (step == m) {
			circle[i] = -1;
			step = 0;
			count--;
		}
	}
	return i;
}
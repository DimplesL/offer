/*
*
* ������46����1+2+...+n
* ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��
* else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*
*/

//�ݹ�
int Sum_Solution_1(int n) 
{
	int  sum = n;
	//����n>0������ݹ���ã�ʵ����Ҳ��if
	bool flag = (n && (sum += Sum_Solution_1(n - 1)));
	return sum;
}

//��̬��������
class tmp
{
public:
	static int n;
	static int sum;
	//ÿ�δ������󶼻����Ӹñ���
	tmp() { n++; sum += n; }
};
//��ʼ��
int tmp::n = 0;
int tmp::sum = 0;

int Sum_Solution(int n)
{
	//����n������
	tmp *t = new tmp[n];
	delete[] t;
	t = nullptr;
	//�����ۼ�ֵ
	return tmp::sum;
}


//����ָ�뷽��
typedef int(*fun)(int);
int solution1(int n)
{
	return 0;
}

int solution2(int n) 
{
	static fun f[2] = { solution1,solution2 };
	//n > 0 !!n == 1;  n==0,!!n = 0
	return n + f[!!n](n - 1);
}

int Sum_Solution2(int n) 
{
	return solution2(n);
}

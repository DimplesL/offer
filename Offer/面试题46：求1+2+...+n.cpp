/*
*
* ������46����1+2+...+n
*
*/

//�ݹ�
int Sum_Solution_1(int n) 
{
	int  sum = n;
	bool flag = (n && (sum += Sum_Solution_1(n - 1)));
	return sum;
}

//��̬��������
class tmp
{
public:
	static int n;
	static int sum;
	tmp() { n++; sum += n; }
};

int tmp::n = 0;
int tmp::sum = 0;

int Sum_Solution(int n)
{
	tmp *t = new tmp[n];
	delete[] t;
	t = nullptr;
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
	return n + f[!!n](n - 1);
}

int Sum_Solution2(int n) 
{
	return solution2(n);
}

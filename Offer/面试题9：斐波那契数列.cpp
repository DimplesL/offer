/*
*
* ������9��쳲���������
* f(n) = f(n-1)+f(n-2)
*
*/

//�ݹ�汾
int recurse_fibonacci(int n)
{
	if (n <= 0) {
		return 0;
	}
	else if (n <= 2) {
		return 1;
	}
	else {
		return recurse_fibonacci(n - 1) + recurse_fibonacci(n - 2);
	}
}

//�ǵݹ�汾
int Fibonacci(int n) 
{
	if (n <= 0) {
		return 0;
	}
	else if (n <= 2) {
		return 1;
	}
	int last = 1;		//��һ�ε�ֵ
	int last_last = 1;  //����һ�ε�ֵ
	int result = last;
	for (int i = 3; i <= n; i++) {
		result = last + last_last; //�����ε�ֵ
		last_last = last;		   //������һ�κ�����һ��
		last = result;
	}
	return result;
}

//��̨��
int jumpFloor(int number) 
{
	if (number <= 0) {
		return 0;
	}
	else if (number == 1) {
		return 1;
	}else if (number == 2) {
		return 2;
	}
	int last = 2;
	int last_last = 1;
	int result = last;
	for (int i = 3; i <= number; i++) {
		result = last + last_last;
		last_last = last;
		last = result;
	}
	return result;
}

//��̬��̨��
int jumpFloorII(int number) 
{
	/*
	int *dp = new int[number + 1];
	dp[0] = 0;

	for (int i = 1; i <= number; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j];
		}
		dp[i]++;
	}
	return dp[number];*/

	//��ѧ���ɷ� f(n) = 2 * f(n-1), ���� f(n) = 2^(n-1)
	return 1 << (number-1);
}

//���θ���
int rectCover(int number) 
{
	//f(n) = f(n-1)+f(n-2)
	if (number <= 0) {
		return 0;
	}
	else if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 2;
	}
	int last = 2;
	int last_last = 1;
	int result = last;
	for (int i = 3; i <= number; i++) {
		result = last + last_last;
		last_last = last;
		last = result;
	}
	return result;
}
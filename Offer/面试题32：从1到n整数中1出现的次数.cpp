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
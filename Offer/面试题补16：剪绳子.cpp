/*
*
* �����ⲹ16��������
* ����һ������Ϊn�����ӣ�������Ӽ���m�Σ�n,m������1����
* ÿ�γ��ȼ�Ϊk[0],k[1],...k[m]������k[0]*k[1]...*k[m]
* ���ܵ����˻��Ƕ��١���������Ϊ8����������2,3,3����ʱ���˻���18��
* f(n) = max(i, f(i) * f(n-i)); ����  0 < i < n��
* 
*/

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int maxProductAfterCutting(int length)
{
	//�߽�,��Ϊ��Ŀ��m>1�������ټ�һ��
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;

	//����dp����
	int *dp = new int[length+1];
	dp[0] = 0; dp[1] = 1;

	int res = 0;
	//�����������
	for (int i = 2; i <= length; i++) {
		res = 0;
		//���ӳ���Ϊiʱ�����Ž⣬����ÿһ�ּ���
		for (int j = 1; j <= i / 2; j++) {
			int val = dp[j] * dp[i - j];
			res = max(i, max(res, val));
		}
		dp[i] = res;
	}
	res = dp[length];
	delete[] dp;

	return res;
}

/*
*
* �����ⲹ2�������˻�����
* ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
* ����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
*
*/

#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A) 
{
	vector<int> B(A.size());
	if (!A.size()) {
		return B;
	}
	//A[0]*A[1]*...*A[i-1]���ֵļ���
	B[0] = 1;
	for (int i = 1; i < A.size(); i++) {
		B[i] = B[i - 1] * A[i - 1];
	}
	//A[i+1]*...*A[n-1]���ֵļ���
	int tmp = 1;
	for (int i = A.size() - 2; i >= 0; i--) {
		tmp *= A[i + 1];
		B[i] *= tmp;
	}

	return B;
}

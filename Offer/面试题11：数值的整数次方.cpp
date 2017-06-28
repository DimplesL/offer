/*
*
* ������11����ֵ�������η�
* ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*
*/

double power_with_exponent(double base, long long exponent)
{
	//��Ϊ0
	if (exponent == 0) {
		return 1.0;
	}
	//ż������(��λ�������˷�����)
	double result = power_with_exponent(base, exponent >> 1);
	result *= result;
	//����Ǽ����ٳ�һ������ֵ
	if(exponent & 0x01 == 1){
		result *= base;
	}
	return  result;
}

double Power(double base, int exponent) 
{
	//baseΪ0.0�򷢻�0.0
	if (base - 0.0 < 0.000001) {
		return 0.0;
	}

	//�ж�����������Ϊ��1.0/��Ӧֵ
	long long exp = exponent;
	if(exponent < 0){
		exp = -exponent;
	}
	double result = power_with_exponent(base, exp);
	return exponent < 0 ? 1.0 / result : result;
}

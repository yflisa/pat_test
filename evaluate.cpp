/*
	��ѧ���⣺���ַ�������Ŷ���ֵ����ȷ��10��-5�η�
*/
#include <cstdio>
#include <stdio.h>
using namespace std;

const double eps = 1e-5;
double Fun(double x)
{
	return x * x;
}

double calSqrt(double nNum, double nLeft, double nRight)
{
	double mid = 0; 

	while((nRight - nLeft) > eps)
	{
		mid = (nLeft + nRight) / 2;
		if(Fun(mid) < 2)
		{
			nLeft = mid;
		}
		else
		{
			nRight = mid;
		}
	}
	return mid;
}

int main()
{
	double nNum = 2;
	double nRes;
	nRes = calSqrt(nNum, 1 ,2);
	printf("%lf\n", nRes);
	return 0;
}
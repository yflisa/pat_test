/*
	求值a的b次对m求余
*/

#include <cstdio>
using namespace std;
typedef long long LL;

LL binaryPow(LL a , LL b, LL M)
{
	if(b == 0)
		return 1;

	if(b % 2 == 0)
	{
		LL tmp = binaryPow(a, b / 2, M);
		return tmp * tmp % M;
	}
	else
		return a * binaryPow(a, b - 1, M) % M;
}

int main()
{
	LL ret = binaryPow(2, 3, 10);
	printf("%lld\n", ret);
}
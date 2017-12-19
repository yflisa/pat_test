#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

void to_array(int n, int num[])
{
	for(int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[])
{
	int sum = 0;
	for(int i = 0; i < 4; i++)
	{
		sum = sum * 10 + num[i];
	}

	return sum;
}

int main()
{
	int n = 0, MIN = 0, MAX = 0;
	int num[5] = {0};
	scanf("%d", &n);
	while(1)
	{
		to_array(n , num);
		sort(num, num + 4);   //��С��������
		MIN = to_number(num);
		sort(num, num + 4, cmp);   //�Ӵ�С����
		MAX = to_number(num);
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if(n == 6174 || n == 0)
			break;
	}

	return 0;
}
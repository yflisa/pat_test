/*
	题目描述： 输入两个非负十进制整数A、B（<=20^30 -1）以及D(进制数),输出A+B的D（1 < D < 10）进制数
	例如：
	输入 123 456 8
	输出 1103
*/

#include <stdio.h>

int main()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;

	int ans[31] = {0}, num = 0;
	do
	{
		ans[num++] = sum % d;
		sum = sum / d;
	}while(sum != 0);

	for(int i = num - 1; i >= 0; i--)
	{
		printf("%d", ans[i]);
	}
	return 0;
}
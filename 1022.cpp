/*
	��Ŀ������ ���������Ǹ�ʮ��������A��B��<=20^30 -1���Լ�D(������),���A+B��D��1 < D < 10��������
	���磺
	���� 123 456 8
	��� 1103
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
/*
	ע�⣺
	����ע�⵱����Ϊ����ʱ���±��1��ʼ��ԭ�������0֮ǰ�Ѿ������0.�������0��ʼ���Ͷ�����
*/

#include <cstdio>

int main()
{
	char head, a[10001] = {0};
	int ex;

	scanf("%c%c.%[0-9]E%d", &head, &a[0], a+1, &ex);

	if(head == '-')
		printf("-");
	if(ex >= 0)
	{
		for(int i = 0; i < (ex + 1) || a[i] != 0; i++)
		{
			if(i == ex + 1)
				printf(".");
			printf("%c", a[i] == 0 ? '0':a[i]);
		}
	}
	else
	{
		printf("0.");
		for(int i = 1; i < (-ex); i++)
			printf("0");
		printf("%s", a);
	}

	return 0;
}
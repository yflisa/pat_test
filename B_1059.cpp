#include <cstdio>
#include <cmath>
#include <cstring>
const int maxn = 100010;
struct Node
{
	int rank;
	bool flag;
}node[maxn];
bool isPrime(int a)
{
	if(a <= 1)
		return false;
	for(int i = 2; i <= sqrt(1.0 * a); i++)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}
int judge(Node a)
{
	if(a.rank == 1)
		return 0;
	if(isPrime(a.rank))
		return 1;
	else
		return 2;
}
int main()
{
	int n, tmp;
	memset(node, 0, sizeof(node));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		node[tmp].rank = i;
		node[tmp].flag = false;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		printf("%04d: ", tmp);
		if(node[tmp].rank != 0)
		{
			int ret = judge(node[tmp]);
			if(node[tmp].flag == false)
			{
				if(ret == 0)
					printf("Mystery Award\n", tmp);
				else if(ret == 1)
					printf("Minion\n", tmp);
				else
					printf("Chocolate\n", tmp);
				node[tmp].flag = true;
			}
			else 
				printf("Checked\n", tmp);
		}
		else
			printf("Are you kidding?\n", tmp);
	}
	return 0;
}
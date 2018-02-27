#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int addr, data, next, count;
	bool flag;
}node[maxn];
bool hashtable[maxn] = {false};

int main()
{
	int s, n, addr;
	scanf("%d %d", &s, &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &addr);
		scanf("%d %d", &node[addr].data, &node[addr].next);
		node[addr].addr = addr;
	}
	int count = 0;
	for(int i = s; i != -1; i = node[i].next)
	{
		if(hashtable[abs(node[i].data)] == false)
		{
			hashtable[abs(node[i].data)] = true;
			node[i].flag = true;
			count++;
		}
	}
	
	bool flag = false;
	for(int i = s, num = 0; i != -1; i = node[i].next)
	{
		if(node[i].flag == true)
		{
			if(flag == true)
			{
				flag = false;
				printf("%05d\n", node[i].addr);
			}
			if(num + 1 != count)
			{
				printf("%05d %d ", node[i].addr, node[i].data);
				flag = true;
			}
			else
			{
				printf("%05d %d -1\n", node[i].addr, node[i].data);
				break;
			}
			num++;
		}
	}
	flag = false;
	for(int i = s, num = count; i != -1; i = node[i].next)
	{
		if(node[i].flag == false)
		{
			if(flag == true)
			{
				flag = false;
				printf("%05d\n", node[i].addr);
			}
			if(num + 1 != n)
			{
				printf("%05d %d ", node[i].addr, node[i].data, node[node[i].next].addr);
				flag = true;
			}
			else
				printf("%05d %d -1\n", node[i].addr, node[i].data);
			num++;
		}
	}
	return 0;
}
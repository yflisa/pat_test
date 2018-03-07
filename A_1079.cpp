#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Node
{
	double data;
	vector<int> child;
}node[maxn];
int n, num = 0, maxDepth = 0;
double p, r, sum = 0;
void DFS(int index, int depth)
{

	if(node[index].child.size() == 0)
	{
		sum += node[index].data * pow(1+r, depth);
		return;
	}

	for(int i = 0; i < node[index].child.size(); i++)
		DFS(node[index].child[i], depth+1);
}

int main()
{
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	int tmpNum, child;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &tmpNum);
		if(tmpNum == 0)
			scanf("%lf", &node[i].data);
		else
		{
			for(int j = 0; j < tmpNum; j++)
			{
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f\n", p * sum);
	return 0;
}
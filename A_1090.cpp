#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int n, maxDepth = 0, num = 0;
const int maxn = 100010;
vector<int> vi[maxn];
double p, r;
void DFS(int root, int depth)
{
	if(vi[root].size() == 0)
	{
		if(maxDepth < depth)
		{
			maxDepth = depth;
			num = 1;
		}
		else if(maxDepth == depth)
			num++;
		return;
	}

	for(int i = 0; i < vi[root].size(); i++)
		DFS(vi[root][i], depth+1);
}

int main()
{
	int root, father;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &father);
		if(father == -1)
			root = i;
		else
			vi[father].push_back(i);
	}
	DFS(root, 0);
	printf("%.2f %d", p*pow(1+r, maxDepth), num);
	return 0;
}
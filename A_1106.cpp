#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
int n, m, num = 0;
double p, r, ans= 1e12;
vector<int> vi[maxn];

void DFS(int index, int depth)
{
	if(vi[index].size() == 0)
	{
		double price = p * pow(1+r, depth);
		if(price < ans)
		{
			ans = price;
			num = 1;
		}
		else if(ans == price)
			num++;
		return;
	}
	for(int i = 0; i < vi[index].size(); i++)
		DFS(vi[index][i], depth+1);
}

int main()
{
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		if(m != 0)
		{
			for(int j = 0; j < m; j++)
			{
				int child;
				scanf("%d", &child);
				vi[i].push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d", ans, num);
	return 0;
}
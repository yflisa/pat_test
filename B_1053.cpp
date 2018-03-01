#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct Dweller
{
	vector<double> v;
	int count;
	bool flag;
	int n;
}dweller[1010];

int main()
{
	int n, d, k, m = 0, y = 0;
	double e, E;
	scanf("%d%lf%d", &n, &e, &d);
	memset(dweller, 0, sizeof(dweller));
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		dweller[i].n = k;
		for(int j = 0; j < k; j++)
		{
			scanf("%lf", &E);
			dweller[i].v.push_back(E);
			if(E < e)
			{
				dweller[i].count++;
			}
		}
		if(dweller[i].count > dweller[i].n / 2)
		{
			dweller[i].flag = true;
			m++;
		}
		if(dweller[i].flag == true && dweller[i].n > d)
		{
			y++;
		}
	}
	printf("%.1f%% %.1f%%", (m-y) * 100.0 / n, y * 100.0 / n);
	return 0;
}
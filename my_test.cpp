#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct tagMoonCake
{
	double price; //单价
	double sell;  //总售价
	double store; //库存
}MoonCake;

bool cmp(MoonCake a, MoonCake b)
{
	return a.price > b.price;
}

int main()
{
	int nMoonKind = 0;
	double fNeeds = 0;
	MoonCake tMoonCake[1010] = {0};

	scanf("%d %lf", &nMoonKind, &fNeeds);
	for(int i = 0; i < nMoonKind; i++)
	{
		scanf("%lf", &tMoonCake[i].store);
	}

	for(int i = 0; i < nMoonKind; i++)
	{
		scanf("%lf", &tMoonCake[i].sell);
		tMoonCake[i].price = tMoonCake[i].sell / tMoonCake[i].store;
	}

	sort(tMoonCake, tMoonCake + nMoonKind, cmp);
	double ans = 0;
	for(int i = 0; i < nMoonKind; i++)
	{
		if(fNeeds >= tMoonCake[i].store)
		{
			fNeeds -= tMoonCake[i].store;
			ans += tMoonCake[i].sell;
		}
		else
		{
			ans += tMoonCake[i].price * fNeeds;
			break;
		}
	}
	printf("%.2f\n", ans);

	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct tagSegment
{
	int x;
	int y;
}Segment;

bool cmp(Segment a, Segment b)
{
	if(a.x != b.x)
		return a.x > b.x;
	else
		return a.y < b.y;
}

int main()
{
	Segment tSegment[10] = {0};
	int nNum = 0;

	while(scanf("%d", &nNum), nNum != 0)
	{
		for(int i = 0; i < nNum; i++)
		{
			scanf("%d %d",&tSegment[i].x, &tSegment[i].y);
		}

		sort(tSegment, tSegment + nNum , cmp);
		int nAns = 1;
		int nLastX = tSegment[0].x;
		for(int i = 1; i < nNum; i++)
		{
			if(tSegment[i].y <= nLastX)
			{
				nLastX = tSegment[i].x;
				nAns++;
			}
		}
		printf("%d\n", nAns);
	}
	return 0;
}
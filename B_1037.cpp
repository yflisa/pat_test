#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ans[4] = {0}, pay[4] = {0}, out_of_pocket[4] = {0};
	bool flag = false;

	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			scanf("%d.%d.%d", &pay[0], &pay[1], &pay[2]);
		}
		if(i == 1)
		{
			scanf("%d.%d.%d", &out_of_pocket[0], &out_of_pocket[1], &out_of_pocket[2]);
		}
	}

	if(out_of_pocket[0] < pay[0])
	{
		flag = true;
		swap(out_of_pocket[0], pay[0]);
		swap(out_of_pocket[1], pay[1]);
		swap(out_of_pocket[2], pay[2]);
	}
	if( out_of_pocket[2] - pay[2] < 0)
	{
		ans[2] = out_of_pocket[2] + 29 - pay[2];
		out_of_pocket[1]--;
	}
	else
	{
		ans[2] = out_of_pocket[2] - pay[2];
	}
	
	if( out_of_pocket[1] - pay[1] < 0)
	{
		ans[1] = out_of_pocket[1] + 17 - pay[1];
		out_of_pocket[0]--;
	}
	else
	{
		ans[1] = out_of_pocket[1] - pay[1];
	}

	ans[0] = out_of_pocket[0] - pay[0];
	if(!flag)
		printf("%d.%d.%d", ans[0], ans[1], ans[2]);
	else

		printf("-%d.%d.%d", ans[0], ans[1], ans[2]);

	return 0;
}
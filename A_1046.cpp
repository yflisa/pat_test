/*
	注意点：
	1.使用一个数组来计算两点之间的距离；
	2.使用一个数组来记录从1到N点之间的距离；
	3.当顶点不好记录的时候可以使用距离
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
int dis[N] = {0}, A[N] = {0};
int main()
{
	int sum = 0, query, n, left[N], right[N];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum;
	}
	scanf("%d", &query);
	for(int i = 0; i < query; i++)
	{
		scanf("%d%d", &left[i], &right[i]);
	    if(left[i] > right[i])
			swap(left[i], right[i]);
	}
	for(int i = 0; i < query; i++)
	{
		int temp = dis[right[i]  -1] - dis[left[i] - 1];
		printf("%d\n", min(temp, sum - temp));
	}

	return 0;
}

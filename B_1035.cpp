#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 111;
int a[maxn], ans[maxn], merge_i[maxn], insert[maxn];
int n;

bool isSame(int A[], int B[])
{
	for(int i = 0; i < n; i++)
	{
		if(A[i] != B[i])
			return false;
	}
	return true;
}

void showArray(int res[])
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d", res[i]);
		if(i + 1 != n)
			printf(" ");
	}
}

bool insertSort()
{
	bool flag = false;
	for(int i = 1; i < n; i++)
	{
		int tmp = insert[i], j = i;
		if(i != 1 && isSame(ans, insert) == true)  //这里前置条件是i != 1
			flag = true;

		while(j > 0 && insert[j - 1] > tmp)
		{
			insert[j] = insert[j - 1];
			j--;
		}
		insert[j] = tmp;
		if(flag)
		{
			return true;
		}
	}
	return false;
}

void mergeSort()
{
	int flag = false;
	for(int step = 2; step / 2 <= n; step *= 2)
	{
		if(step != 2 && isSame(ans, merge_i) == true)
		{
			flag = true;
		}
		for(int j = 0; j < n; j += step)
			sort(merge_i + j, merge_i + min(step + j, n));
		if(flag)
			break;
	}
	if(flag)
	{
		showArray(merge_i);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &ans[i]);

	memcpy(merge_i, a, sizeof(a));
	memcpy(insert, a, sizeof(a));

	if(insertSort())
	{
		printf("Insertion Sort\n");
		showArray(insert);
	}
	else
	{
		printf("merge Sort\n");
		mergeSort();
	}
	return 0;
}

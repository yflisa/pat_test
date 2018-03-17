#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 21;
int main()
{
	int n, number[maxn] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
	}
	sort(number, number+n);
	printf("%d", number[n/2]);
	return 0;
}
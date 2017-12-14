/*
	哈希表
	数组N[5] = {8,3,7,6,2} N[3] = {7,4,2}
	查看数组N是否在数组M中出现过
	实现方法，设定一个bool类型的数组hashTable[10000],将全部数组的值设为false，其中hashTable[x] == true为正整数x在N个正整数中出现过，而hashTable[x] == false为正整数x在N个正整数中没有出现过。
*/

#include <cstdio>
const int maxn = 10010;
bool bHashTable[maxn] = {false};
int main()
{
	int nN = 0, nM = 0, nIndex = 0;
	scanf("%d %d", &nN, &nM);	//分别输入两数组的个数
	for (int i = 0; i < nN; i++)
	{
		scanf("%d", &nIndex);
		bHashTable[nIndex] = true;
	}
	nIndex = 0;
	for(int i = 0; i < nM; i++)
	{
		scanf("%d", &nIndex);
		if(true == bHashTable[nIndex])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
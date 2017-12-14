/*
	本例是hash_code2.cpp的变种，本例要求给出N个字符串（恰好由三位大写字母组成），再给出M个查询字符串，问每个字符串在N个字符串中出现的次数
	本例涉及的点：
	1.hash_code1.cpp中直接找的是是否存在，并且是一个数字，那么这里就不使用数字，而是将字符串和int类型的数据得到一个映射，int是数组下标。
	  如果找到这个下标，查找其中的次数，如果次数不为0表示出现过。这里的难点在于映射。
	2.数组大小设为 26 * 26 * 26 + 10, 后面的+10不考虑，26^3是字符串是大写的单位组成，26是26个大写字母
*/
#include <cstdio>
#define MAX (26 * 26 * 26 +10)

int nHashTable[MAX] = {0};

int hashFunc(char chString[], int len)
{
	int id = 0;
	for(int i = 0; i < len; i++)
	{
		id = id * 26 + (chString[i] - 'A');
	}
	return id;
}

int main()
{
	int nN = 0, nM = 0;
	char chTmpStr[1000][3] = {0};
	scanf("%d %d", &nN, &nM);

	for(int i = 0; i < nN; i++)
	{
		scanf("%s", chTmpStr[i]);
		int id = hashFunc(chTmpStr[i], 3);
		nHashTable[id]++;
	}

	for(int i = 0; i < nM; i++)
	{
		scanf("%s", &chTmpStr[i]);
		int id = hashFunc(chTmpStr[i], 3);
		printf("%d\n", nHashTable[id]);
	}
	return 0;
}
/*
	������hash_code2.cpp�ı��֣�����Ҫ�����N���ַ�����ǡ������λ��д��ĸ��ɣ����ٸ���M����ѯ�ַ�������ÿ���ַ�����N���ַ����г��ֵĴ���
	�����漰�ĵ㣺
	1.hash_code1.cpp��ֱ���ҵ����Ƿ���ڣ�������һ�����֣���ô����Ͳ�ʹ�����֣����ǽ��ַ�����int���͵����ݵõ�һ��ӳ�䣬int�������±ꡣ
	  ����ҵ�����±꣬�������еĴ��������������Ϊ0��ʾ���ֹ���������ѵ�����ӳ�䡣
	2.�����С��Ϊ 26 * 26 * 26 + 10, �����+10�����ǣ�26^3���ַ����Ǵ�д�ĵ�λ��ɣ�26��26����д��ĸ
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
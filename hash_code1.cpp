/*
	��ϣ��
	����N[5] = {8,3,7,6,2} N[3] = {7,4,2}
	�鿴����N�Ƿ�������M�г��ֹ�
	ʵ�ַ������趨һ��bool���͵�����hashTable[10000],��ȫ�������ֵ��Ϊfalse������hashTable[x] == trueΪ������x��N���������г��ֹ�����hashTable[x] == falseΪ������x��N����������û�г��ֹ���
*/

#include <cstdio>
const int maxn = 10010;
bool bHashTable[maxn] = {false};
int main()
{
	int nN = 0, nM = 0, nIndex = 0;
	scanf("%d %d", &nN, &nM);	//�ֱ�����������ĸ���
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
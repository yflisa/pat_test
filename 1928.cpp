#include <stdio.h>
int month[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
{31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

bool isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1; //闰年
	return 0; //平年
}

int main()
{
	int nTime1 = 0, nYYYY1 = 0, nMM1 = 0, nDD1 = 0;
	int nTime2 = 0, nYYYY2 = 0, nMM2 = 0, nDD2 = 0;
	while(scanf("%d%d", &nTime1, &nTime2) != EOF)
	{
		if (nTime1 > nTime2)
		{
			int nTmpTime = nTime1;
			nTime1 = nTime2;
			nTime2 = nTmpTime;
		}
		nYYYY1 = nTime1 / 10000, nMM1 = nTime1 / 10000 % 100, nDD1 = nTime1 % 100;
		nYYYY2 = nTime2 / 10000, nMM2 = nTime2 / 10000 % 100, nDD2 = nTime2 % 100;
		int nAnswer = 1;  //记录结果
		while(nYYYY1 < nYYYY2 || nMM1 < nMM2 || nDD1 < nDD2)
		{
			nDD1++;
			if(nDD1 == month[nMM1][isLeap(nYYYY1)] + 1)
			{
				nMM1++;
				nDD1++;
			}
			if(nMM1 == 13)
			{
				nYYYY1++;
				nMM1++;
			}
			nAnswer++;
		}
		printf("%d\n", nAnswer);
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int nNum = 0, nRow = 0, nCol = 0;
	char cCharactor;

	scanf("%d %c", &nNum, &cCharactor);

	nCol = nNum;
	
	if (nNum % 2 == 0)
	{
		nRow = nNum / 2;
	}
	else
	{
		nRow = nNum / 2 + 1;
	}

	for (int i = 0; i < nNum; i++)
	{
		printf("%c", cCharactor);
	}
	printf("\n");

	for (int i = 0; i < nRow; i++)
	{
		printf("%c", cCharactor);
		for (int j = 1; j < nNum - 2; j++)
			printf(" ");
		printf("%c\n", cCharactor);
	}
	for (int i = 0; i < nNum; i++)
	{
		printf("%c", cCharactor);
	}
	printf("\n");
	getchar();
	getchar();
	return 0;
}
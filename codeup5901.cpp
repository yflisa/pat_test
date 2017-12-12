#include <stdio.h>
#include <string.h>

int main()
{
	char chString[20] = {0};
	scanf("%s", chString);
	int nLen = strlen(chString);
	bool bResult = true;
	for (int i = 0; i < nLen / 2 ; i++)
	{
		if(chString[i] != chString[nLen - i - 1])
		{
			bResult = false;
			break;
		}
	}

	if (bResult == false)
		printf("NO!\n");
	else
		printf("YES!\n");
	
	return 0;
}
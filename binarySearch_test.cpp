/*binarysearch
	要求 ：数组严格递增
*/
#include <stdio.h>
int binarySearch(int nA[], int nLeft, int nRight, int nNum)
{
	int nMid = 0;
	while(nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if(nA[nMid] == nNum)
		{
			return nNum;
		}
		else if(nA[nMid] > nNum)
		{
			nRight = nMid - 1;
		}
		else
		{
			nLeft = nMid + 1;
		}
	}
	return -1;
}
int main()
{
	int nA[10] = {3, 5,23, 34, 123, 439, 890,38724,48756, 65535};
	const int nNum = 10;

	printf("%d %d\n", binarySearch(nA, 0, nNum - 1, 65535), binarySearch(nA, 0, nNum - 1, 10));
	return 0;
}
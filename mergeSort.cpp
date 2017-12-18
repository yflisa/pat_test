/*
	归并排序:注意merge()函数的边界挑拣是R1和R2，不要错误写成L1和L2，还有最后merge()函数中最后for循环的下标是从L1+K开始偏移
*/
#include <cstdio>
using namespace std;
#define MAX (100)

void merge(int A[], int L1, int R1, int L2, int R2)
{
	int i = L1, j = L2, index = 0;
	int tmp[MAX] = {0};
	while(i <= R1 && j <= R2)
	{
		if(A[i] <= A[j])
			tmp[index++] = A[i++];
		else
			tmp[index++] = A[j++];
	}
	while(i <= R1) 
		tmp[index++] = A[i++];
	while(j <= R2)
		tmp[index++] = A[j++];
	for(int k = 0; k < index; k++)
		A[L1 + k] = tmp[k];
}

void mergeSort(int A[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid+1, right);
		merge(A, left, mid, mid+1, right);
	}

}
int main()
{
	int A[10] = {3, 10, 23457, 65535, 9, 15, 7, 654, 10, 987};
	mergeSort(A, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%d ", A[i]);
	return 0;
}
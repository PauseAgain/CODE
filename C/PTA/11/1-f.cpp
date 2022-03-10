#include<stdio.h>

typedef int ElementType;
void PrintSort(ElementType *A,int n)
{
	for (int i = 0; i < n;i++)
	{
		printf("%d,", A[i]);
	}
}
void InsertionSort(ElementType *A, int n)
{
	int j, p;
	ElementType temp;

	for(p = 1; p < n;p++)
	{
		temp = A[p];
		for (j = p; j > 0 && A[j - 1] > temp;j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;

		PrintSort(A,n);
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	ElementType A[n];

	for (int i = 0; i < n;i++)
	{
		scanf("%d,", &A[i]);
	}
	InsertionSort(A, n);
	return 0;
}
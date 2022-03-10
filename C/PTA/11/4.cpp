#include <stdio.h>

typedef int ElementType;

void Swap(ElementType *A, ElementType *B)
{
	ElementType tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}
void Print(ElementType *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d,", A[i]);
	}
	printf("\n");
}
void SelectionSort(ElementType *A, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int min = i;
		for (j = i+1 ; j < n; j++)
		{
			if (A[j] < A[min])
			{
				min = j;
				//! X 不应该放在这里！！！Swap(&A[min], &A[i]);
			}
			//!Swap(&A[j], &A[min]);  应该是A[i]与A[min]交换
		}
		Swap(&A[min], &A[i]);
		Print(A, n);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	ElementType A[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d,", &A[i]);
	}

	SelectionSort(A, n);
	return 0;
}
#include <stdio.h>
typedef int ElementType;
#define CutOff 3
int p;
int cho = 0;
void Swap(ElementType *A, ElementType *B);
void InsertionSort(ElementType *A, int n);
int Median3(ElementType *A, int left, int right);
void QSort(ElementType *A, int left, int right);
void QuickSort(ElementType *A, int n);

void Swap(ElementType *A, ElementType *B)
{
	ElementType tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}
void InsertionSort(ElementType *A, int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		tmp = A[i];
		for (j = i; j > 0 && tmp < A[j - 1]; j--)
		{
			A[j] = A[j - 1];
			
		}
		A[j] = tmp;
		//! XXX   A[j] = A[tmp];XXXX
	}
}
int Median3(ElementType *A, int left, int right)
{
	int center = (left + right) / 2;
	while (A[left] > A[center])
	{
		Swap(&A[left], &A[center]);
	}
	while (A[left] > A[right])
	{
		Swap(&A[left], &A[right]);
	}
	while (A[center] > A[right])
	{
		Swap(&A[center], &A[right]);
	}
	Swap(&A[center], &A[right - 1]);
	return A[right - 1];
}
void QSort(ElementType *A, int left, int right)
{
	int i, j;
	int Pivot;
	if (right - left >= CutOff)
	{
		if (cho == 0)
		{
			cho = 1;
			Pivot = A[p];
			//!	Swap(&A[p], &A[right - 1]);
			Swap(&A[p], &A[right]);
			i = left - 1;
			j = right;
			for (;;)
			{
				while (A[++i] < Pivot){}
				while (A[--j] > Pivot){}
				if (i < j)
				{
					Swap(&A[i], &A[j]);
				}
				else
				{
					break;
				}
			}
			Swap(&A[i], &A[right]); //!
			printf("Qsort(%d,%d):", left, right);
			for (int x = 0; x < 10;x++)
			{
				printf("%d,", A[x]);
			}
			printf("\n");
			QSort(A, left, i - 1);
			QSort(A, i + 1, right);
		}
		else
		{
			cho = 1;
			Pivot = Median3(A, left, right);
			i = left;
			j = right - 1;
			for (;;)
			{
				while(A[++i]<Pivot){}
				while(A[--j]>Pivot){}
				if(i<j)
					Swap(&A[i], &A[j]);
				else
					break;
			}
			Swap(&A[i], &A[right - 1]);
			printf("Qsort(%d,%d):", left, right);
			for (int x = 0; x < 10;x++)
			{
				printf("%d,", A[x]);
			}
			printf("\n");
			QSort(A, left, i - 1);
			QSort(A, i + 1, right);
		}
	}
	else
	{////////////////////////////!  XXXX  left - right + 1  XXXX
		InsertionSort(A+left,right-left+1);
		printf("insert(%d,%d):",left,right-left+1);
		for (int x = 0; x < 10; x++)
		{
			printf("%d,", A[x]);
		}
		printf("\n");
	}
}
void QuickSort(ElementType *A, int n)
{
	QSort(A, 0, n - 1);
}
int main()
{
	int A[10] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
	scanf("%d", &p);
	QuickSort(A, 10);
	return 0;
}
#include <stdio.h>
int Median3(int A[], int Left, int Right);
void Qsort(int A[], int Left, int Right);
void QuickSort(int A[], int N);
void InsertionSort(int *A, int N);
void Swap(int *p, int *q);

int pt;
int cho = 0;

int main()
{
	int A[10] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
	int N = 10;
	scanf("%d", &pt);
	QuickSort(A, N);
	return 0;
}

void Swap(int *p, int *q)
{
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int Median3(int A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	/* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */
	Swap(&A[Center], &A[Right - 1]); /* Hide pivot */
	/* only need to sort A[ Left + 1 ] �� A[ Right �C 2 ] */
	return A[Right - 1]; /* Return pivot */
}

void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;
	if (Left + 3 <= Right)
	{ /* if the sequence is not too short */
		if (cho == 0)
		{
			Pivot = A[pt];
			cho = 1;
			Swap(&A[pt], &A[Right]);
			i = Left - 1;
			j = Right; /* why not set Left+1 and Right-2? */
			for (;;)
			{
				while (A[++i] < Pivot)
				{
				} /* scan from left ����һ�����ڵ���pivot��*/
				while (A[--j] > Pivot)//初始：Pivot=right --j=right-1  与 pivot(right 比较)
				{
				} /* scan from right ����һ��С�ڵ���pivot��*/
				if (i < j)
					Swap(&A[i], &A[j]); /* adjust partition */
				else
					break; /* partition done */
			}
			Swap(&A[i], &A[Right]); /* restore pivot */

			printf("Qsort(%d,%d):", Left, Right);//!不是i，j
			for (j = 0; j < 10; j++)
				printf("%d,", A[j]);
			printf("\n");

			Qsort(A, Left, i - 1);	/* recursively sort left part */
			Qsort(A, i + 1, Right); /* recursively sort right part */
		}
		else
		{
			Pivot = Median3(A, Left, Right); /* select pivot *///!唯一不同之处
			i = Left;
			j = Right - 1; /* why not set Left+1 and Right-2? */
			for (;;)
			{
				while (A[++i] < Pivot)
				{
				} /* scan from left ����һ�����ڵ���pivot��*/
				while (A[--j] > Pivot)
				{
				} /* scan from right ����һ��С�ڵ���pivot��*/
				if (i < j)
					Swap(&A[i], &A[j]); /* adjust partition */
				else
					break; /* partition done */
			}
			Swap(&A[i], &A[Right - 1]); /* restore pivot */
			printf("Qsort(%d,%d):", Left, Right);
			for (j = 0; j < 10; j++)
				printf("%d,", A[j]);
			printf("\n");
			Qsort(A, Left, i - 1);	/* recursively sort left part */
			Qsort(A, i + 1, Right); /* recursively sort right part */
		}
	}	 /* end if - the sequence is long */
	else /* do an insertion sort on the short subarray */
	{
		InsertionSort(A + Left, Right - Left + 1);
		printf("insert(%d,%d):", Left, Right - Left + 1);//!我超我的，我返回你妈呢？？直接左减右完事了
		for (j = 0; j < 10; j++)
			printf("%d,", A[j]);
		printf("\n");
	}
}
void InsertionSort(int *A, int N)
{
	int j, P;
	int Tmp;
	for (P = 1; P < N; P++)
	{
		Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}
void QuickSort(int A[], int N)
{
	Qsort(A, 0, N - 1);
	/* A: 	the array 	*/
	/* 0: 	Left index 	*/
	/* N �C 1: Right index	*/
}

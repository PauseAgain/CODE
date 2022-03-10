#include <stdio.h>
//!整了一下午，Theshy来了全错了！
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define CutOff 3 ////用于管理快速排序切换InsertionSort的数组大小
typedef int ElementType;
int p;
int cho = 0;
void Swap(ElementType *A, ElementType *B)
{
	ElementType tmp;
	tmp = *B;
	*B = *A;
	*A = tmp;
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
	}
}
ElementType Median3(ElementType *A, int left, int right)
{
	int center = (left + right) / 2;
	if (A[left] > A[center])
	{
		Swap(&A[left], &A[center]);
	}
	if (A[left] > A[right])
	{
		Swap(&A[left], &A[right]);
	}
	if (A[center] > A[right])
	{
		Swap(&A[center], &A[right]);
	}

	Swap(&A[right - 1], &A[center]);
	return A[right - 1];
}

void Qsort(ElementType *A,int left,int right)
{
	int i, j, Pivot;
	if (left+CutOff<=right)
	{
		if(cho==0)
		{
			cho = 1;
			Pivot = A[p];//!
			//!Swap(&A[Pivot], &A[right]);//!
			Swap(&A[p],&A[right]);
			i = left - 1;//!
			j = right;//!
			for (;;)
			{
				while(A[++i]<Pivot){}
				while(A[--j]>Pivot){}
				if(i<j)
				{
					Swap(&A[i], &A[j]);
				}
				else{
					break;
				}
			}
			Swap(&A[i], &A[right]);//!
			printf("Qsort(%d,%d):", left, right);
			for (int m = 0; m < 10;m++)
				printf("%d,", A[m]);
			printf("\n");
			Qsort(A, left, i-1);
			Qsort(A, i + 1, right);
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
				{
					Swap(&A[i], &A[j]);
				}
				else{
					break;
				}
			}
			Swap(&A[i],& A[right - 1]);
			printf("Qsort(%d,%d):", left, right);
			for (int m = 0; m < 10;m++)
				printf("%d,", A[m]);
			printf("\n");
			Qsort(A, left, i-1);
			Qsort(A, i + 1, right);
		}
	}
	else{
		InsertionSort(A + left, right - left + 1);
		printf("insert(%d,%d):",left,right-left+1);
		for (int m = 0; m < 10;m++)
			printf("%d,", A[m]);
		printf("\n");
	}
}
void QuickSort(ElementType *A,int n)
{
	Qsort(A, 0, n - 1);
}

int main()
{
	int A[10] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
	int n = 10;
	scanf("%d", &p);
	QuickSort(A, n);
	return 0;
}

// void QuickSort(ElementType *A, int left, int right)
// {
// 	int i, j;
// 	ElementType Pivot;
// 	if (cho==1)
// 	{
// 		if (right - left >= CutOff)
// 		{
// 			Pivot = Median3(A, left, right);
// 			//!注意与cho=0时候区别👇
// 			i = left ;
// 			j = right-1;
// 			for (;;)
// 			{
// 				while (A[++i] < Pivot)
// 				{
// 				}
// 				while (A[--j] > Pivot)
// 				{
// 				}
// 				if (i < j)
// 				{
// 					Swap(&A[i], &A[j]);
// 				}
// 				else
// 				{
// 					break;
// 				}
// 			}

// 			//! printf("Qsort(%d,%d):", left, right);
// 			//! for (int k = 0; k < 10; k++)
// 			//! {
// 			//! 	printf("%d,", A[k]);
// 			//! }
// 			//! printf("\n");

// 			Swap(&A[Pivot], &A[right - 1]);
// 			printf("Qsort(%d,%d):", left, right);
// 			for (int k = 0; k < 10; k++)
// 			{
// 				printf("%d,", A[k]);
// 			}
// 			printf("\n");
// 			QuickSort(A, left, i - 1);
// 			QuickSort(A, i + 1, right);
// 		}
// 		else
// 		{
// 			InsertionSort(A + left, right - left + 1);
// 			printf("insert(%d,%d):", left, right - left + 1);
// 			for (j = 0; j < 10; j++)
// 			{
// 				printf("%d,", A[j]);
// 			}
// 			printf("\n");
// 		}
// 	}
// 	else
// 	{
// 		cho = 1;
// 		if (right - left >= CutOff)
// 		{
// 			//!XXX Pivot = p;XXX
// 			Pivot = A[p];
// 			//! XXX i = left; XXX
// 			//! XXX  j = right - 1; XXX
// 			i = left - 1;
// 			j = right;
// 			for (;;)
// 			{
// 				while (A[++i] < Pivot)
// 				{
// 				}
// 				while (A[--j] > Pivot)
// 				{
// 				}
// 				if (i < j)
// 				{
// 					Swap(&A[i], &A[j]);
// 				}
// 				else
// 				{
// 					break;
// 				}
// 			}

// 			//! printf("Qsort(%d,%d):", left, right);
// 			//! for (int k = 0; k < 10; k++)
// 			//! {
// 			//! 	printf("%d,", A[k]);
// 			//! }
// 			//! printf("\n");

// 			Swap(&A[Pivot], &A[right - 1]);
// 			printf("Qsort(%d,%d):", left, right);
// 			for (int k = 0; k < 10; k++)
// 			{
// 				printf("%d,", A[k]);
// 			}
// 			printf("\n");
// 			QuickSort(A, left, i - 1);
// 			QuickSort(A, i + 1, right);
// 		}
// 		else
// 		{
// 			InsertionSort(A + left, right - left + 1);
// 			printf("insert(%d,%d):", left, right - left + 1);
// 			for (j = 0; j < 10; j++)
// 			{
// 				printf("%d,", A[j]);
// 			}
// 			printf("\n");
// 		}
// 	}
// }

// int main()
// {
// 	int A[10] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
// 	scanf("%d",&p);
// 	QuickSort(A, 0, 9);
// 	return 0;
// }
#include <stdio.h>

typedef int ElementType;

void Merge(ElementType *A, ElementType *TempArray, int leftpos, int rightpos, int rightend)
{
	int leftend=rightpos-1;
	int temppos=leftpos;
	int numelements=rightend-leftpos+1;

	while(leftpos<=leftend&&rightpos<=rightend)
	{
		if(A[leftpos]<=A[rightpos])
		{
			TempArray[temppos++]=A[leftpos++];
		}
		else
		{
			TempArray[temppos++]=A[rightpos++];
		}
	}
	while(leftpos<=leftend )
	{
		TempArray[temppos++]=A[leftpos++];
	}

	while(rightpos<=rightend)
	{
		TempArray[temppos++]=A[rightpos++];
	}

	for(int i=0;i<numelements;i++)
	{
		//!
		A[rightend-i]=TempArray[rightend-i]

		//or

		// A[rightend]=TempArray[rightend]
		// rightend--;
	}
}

void Msort(ElementType *A,ElementType *TempArray,int left,int right)
{
	int center;
	if(left<right)
	{
		center = (left + right) / 2;
		Msort(A, TempArray, left, center);
		Msort(A, TempArray, center + 1, right);
		Merge(A, TempArray, left, center + 1, right);
	}
}

void MergeSort(ElementType *A,int n)
{
	ElementType *TempArray;
	TempArray = (ElementType *)malloc(n * sizeof(ElementType));

	Msort(A, TempArray, 0, n - 1);
	free(TempArray);
}

void Merge(ElementType *A,ElementType *TempArray,int LeftPos,int RightPos ,int RightEnd)
{
	int LeftEnd = RightPos - 1;
	int TempPos = LeftPos;
	int NumElements = LeftPos - RightEnd + 1;

	while(LeftPos<=LeftEnd&& RightPos<=RightEnd)
	{
		if(A[LeftPos]<=A[RightPos])
		{
			TempArray[TempPos++]= A[LeftPos++];
		}
		else
		{
			TempArray[TempPos++]=A[RightPos++];
		}
	}
	while(LeftPos<=LeftEnd)
	{
		TempArray[TempPos++]= A[LeftPos++];
	}
	while(RightPos<=RightEnd)
	{
		TempArray[TempPos++]= A[RightPos++];
	}

	for (int i = 0; i < NumElements;RightEnd--)
	{
		A[RightEnd] = TempArray[RightEnd];
	}
}

void MSort(ElementType *A,ElementType *TempArray,int left ,int right)
{
	int center;
	if(left<right)
	{
		center = (left + right) / 2;
		MSort(A, TempArray, left, center);
		MSort(A, TempArray, center + 1, right);
		Merge(A, TempArray, left, center + 1, right);
	}
}

void MergeSort(ElementType *A,int n)
{
	ElementType TempArray;
	TempArray = (ElementType *)malloc(n * sizeof(ElementType));

	MSort(A, TempArray, 0, n - 1);
	free(TempArray);
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define cutoff 10 ////用于管理快速排序切换InsertionSort的数组大小
typedef int ElementType;

void Merge(ElementType *A, ElementType *TempArray, int LeftPos, int RightPos, int RightEnd)
{
	int i, LeftEnd, NumElements, TempPos;
	LeftEnd = RightPos - 1;
	TempPos = LeftPos;
	NumElements = RightEnd - LeftPos + 1;

	while (LeftPos <= LeftEnd && RightPos <= RightEnd)
	{
		if (A[LeftPos] <= A[RightPos])
		{
			TempArray[TempPos++] = A[LeftPos++];
		}
		else
		{
			TempArray[TempPos++] = A[RightPos++];
		}
	}
	while (LeftPos <= LeftEnd)
	{
		TempArray[TempPos++] = A[LeftPos++];
	}
	while (RightPos <= RightEnd)
	{
		TempArray[TempPos++] = A[RightPos++];
	}
	for (i = 0; i < NumElements; i++)
	{
		A[RightEnd] = TempArray[RightEnd];
		RightEnd--;
	}
}
void Msort(ElementType *A, ElementType *TempArray, int left, int right)
{
	//ElementType* TempArray=(ElementType*)malloc(sizeof(ElementType))
	int center;
	if(left<right)
	{
		center = (left + right) / 2;
		Msort(A, TempArray, left, center);
		Msort(A, TempArray, center + 1, right);
		Merge(A, TempArray, left, center + 1, right);
	}
}

void MergeSort(ElementType *A,int n)
{
	int left = 0;
	int right = n;
	ElementType *TempArray = (ElementType *)malloc(sizeof(ElementType)*n);
	Msort(A, TempArray, left, right);
	free(TempArray);
}
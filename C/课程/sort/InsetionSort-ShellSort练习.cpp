#include <stdio.h>
typedef int ElementType;

void InsertionSort(ElementType *A,int n)
{
	int j, p;
	ElementType temp;
	for (p = 1; p < n; p++)
	{
		temp = A[p];
		for (j = p; j > 0 && a[j - 1] > temp;j--)
		{
			a[j] = a[j - 1];
		}
		a[j]= temp;
	}
}

void ShellSort(ElementType *A,n)
{
	int i, j, increment;
	ElementType temp;
	for (increment = n / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < n;i++)
		{
			temp = A[i];
			for (j = i; j >= increment && A[j - increment] > temp;j-=increment)
			{
				A[j] = A[j - increment];
			}
			A[j] = temp;
		}
	}
}
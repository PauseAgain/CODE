#include<stdio.h>

typedef int ElementType;

void PrintSort(ElementType *A, int n)
{
	for (int i = 0; i < n;i++)
	{
		printf("%d,", A[i]);
	}
	printf("\n");
}

void ShellSort(ElementType *A,int n)
{
	int i, j, increment;
	ElementType temp;
	for (increment = n / 2; increment > 0;increment/=2)
	{
		for (i = increment; i < n;i++)
		{
			temp = A[i];
			for (j = i; j >= increment&& A[j-increment]<temp;/*j--*/j-=increment)//!发现错误 在| j-=increment √|  j-- X |
			{	
					A[j] = A[j - increment];
			}
			A[j] = temp;//!错误！它在（for j）循环外面！
		}
		PrintSort(A, n);
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

	ShellSort(A, n);
	
	return 0;
}
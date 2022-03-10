#include <stdio.h>
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d,", &A[i]);
	}
	int i, j;
	for ( i = 0; i < n - 1;i++)
	{
		int min = i;
		for (j = i + 1; j < n;j++)
		{
			if (A[j] < A[min])
				min = j;
		}
		Swap(&A[min], &A[i]);
		for (int x = 0; x < n; x++)
		{
			printf("%d,", A[x]);
		}
		printf("\n");
	}
		return 0;
}
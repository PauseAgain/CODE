#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d,", &A[i]);
	}
	////
	int i,j, k, tmp;
	for ( i = n / 2; i > 0; i /= 2)
	{
		int j, k, tmp;
		for (j = i; j < n; j++)
		{
			tmp = A[j];
			//! for (k = j; k > j - i && tmp < A[k - i]; k -= i)
			for (k = j; k >= i && tmp > A[k - i]; k -= i)
			{
				A[k] = A[k - i];
			}
			A[k] = tmp;
		}
		for (int f = 0; f < n; f++)
		{
			printf("%d,", A[f]);
		}
		printf("\n");
	}
	
	return 0;
}
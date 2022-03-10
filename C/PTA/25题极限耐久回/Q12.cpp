#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int b[a];
	for (int i = 0; i < a; i++)
	{
		scanf("%d,", &b[i]);
	}
	int  j,tmp;
	for (int i = 1; i < a; i++)
	{
		
		tmp = b[i];
		for (j = i; j > 0 && tmp < b[j - 1]; j--)
		{
			b[j] = b[j - 1];
		}
		b[j] = tmp;
		for (int k = 0; k < a; k++)
		{
			printf("%d,", b[k]);
		}
		printf("\n");
	}

	return 0;
}
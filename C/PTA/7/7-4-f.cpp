#include <stdio.h>
int main()
{
	char rubbish;
	int m, n, count = 0;
	scanf("%d%c%d", &n, &rubbish, &m);
	int number = n; //防止n被污染
	int a[n+1];
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}

	while (number > 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != 0)
			{
				count++;
			}
			if (count == m + 1)
			{
				printf("%d,", a[i]);
				a[i] = 0;
				count = 0;
				number--;
			}
			
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]!=0)
		{
			printf("%d",a[i]);
		}
	}

	return 0;
}
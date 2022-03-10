#include <stdio.h>
int main()
{
	int count = 0;
	int error = 0;
	int midnumber;
	char stack[100];
	while ((stack[count] = getchar()) != '\n')
	{
		if (stack[count] != ',')
		{
			count++;
		}
	}
    count--;//玄学--理解一下
	////printf("\n%d\n",count);
	midnumber = count / 2; //偶数时候是靠左边的中间数//奇数的时候真·中间数
	if (count % 2 == 1)	   //even
	{
		for (int i = 0; i < midnumber; i++)
		{
			if (stack[i] != stack[count - i])
			{
				error = -1;
			}
		}
	}
	else //odds
	{
		for (int j = 0; j < midnumber; j++)
		{
			if (stack[j] != stack[count - j])
			{
				error = -1;
			}
		}
	}
	if(error==0)
	{
		printf("Yes\n");
	}
	if(error==-1)
	{
		printf("No\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int judge(char a, char b)
{
	if ((a == '+' && b == '+') || (a == '+' && b == '-') || (a == '-' && b == '-') || (a == '-' && b == '+') || (a == '*' && b == '*') || (a == '*' && b == '/') || (a == '/' && b == '*') || (a == '/' && b == '/'))
		return 0;
	else if ((a == '+' && b == '*') || (a == '+' && b == '/') || (a == '-' && b == '*') || (a == '-' && b == '/'))
		return -1;
	else
		return 1;
}

int main()
{
	char x;
	double x1, x2, result;
	int top1 = -1;
	int top2 = -1;
	int p = -1;
	char array[100];
	char stack1[100];
	double stack2[100];

	for (int i = 0; i < 100; i++)
	{
		array[i] = '\0';
	}
	while (scanf("%c", &x) != EOF)//while(scanf("%c",&x)!= EOF)
	{
		if ((x >= '0') && (x <= '9'))
			array[++p] = x;
		else if (x == '(')
			stack1[++top1] = x;
		if (x == ')')
			while ((top1 != -1) && (stack1[top1] != '('))
			{
				array[++p] = stack1[top1--];
			}
		top1--;
		if ((x == '*') || (x == '/'))
		{
			if (stack1[top1] == '(')
			{
			}
			else if (judge(x, stack1[top1]) <= 0)
			{
				while ((top1 != -1) && (stack1[top1] != '('))
					array[++p] = stack1[top1--];
					if(array[p]=='+' || array[p]=='-')
						break;
			}
			else
			{
			}
		}
		stack1[++top1] = x;
		if ((x == '+') || (x == '-'))
			while ((top1 != -1) && (stack1[top1] != '('))
				array[++p] = stack1[top1--];
		stack1[++top1] = x;
	}
	while (top1 != -1)
	{
		array[++p] = stack1[top1--];
	}

	//////////////////??!/////////////////////???!////////////////////?!!//!/////////
	for (int i = 0; array[i] != '\0'; i++)
	{
		if ((array[i] >= '0') && (array[i] <= '9'))
		{
			stack2[++top2] = (double)(array[i] - '0');
		}
		if (array[i] == '+')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x1 + x2;
			stack2[++top2] = result;
		}
		if (array[i] == '-')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x1 - x2;
			stack2[++top2] = result;
		}
		if (array[i] == '*')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x1 * x2;
			stack2[++top2] = result;
		}
		if (array[i] == '/')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x1 / x2;
			stack2[++top2] = result;
		}
	}
	printf("%.2lf\n", stack2[0]);
	for (int i = 0; array[i] != '\0'; i++)
	{
		printf("%c ", array[i]);
	}
	printf("\n");

	return 0;
}
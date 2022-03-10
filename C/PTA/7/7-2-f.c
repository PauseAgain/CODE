#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int JudgePriority(char a, char b)
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
	char stack[100];
	double stack2[100];
	char array[20];
	for (int i = 0; i < 20; i++)
	{
		array[i] = '\0';
	}
	int top = -1;
	int top2 = -1;
	int p = -1;
	char x;
	while (scanf("%c", &x) != EOF)
	{
		if (x >= '0' && x <= '9')
		{
			array[++p] = x;
		}
		else
		{
			if (x == '(')
			{
				stack[++top] = x;
			}
			if (x == ')')
			{
				while (stack[top] != '(')
				{
					array[++p] = stack[top--];
				}
				top--;
			}

			if (x == '*' || x == '/')
			{

				if (stack[top] == '(') //?/????????????
				{
				}
				else if (JudgePriority(stack[top], x) >= 0)
					while (top != -1 && stack[top] != '(')
					{
						array[++p] = stack[top--];
						if (array[p] == '+' || array[p] == '-')
							break;
					}
				stack[++top] = x;
			}
			if (x == '+' || x == '-')
			{
				while (top != -1 && stack[top] != '(')
				{
					array[++p] = stack[top--];
				}
				stack[++top] = x;
			}
		}
	}

	while (top != -1)
	{
		array[++p] = stack[top--];
	}

	//计算表达式的结果：
	double x1, x2, result;
	for (int i = 0; array[i] != '\0'; i++)
	{
		if (array[i] >= '0' && array[i] <= '9')
		{
			
			stack2[++top2] = (array[i] - '0');
		}
		else if (array[i] == '+')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x1 + x2;
			stack2[++top2] = result;
		}
		else if (array[i] == '-')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x2 - x1;
			stack2[++top2] = result;
		}
		else if (array[i] == '*')

		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x1 * x2;
			stack2[++top2] = result;
		}
		else if (array[i] == '/')
		{
			x1 = stack2[top2--];
			x2 = stack2[top2--];
			result = x2 / x1;
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
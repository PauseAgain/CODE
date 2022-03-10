#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlen 100
typedef char ElementType;
typedef double ElementType2;

typedef struct node
{
	ElementType element;
	struct node *next;
} node, *StackNodePtr;
typedef struct StackNode
{
	StackNodePtr top;
	int count;
} StackNode, *LinkStack;

typedef struct node2
{
	ElementType2 element;
	struct node2 *next;
} node2, *StackNodePtr2;
typedef struct StackNode2
{
	StackNodePtr2 top;
	int count;
} StackNode2, *LinkStack2;

LinkStack InitialStack(void)
{
	LinkStack S;
	S = (LinkStack)malloc(sizeof(StackNode));
	S->top = (StackNodePtr)malloc(sizeof(node));
	if (S->top == NULL)
	{
		printf("InitialStack ERROR!");
		return 0;
	}
	else
	{
		S->top = NULL;
		S->count = 0;
		return S;
	}
}
LinkStack2 InitialStack2(void)
{
	LinkStack2 S;
	S = (LinkStack2)malloc(sizeof(StackNode2));
	S->top = (StackNodePtr2)malloc(sizeof(node2));
	if (S->top == NULL)
	{
		printf("InitialStack ERROR!");
		return 0;
	}
	else
	{
		S->top = NULL;
		S->count = 0;
		return S;
	}
}
void Push(ElementType X, LinkStack S)
{
	StackNodePtr s;
	s = (StackNodePtr)malloc(sizeof(node));
	s->element = X;
	////printf("\n测试：push了%c\n", X);
	s->next = S->top;
	S->top = s;
	S->count++;
}
void Push2(ElementType2 X, LinkStack2 S)
{
	StackNodePtr2 s;
	s = (StackNodePtr2)malloc(sizeof(node2));
	s->element = X;
	////printf("\n测试：push2了%.2lf\n", X);
	s->next = S->top;
	S->top = s;
	S->count++;
}
ElementType Pop(LinkStack S)
{
	ElementType i = 0;
	StackNodePtr tmp;
	//!忘了if(S->top!=NULL)
	if (S->top != NULL)
	{
		i = S->top->element;
		tmp = S->top;
		S->top = S->top->next;
		////printf("\n测试：pop了%c\n", i);
		free(tmp);
		return i;
	}
	else
	{
		printf("Pop ERROR1！");
		return 0;
	}
}
ElementType2 Pop2(LinkStack2 S)
{
	double i;
	StackNodePtr2 tmp;
	//!忘了if(S->top!=NULL)
	if (S->top != NULL)
	{
		S->top->element = i;
		tmp = S->top;
		S->top = S->top->next;
		free(tmp);
		return i;
	}
	else
	{
		printf("Pop ERROR2！");
	}
}

ElementType Top(LinkStack S)
{
	if (S->top != NULL)
	{
		return S->top->element;
	}
	else
	{
		//? printf("S->top is NULL！");
		return -1;
	}
}
ElementType2 Top2(LinkStack2 S)
{
	if (S->top != NULL)
	{
		return S->top->element;
	}
	else
	{
		// printf("S->top is NULL！");
		return -1;
	}
}

int GetStackLong(LinkStack S)
{
	if (S)
	{
		return S->count;
	}
	else
	{
		printf("S is NULL！");
		return 0;
	}
}

int main()
{
	ElementType Array[maxlen] = {'\0'};

	LinkStack S1 = InitialStack();

	char x;
	int index = 0;
	while ((x = getchar()) != '\n' && x != EOF)
	{
		if (x >= '0' && x <= '9')
		{
			Array[index++] = x;
		}
		else
		{
			if (x == '(')
			{
				Push(x, S1);
			}
			if (x == ')')
			{
				while (Top(S1) != EOF)
				{
					if (Top(S1) == '(')
					{
						Pop(S1);
						break;
					}
					else
					{
						Array[index++] = Pop(S1);
					}
				}
			}
			if (x == '*' || x == '/')
			{
				while (Top(S1) == '*' || Top(S1) == '/')
				{
					Array[index++] = Pop(S1);
				}
				Push(x, S1);
			}
			if (x == '+' || x == '-')
			{
				while (Top(S1) != EOF && Top(S1) != '(')
				{
					Array[index++] = Pop(S1);
				}
				Push(x, S1);
			}
		}
	}
	while (Top(S1) != EOF)
	{
		Array[index++] = Pop(S1);
	}

	////printf("\n测试：%s\n", Array);

	double x1, x2, result;
	LinkStack2 S2 = InitialStack2();
	for (int i = 0; Array[i] != '\0'; i++)
	{
		if (Array[i] <= '9' && Array[i] >= '0')
		{
			double n = Array[i] - '0';
			Push2(n, S2);
		}
		else if (Array[i] == '+')
		{
			x1 = S2->top->element;
			x2 = S2->top->next->element;
			result = x2 + x1;
			Pop2(S2);
			Pop2(S2);
		////	printf("\nx2(%.2lf)+x1(%.2lf)=(%.2lf)\n", x2, x1, result);
			Push2(result, S2);
		}
		else if (Array[i] == '-')
		{
			x1 = S2->top->element;
			x2 = S2->top->next->element;
			result = x2 - x1;
			Pop2(S2);
			Pop2(S2);
		////	printf("\nx2(%.2lf)-x1(%.2lf)=(%.2lf)\n", x2, x1, result);
			Push2(result, S2);
		}
		else if (Array[i] == '*')
		{
			x1 = S2->top->element;
			x2 = S2->top->next->element;

			result = x2 * x1;
			Pop2(S2);
			Pop2(S2);
		////	printf("\nx2(%.2lf)*x1(%.2lf)=(%.2lf)\n", x2, x1, result);
			Push2(result, S2);
		}
		else if (Array[i] == '/')
		{
			x1 = S2->top->element;
			x2 = S2->top->next->element;
			result = x2 / x1;
			Pop2(S2);
			Pop2(S2);
		////	printf("\nx2(%.2lf)/x1(%.2lf)=(%.2lf)\n", x2, x1, result);
			Push2(result, S2);
		}
	}
	printf("%.2lf\n", Top2(S2));
	for (int i = 0; Array[i] != '\0'; i++)
	{
		printf("%c ", Array[i]);
	}
	printf("\n");
	return 0;
}
   #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 500

typedef struct Stack
{
	char Array[MaxSize];
	int Top;
	double num[MaxSize];
	int TopInt;
} SnStack;

void InitStack(SnStack *S)
{
	S->Top = -1;
	S->TopInt = -1;
}

bool IsEmpty(SnStack S)
{
	return S.Top == -1;
}

bool IsFull(SnStack S)
{
	return S.Top == MaxSize - 1;
}

bool Push(SnStack *S, char element)
{
	if (IsFull(*S))
		return false;
	S->Array[++S->Top] = element;
	return true;
}

void PushInt(SnStack *S, double element)
{
	S->num[++S->TopInt] = element;
	return;
}

char Top(SnStack S)
{
	if (IsEmpty(S))
		return 'a';
	return S.Array[S.Top];
}

char Pop(SnStack *S)
{
	if (IsEmpty(*S))
		return 'a';
	return S->Array[S->Top--];
}

double PopInt(SnStack *S)
{
	return S->num[S->TopInt--];
}

int JudgePriority(char a, char b)
{
	if (a == '+' && b == '+' || a == '+' && b == '-' || a == '-' && b == '-' || a == '-' && b == '+' || a == '*' && b == '*' || a == '*' && b == '/' || a == '/' && b == '*' || a == '/' && b == '/')
		return 0;
	else if (a == '+' && b == '*' || a == '+' && b == '/' || a == '-' && b == '*' || a == '-' && b == '/')
		return -1;
	else
		return 1;
}

int main()
{
	SnStack S;
	SnStack Cal;
	char zanshi[MaxSize];
	int len = 0;
	InitStack(&S);
	char x;
	while (scanf("%c", &x) != EOF)
	{
		if (x >= '0' && x <= '9')
			//printf("%c ", x);
			zanshi[len++] = x;
		else
		{
			if (IsEmpty(S) || x == '(')
				Push(&S, x);
			else
			{
				if (x == '+' || x == '-')
				{
					while (!IsEmpty(S) && Top(S) != '(')
					{
						//printf("%c ", Pop(&S));
						zanshi[len++] = Pop(&S);
					}
					Push(&S, x);
				}
				else if (x == '*' || x == '/')
				{
					if(Top(S)=='('){}
					else if (JudgePriority(Top(S), x) >= 0)
						while (!IsEmpty(S) && Top(S) != '(')
						{
							char temp = Pop(&S);
							//printf("%c ", temp);
							zanshi[len++] = temp;
							if (temp == '+' || temp == '-')
								break;
						}
					Push(&S, x);
				}
				else if (x == ')')
				{
					while (Top(S) != '(')
					{
						//printf("%c ", temp);
						zanshi[len++] = Pop(&S);
					}
					Pop(&S);
				}
			}
		}
	}
	while (!IsEmpty(S))
	{
		if (Top(S) != '('&&Top(S)!=')')
			zanshi[len++] = Pop(&S);
		else
			Pop(&S);
	}
	//printf("%c ", Pop(&S));

	InitStack(&Cal);
	for (int i = 0; i < len; i++)
	{
		if (zanshi[i] >= '0' && zanshi[i] <= '9')
			PushInt(&Cal, zanshi[i] - '0');
		else if (zanshi[i] == '+')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = a + b;
			//printf("c=%lf\n", c);
			PushInt(&Cal, c);
		}
		else if (zanshi[i] == '-')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = b - a;
			//printf("c=%lf\n", c);
			PushInt(&Cal, c);
		}
		else if (zanshi[i] == '*')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = a * b;
			//printf("c=%lf\n",c);
			PushInt(&Cal, c);
		}
		else if (zanshi[i] == '/')
		{
			double a = PopInt(&Cal);
			//printf("a=%d\n",a);
			double b = PopInt(&Cal);
			//printf("b=%d\n",b);
			double c = (1.0) * b / a;
			//printf("c=%lf\n",c);
			PushInt(&Cal, c);
		}
	}
    zanshi[len]='@';
	printf("%.2lf\n", PopInt(&Cal));
	/*for (int i = 0; i < len; i++)
		printf("%c ", zanshi[i]);
        */
    int i=0;
    while(zanshi[i]!='@')
    {
        printf("%c ", zanshi[i]);
        i++;
    }
	return 0;
}

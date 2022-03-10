/*#include <stdio.h>
#include <stdlib.h>
//设置等级level
//level-0:number;level-1:+,-;level-2:*,/
//决定先转换为后置再计算
struct node
{
	char symbol;
	struct node *next;
};

typedef struct node *STACK;
STACK MakeStack(void);
int IsEmpty(STACK s);		  //1,0
void push(char sym, STACK s); //把level判断写到push函数里面去
void pop(STACK s);
char top(STACK s);
int levelcompare(char a, char b);

STACK MakeStack(void)
{
	STACK s = (struct node *)malloc(sizeof(struct node));
	s->next = NULL;
	return s;
}

int IsEmpty(STACK s)
{
	return s->next == NULL;
}

void push(char sym, STACK s)
{
	STACK p = (struct node *)malloc(sizeof(struct node));
	p->symbol = sym;
	p->next = s->next;
	s->next = p;
}
int levelcompare(char a, char b)
{
	if ((a == '*' || b == '+') || (a == '*' || b == '-') || (a == '/' || b == '+') || (a == '/' || b == '-'))
	{
		return 1;
	}
	else if ((a == '+' || b == '*') || (a == '+' || b == '/') || (a == '-' || b == '*') || (a == '+' || b == '/'))
	{
		return -1;
	}
	else if ((a == '*' || b == '*') || (a == '+' || b == '+') || (a == '-' || b == '-') || (a == '/' || b == '/'))
	{
		return 0;
	}
	else if ((a == '/' || b == '*') || (a == '*' || b == '/') || (a == '+' || b == '-') || (a == '-' || b == '+'))
	{
		return 0;
	}
	else
	{
		printf("error!");
	}
}
void pop(STACK s)
{
	STACK p;
	p = s->next;
	s->next = s->next->next;
	free(p);
}

char top(STACK s)
{
	return s->next->symbol;
}

int main()
{
	STACK s = MakeStack();
	int i = 0;
	char a[100];
	scanf("%s", a);
	//	printf("%s",a);
	while (a[i] != '\0')
	{
		if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '(' || a[i] == ')')
		{
			printf("AAA!");
			if (a[i] == '(')
			{
				push(a[i], s);
			}
			else if (a[i] == ')')
			{
				while (top(s) != '(')
				{
					printf("1%c ", top(s));
					pop(s);
				}
				pop(s);
			}
			else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
			{
				if (IsEmpty(s) == 1)
				{
					push(a[i], s);
				}
				else if (levelcompare(a[i], top(s)) >= 0)
				{
					push(a[i], s);
				}
				else if (levelcompare(a[i], top(s)) < 0)
				{
					while (levelcompare(a[i], top(s)) <= 0)
					{
						printf("2%c ", top(s));
						pop(s);
					}
					push(a[i], s);
				}
			}
			while (s)
			{
				printf("3%c ", top(s));
				s = s->next;
			}
		}
		else
		{
			printf("%c ", a[i]);
		}
		i++;
	}

	return 0;
}
*/
#define EOF -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

 char stack[100];
 double stack2[100];
 char array[20];

 for (int i = 0; i < 20; i++)
 {
  array[i] = '0'; //初始化array数组
 }
 int top = -1;

 int top2 = -1;

 int p = -1;
 char x;
 while ((x = getchar()) != '\n' && x != EOF)
    {
        if (x >= '0' && x <= '9')
        {
            p++;
            array[p] = x;
        }
        else
        {
            if (x == '(')
            {
                top++;
                stack[top] = x;
            }
            if (x == ')')
            {
                while (stack[top] != '(')
                {
                    p++;
                    array[p] = stack[top];
                    top--;
                }
                top--;
            }

            if (x == '*' || x == '/')
            {
                while (stack[top] == '*' || stack[top] == '/')
                {
                    p++;
                    array[p] = stack[top];
                    top--;
                }
                top++;
                stack[top] = x;
            }
            if (x == '+' || x == '-')
            {
                while (top != -1 && stack[top] != '(')
                {
                    p++;
                    array[p] = stack[top];
                    top--;
                }

                top++;
                stack[top] = x;
            }
        }
    }

    while (top != -1)
    {
        p++;
        array[p] = stack[top];
        top--;
    }


 double x1, x2, result;

 for (int j = 0; array[j] != '0'; j++)
 {
  if (array[j] >= '0' && array[j] <= '9')
  {
   top2++;
   stack2[top2] = (double)(array[j] - '0'); //换算成数字（double）了？
  }
  else if (array[j] == '+')
  {
   x1 = stack2[top2--]; //这是'之前的数字'
   x2 = stack2[top2];  //这是x1之前的数字
   result = x1 + x2;  //第二个--和后一个++是否重复？
   stack2[top2] = result;
  }
  else if (array[j] == '-')
  {
   x1 = stack2[top2--];
   x2 = stack2[top2];
   result = x2 - x1;
   stack2[top2] = result;
  }
  else if (array[j] == '*')
  {
x1 = stack2[top2--];
   x2 = stack2[top2];
   result = x1 * x2;
   stack2[top2] = result;
  }
  else if (array[j] == '/')
  {
   x1 = stack2[top2--];
   x2 = stack2[top2];
   result = x2 / x1;
   stack2[top2] = result;
  }
 }
 printf("%.2f", stack2[0]);
 printf("\n");
 for (int i = 0; array[i] != '\0'; i++)
 {
  printf("%c ", array[i]);
 }
 return 0;
}
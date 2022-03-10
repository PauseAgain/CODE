#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
	char symbol;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *STACK;
typedef struct node *POSITION; //STACK,POSITION都是node*型

STACK MakeStack(void);		//创建空链表不需要输入什么
int IsEmpty(STACK s);		//isempty(A)函数是一个判断是否为空的一个函数
void push(STACK s, char x); //push也是void型
void pop(STACK s);
char top(STACK s); //char类型紧跟data
int match(char p, char q);

STACK MakeStack(void)
{
	STACK s = (struct node *)malloc(sizeof(struct node));
	/*if (s == NULL)
	{
		printf("memory error");
	}*/
	//else
	//{
	s->next = NULL;
	return s;
	//}
}
//!不是很明白IsEmpty的意义
int IsEmpty(STACK s)
{ //!这句话整不明白！
	return s->next == NULL;
}
void push(STACK s, char q)
{
	if (s == NULL)
	{
		printf("Please make a list at first!");
	}
	POSITION p = (struct node *)malloc(sizeof(struct node));
	if (p == NULL)
	{
		printf("memory error!");
	}
	else
	{
		p->symbol = q;
		p->next = s->next;
		s->next = p;
	}
}

void pop(STACK s)
{
	POSITION p;
	if (IsEmpty(s))
	{
		printf("Empty Stack!");
	}
	else
	{ //!这一段也不懂
		//printf("%c has been poped!\n", top(s));
		p = s->next;
		s->next = s->next->next;
		free(p);
	}
}

char top(STACK s)
{
	return s->next->symbol;
}

int match(char p /*a[i]*/, char q /*top(s)*/)
{ //40,41,91,93,123,125
	if (abs(p - q) == 1)
		return 0;
	else if (abs(p - q) == 2)
		return 0;
	else
		return 1;
}
int main()
{
	STACK s = MakeStack();
	STACK y = MakeStack();
	char a[50];
	int number[4]={0,0,0,0};
	scanf("%s", a);
	int i = 0;
	while (a[i] != 0)
	{
		if (a[i] == '(' || a[i] == '[' || a[i] == '{')
		{
			//printf("%c", a[i]);
			push(s, a[i]);
			//printf("%chas been pushed!\n", top(s));
		}
		else if (a[i] == '}' || a[i] == ']' || a[i] == ')')
		{

			if (match(a[i], top(s)) == 0)
			{
				pop(s);
			}
			else{
				push(y,a[i]);
			}
		}

		i++;
	}
	if (IsEmpty(s))
	{
		printf("0");
	}
	else
	{
		while (s)
		{
			if (s->symbol == '(')
			{number[1]=1;
			}
			else if (s->symbol == '[')
			{
				number[2]=1;
			}
			else if (s->symbol == '{')
			{
			number[3]=1;
			}
			s = s->next;
		}
		while (y)
		{
			if (y->symbol == ')')
			{
				number[1]=1;
			}
			else if (y->symbol == ']')
			{
			number[2]=1;
			}
			else if (y->symbol == '}')
			{
				number[3]=1;
			}
			y = y->next;
		}
		for(int j=1;j<4;j++)
		{
			if(number[j]==1)
			{
				printf("%d,",j);
			}
		}
	}
	printf("\n");
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char ElementType;
typedef struct StackNode
{
	ElementType element;
	//!!StackNode *next;忘了！！！！struct  ！！！
	struct StackNode *next;
} StackNode;
typedef struct stack{
	StackNode *top;
	int count;
}stack, * LinkStack;

LinkStack InitializeStack(void)
{
	LinkStack S;
	S = (LinkStack)malloc(sizeof(stack));
	//! S = (LinkStack)malloc(sizeof(StackNode *) + sizeof(int));
	S->top = (StackNode *)malloc(sizeof(struct StackNode));
	if (S->top == NULL)
	{
		printf("ERROR! InitializeStack!");
	}
	else{
		S->top = NULL;
		S->count = 0;
	}

	return S;
}

void Push(ElementType X,LinkStack S)
{
	StackNode *s;
	s = (StackNode *)malloc(sizeof(struct StackNode));
	s->element = X;
	//! if(S->top)
	//!{
		s->next = S->top;
		S->top = s;
		S->count++;
		//! }
}

ElementType Pop(LinkStack S)
{
	StackNode *tmp;
	ElementType key=0;
	tmp = (StackNode *)malloc(sizeof(StackNode));
	if(S->top!=NULL)
	{
		tmp = S->top;
		S->top = S->top->next;
		key = tmp->element;
		free(tmp);
		S->count--;
	}
	return key;
}
void PrintStack(LinkStack S)
{
	//!错在会改变指针
	// //! while(S->top){
	//! 	printf("%c", S->top->element);
	//! 	S->top = S->top->next;
	//! }
	StackNode *tmp;
	tmp = S->top;
	while(tmp)
	{
		printf("%c", tmp->element);
		tmp = tmp->next;
	}
}

int GetStackLong(LinkStack S)
{
	return S->count;
}

ElementType GetTop(LinkStack S)
{
	return S->top->element;
}

//1

int main()
{
	LinkStack S=InitializeStack();
	int error[3] = { 0, 0, 0};
	char x;
	while(scanf("%c",&x)!=EOF)
	{
		////printf("测试：%c\n", x);
		if (x == '(' || x == '[' || x == '{')
		{
			Push(x, S);
		}
		if(x==')'||x==']'||x=='}')
		{
			if(x=='(')
			{
				if(GetTop(S)=='(')
				{
					Pop(S);
				}
				else{
					error[0] = 1;
				}
			}
			else if(x=='[')
			{
				if(GetTop(S)==']')
				{
					Pop(S);
				}
				else{
					error[1] = 1;
				}
			}
			else if(x=='}')
			{
				if(GetTop(S)=='{')
				{
					Pop(S);
				}
				else{
					error[2] = 1;
				}
			}
			else{}
		}
	}
	if(S->top==NULL)
	{
		
	}
	else
	{
		while(S->top)
		{

		if(GetTop(S)=='(')
		{
			Pop(S);
			error[0] = 1;
		}
		if(GetTop(S)=='[')
		{
			Pop(S);
			error[1] = 1;
		}
		if(GetTop(S)=='{')
		{
			Pop(S);
			error[2] = 1;
		}
		}
	}

	if(error[0]==0&&error[1]==0&&error[2]==0)
	{
		printf("0\n");
	}
	else
	{
		if(error[0]==1)
		{
			printf("1,");
		}
		if(error[1]==1)
		{
			printf("2,");
		}
		if(error[2]==1)
		{
			printf("3,");
		}
	}
	return 0;
}

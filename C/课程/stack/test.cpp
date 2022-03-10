#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;
//?两段式定义法
typedef struct node
{
	DataType data;
	struct node *next;
}  *linkstackptr;

typedef struct stack{
	linkstackptr top;//!栈顶指针
	int count;//!计数器
} *LinkStack;

//!/*  构造一个空栈S */
bool InitStack(LinkStack S)//!造栈 *S
{ 
        S -> top = (linkstackptr)malloc(sizeof(struct node));//创造S的空间（S->top！=NULL）此时
        if(S -> top==NULL)
                return false;
        S -> top = NULL;//令S->top==NULL来初始化
        S -> count = 0;//计数器初始化
        return true;
}

//!链栈的进栈操作算法（类似于链表的插入）：
//1:先对数据域进行赋值，2:然后让新结点指向栈顶指针，3:最后将栈顶指针交给新节点。
bool push(LinkStack S,DataType element )//!入栈 *S
{
//?小s是创造的新节点的指针 包含数据data和链表指针next
//?    大S是原有的栈 包含栈顶指针（与小s同类top）和计数器count
	linkstackptr s = (linkstackptr)malloc(sizeof(struct node));
	s->data = element;//对数据域进行赋值
	s->next = S->top;//把当前栈顶的值赋给新的元素的后继（指针的指向）
	S->top = s;//新的节点赋值给栈顶指针
	S->count++;//计数器增加一个

	return true;
}

//!链栈的出栈操作算法（类似于链表的删除操作）：
////1:将要删除的元素的值交给临时变量，//!似乎正常情况下不用
// 2:将栈顶指针交给临时节点（栈只在栈顶进行操作，不用担心其他问题），
//3:将栈顶指针下移，//4:最后释放临时节点（即完成删除）。
bool pop(LinkStack S)//!出栈 *S
{
	linkstackptr temp;//临时指针节点
	if(S->count==0)
		return false;
	else
	{
		temp = S->top;//将栈顶指针交给temp
		S->top = S->top->next;//使得栈顶指针往下挪一位
		free(temp);//释放原来的栈顶指针
		S->count--;//计数器减减
		return true;
	}
}

bool TraverseStack(LinkStack S)//!遍历打印栈
{
	linkstackptr temp;//临时指针节点
	temp = S->top;//为临时节点赋值S->top
	while(temp)//遍历temp节点并且打印
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	return true;
}

int StackLength(LinkStack S)//!获得栈长度
{
	return S->count;
}

//!x* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
int GetTop(LinkStack S,DataType *element)
{
        if (S->top == NULL)
                return 0;
        else
                *element = S->top -> data;//!以改变指针形式传输top-element的值
        return 1;
}
int main()
{
	LinkStack L;
	InitStack(L);
	printf("%d", L->count);
	return 0;
}
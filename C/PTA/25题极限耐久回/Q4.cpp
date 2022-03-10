#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node{
	struct Node *pre;
	struct Node *next;
	ElementType element;
} Node, *RoundList;

RoundList Initialize(void)
{
	RoundList R;
	R = (RoundList)malloc(sizeof(Node));
	R->next = NULL;
	R->pre = NULL;
	R->element = 0;
	return R;
}
RoundList Insert(ElementType X,RoundList R)
{
	RoundList N=Initialize();
	N->element = X;
	R->next = N;
	N->pre = R;
	return N;
}
ElementType Pop(RoundList R)
{
	printf("Pop启动！");
	ElementType ele = R->element;
	RoundList N;
	N = R->next;
	R->pre->next = R->next;
	R->next->pre = R->pre;
	R = N;
	return ele;
}

int main()
{
	int n;
	int m;
	scanf("%d,", &n);
	scanf("%d", &m);

	RoundList R = Initialize();
	RoundList head = R;

	for (int i = 1; i <= n; i++)
	{
		R=Insert(i, R);
	}
	R->next = head;
	head->pre = R;
	R->next = head->next;
	head = R->next;

	// for (int i = 0; i <= 25; i++)
	// {
	// 	printf("%d,", head->element);
	// 	head = head->next;
	// }
	// printf("\n");

	//printf("%d\n", head->element);
	if(n!=1)
		for (int i = 1; i <= n; i++)
		{int count = 0;
			for (;;)
			{
				if(count<m)
				{
					head = head->next;
					count++;
				}
				else{
					if(i!=n)
						printf("%d,", head->element);//先TOP出结果
					else 
						printf("%d", head->element);
						
					//!进行一个pop head & head=head->next；的操作
					RoundList P = head->pre;
					RoundList N = head->next;
					head = head->next;
					P->next = N;
					N->pre = P;

					break;
				}
			}
		}
	else
		printf("1");
	printf("\n");
	return 0;
}

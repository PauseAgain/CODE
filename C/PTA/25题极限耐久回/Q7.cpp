#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct AvlNode
{
	int height;
	ElementType element;
	struct AvlNode*left;
	struct AvlNode*right;
} AvlNode, *AvlTree;

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
AvlTree MakeEmpty(AvlTree T)
{
	if (T!=NULL)
	{
		MakeEmpty(T->right);
		MakeEmpty(T->left);
		free(T);
	}
	return NULL;
}

int Hight(AvlTree T)
{
	if (T == NULL)
		return 1;
	else
		return (1 + max(Hight(T->left), Hight(T->right)) );
}
AvlTree SingleRotateWithLeft(AvlTree K2)
{
	AvlTree K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;

	K2->height = max(Hight(K2->left), Hight(K2->right)) + 1;
	K1->height = max(Hight(K1->left), Hight(K1->right)) + 1;
	return K1;
}
AvlTree SingleRotateWithRight(AvlTree K2)
{
	AvlTree K1 = K2->right;
	K2->right = K1->left;
	K1->left = K2;

	K2->height = max(Hight(K2->left), Hight(K2->right)) + 1;
	K1->height = max(Hight(K1->left), Hight(K1->right)) + 1;
	return K1;
}
AvlTree DoubleRotateWithLeft(AvlTree K3)
{
	K3->left = SingleRotateWithRight(K3->left);
	return SingleRotateWithLeft(K3);
}
AvlTree DoubleRotateWithRight(AvlTree K3)
{
	K3->right = SingleRotateWithLeft(K3->right);
	return SingleRotateWithRight(K3);
}

AvlTree AvlInsert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(AvlNode));
		T->element = X;
		T->height = 0;
		T->left = T->right = NULL;
	}
	else
	{
		if (X < T->element)
		{
			T->left = AvlInsert(X,T->left);
			if (Hight(T->left) - Hight(T->right) == 2)
			{
				if (X < T->left->element)
				{
					T = SingleRotateWithLeft(T);
				}
				else
				{
					T = DoubleRotateWithLeft(T);
				}
			}
		}
		else if (X > T->element)
		{
			T->right = AvlInsert(X,T->right);
			if (Hight(T->right) - Hight(T->left) == 2)
			{
				if (X > T->right->element)
				{
					T = SingleRotateWithRight(T);
				}
				else
				{
					T = DoubleRotateWithRight(T);
				}
			}
		}
	}
	T->height = max(Hight(T->left), Hight(T->right)) + 1;
	return T;
}
void PrintAvlTree(AvlTree T)
{
	if(T)
	{
		printf("%d,", T->element);
		if(T->left)
		{
			PrintAvlTree(T->left);
		}
		if(T->right)
		{
			PrintAvlTree(T->right);
		}
	}
}
int main()
{
	AvlTree T = MakeEmpty(T);
	int x;
	while (scanf("%d,",&x)!=EOF)
	{
		T = AvlInsert(x, T);
	}
	PrintAvlTree(T);
	printf("\n");
	T = MakeEmpty(T);
	return 0;
}
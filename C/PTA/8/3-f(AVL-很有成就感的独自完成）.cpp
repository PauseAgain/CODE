#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct avltree
{
	int key;
	int height;
	struct avltree *left;
	struct avltree *right;
} * AvlTree;

int max(int a, int b);
AvlTree MakeEmpty(AvlTree T);
int Height(AvlTree T);
AvlTree SingleRotateWithRight(AvlTree T);
AvlTree DoubleRotateWithRight(AvlTree T);
AvlTree SingleRotateWithLeft(AvlTree T);
AvlTree DoubleRotateWithLeft(AvlTree T);
AvlTree Insert(int element, AvlTree T);
void PrintAvlTree(AvlTree T);

int max(int a, int b)
{
	if (a >= b)
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
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}
int Height(AvlTree T) //求树的高度;
{
	if (T == NULL)
		return 1;
	else
		return (1 + max(Height(T->left), Height(T->right)));
}

//!_______________________________________________
AvlTree SingleRotateWithLeft(AvlTree K2)
{
	AvlTree K1;
	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;
	K2->height = max(Height(K2->left), Height(K2->right)) + 1;
	K1->height = max(Height(K1->left), K2->height) + 1;
	return K1;
	
}
//!_______________________________________________
AvlTree SingleRotateWithRight(AvlTree K2)
{
	//同理，不难写出
	AvlTree K1;
	K1 = K2->right;
	K2->right = K1->left;
	K1->left = K2;
	K2->height = max(Height(K2->left), Height(K2->right));
	K1->height = max(Height(K1->left), K2->height) + 1;
	return K1;
}
//!_______________________________________________
AvlTree DoubleRotateWithLeft(AvlTree K3) //背会得了
{
	K3->left = SingleRotateWithRight(K3->left);
	return SingleRotateWithLeft(K3);//!return也是single

	// K3->//?left
	////= SingleRotateWith
	//! Right//
	//?(K3->left);
	//// return SingleRotateWith
	//! Left(K3);
	
}
//!_______________________________________________
AvlTree DoubleRotateWithRight(AvlTree K3)
{
	//同理
	K3->right = SingleRotateWithLeft(K3->right);
	return SingleRotateWithRight(K3);
	
}
//!_______________________________________________

AvlTree Insert(int element, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(struct avltree));
		T->key = element;
		T->left = NULL;
		T->right = NULL;
		//!  :T->height = 0;
		T->height = 0;
	}
	else if (element < T->key)
	{
		T->left = Insert(element, T->left);
//!不同点----------------------------👇
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (element < T->left->key)
			{
				T = SingleRotateWithLeft(T);
			}
			else
			{
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if (element > T->key)
	{
		T->right = Insert(element, T->right);
//!不同点----------------------------👇
		if (Height(T->right) - Height(T->left) == 2)
		{
			if (element > T->right->key)
			{
				T = SingleRotateWithRight(T);
			}
			else
			{
				T = DoubleRotateWithRight(T);
			}
		}
	}
	//! :T->height = max(Height(T->left), Height(T->right)) + 1;
	T->height = max(Height(T->left), Height(T->right)) + 1;

	return T;
}

void PrintAvlTree(AvlTree T)
{
	if (T == NULL)
	{
		printf("ERROR PRINT!");
	}
	else
	{
		printf("%d,", T->key);
	}

	if (T->left)
	{
		PrintAvlTree(T->left);
	}
	if (T->right)
	{
		PrintAvlTree(T->right);
	}
}

int main()
{
	AvlTree T = MakeEmpty(T);
	int input;

	while (scanf("%d,", &input) != EOF)
	{
		T = Insert(input, T);
		//printf("Input=%d\n", input);
	}
	PrintAvlTree(T);
	printf("\n");
	T=MakeEmpty(T);
	return 0;
}
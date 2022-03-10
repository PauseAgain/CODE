#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct TreeNode
{
	ElementType element;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode, *BinaryTree;

BinaryTree MakeEmpty(BinaryTree T)
{
	
	if (T!=NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}
BinaryTree Insert(ElementType X, BinaryTree T)
{
	if (T == NULL)
	{
		T = (BinaryTree)malloc(sizeof(struct TreeNode));
		
		T->left = NULL;
		T->right = NULL;
		T->element = X;
	}
	else
	{
		if (X < T->element)
		{
			T->left = Insert(X, T->left);
		}
		else if (X > T->element)
		{
			T->right = Insert(X, T->right);
		}
	}
	return T;
}

void TraversePrint(BinaryTree T)
{
	if (T)
	{
		printf("%d,", T->element);

		if (T->left)
		{
			TraversePrint(T->left);
		}
		if (T->right)
		{
			TraversePrint(T->right);
		}
	}
}

int main()
{
	int x;
	BinaryTree T = MakeEmpty(T);

	while (scanf("%d,", &x) != EOF)
	{
		////printf("x=%d", x);
		T = Insert(x, T);
	}
	TraversePrint(T);
	printf("\n");
	T = MakeEmpty(T);
	return 0;
}
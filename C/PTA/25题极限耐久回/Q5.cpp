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
	T = (BinaryTree)malloc(sizeof(TreeNode));
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}

	return NULL;
}
int Depth(BinaryTree T)
{
    int m, n;
    if (T == NULL)
        return 0; //如果是空树，深度为0，递归结束
    else
    {
        m = Depth(T->left); //递归计算左子树的深度记为m
        n = Depth(T->right); //递归计算右子树的深度记为n
        if (m > n)
            return (m + 1); //二叉树的深度为m 与n的较大者加1
        else
            return (n + 1);
    }
}
BinaryTree Insert(ElementType X, BinaryTree T)
{
	if (T == NULL)
	{
		T = (BinaryTree)malloc(sizeof(TreeNode));
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

int PrintBinaryTree(int deepth, BinaryTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else if (deepth == 0)
	{
		printf("%d,", T->element);
		return 1;
	}
	else
	{
		int a = PrintBinaryTree(deepth - 1, T->left);
		int b = PrintBinaryTree(deepth - 1, T->right);
		if (a == 0 && b == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int index = 0;
	int tmp;
	int Array[n];
	while ((scanf("%d,", &tmp)) != EOF)
	{
		Array[index++] = tmp;
	}
	////printf("tmp=%d\n", tmp);//!这傻逼tmp把deep要scanf的吃掉
	int deep = tmp;

	// for (int i = 0; i < n;i++)
	// {
	// 	printf("%d,", Array[i]);
	// }
	
	BinaryTree T;
	T = (BinaryTree)malloc(sizeof(TreeNode));
	T->left = NULL;
	T->right = NULL;

	for (int i = 0; i < n; i++)
	{
		T = Insert(Array[i], T);
	}
	if(Depth(T)>=deep)
		PrintBinaryTree(deep, T);
	else
		printf("-1");
	printf("\n");
	return 0;
}

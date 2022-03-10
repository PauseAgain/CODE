#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef int ElementType;

struct TreeNode;

typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Position;

struct TreeNode
{
	ElementType element;
	SearchTree left;
	SearchTree right;
};

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}

	if (X < T->element)
	{
		return Find(X, T->left);
	}
	else if (X > T->element)
	{
		return Find(X, T->right);
	}
	else
	{
		return T;
	}
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->right);
	}
}

Position FindMin(SearchTree T) //两种递归/非递归find最值
{
	if (T != NULL)
	{
		while ((T->left != NULL))
		{
			T = T->left;
		}
	}
	return T;
}

SearchTree Insert(Element X, SearchTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		T->element = X;
		T->left = NULL;
		T->right = NULL;
	}
	else if (X < T->element)
	{
		//! T = Insert(X, T->left);//错了，应该是T->left
		T->left = Insert(X, T->left);
	}
	else if (X > T->element)
	{
		//! T = Insert(X, T->right);//错了，应该是T->right
		T->right = Insert(X, T->right);
	}

	return T;
}

SearchTree Delete(Element X, SearchTree T)
{
	Position tempcell;
	if (T == NULL)
	{
		printf("Not found!");
	}
	else if (X < T->element)
	{
		T->left = Delete(X, T->left);
	}
	else if (X > T->element)
	{
		T->right = Delete(X, T->right);
	}
	else if (T->right && T->left) //（双子节点删除）
	{
		tempcell = FindMin(T->right); //把该节点右子树最小值节点找出来和该带删除节点数据替换
		T->element = tempcell->element;
		T->right = Delete(T->element, T->right); //递归
	}
	else //(单子节点删除或叶子节点删除)
	{
		tempcell = T;
		if (T->left == NULL)
		{
			T = T->right;
		}
		else if (T->right == NULL)
		{
			T = T->left;
		}
		free(tempcell)
	}

	return T;
}
//?                     二叉树的遍历

//!                                                   层序(递归实现)遍历

//! AVL


int Height(AvlTree T)//比较height函数
{
	if(T==NULL)
	{
		return 1;
	}
	else{
		return (1 + Max(Height(T->Left), Height(T->Right)));
	}
}
AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{ /* Create and return a one-node tree */
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
			FatalError("Out of space!!!");
		else
		{
			T->Element = X;
			T -›Height = 0;
			T -›Left = T -›Right = NULL;
		}
	} /* End creating a one-node tree */
	else if (X < T->Element)
	{ /* handle left insertion */
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) /* not balanced */
			if (X < T->Left->Element)				 /* LL Rotation */
				T = SingleRotateWithLeft(T);
			else							 /* LR Rotation */
				T = DoubleRotateWithLeft(T); /* End left */
	}
	else if (X > T->Element)
	{ /* handle right insertion */
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2) /* not balanced */
			if (X > T->Right->Element)				 /* RR Rotation */
				T = SingleRotateWithRight(T);
			else /* RL Rotation */
				T = DoubleRotateWithRight(T);
	} /* End right */
	/* Else X is in the tree already; we'll do nothing */
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

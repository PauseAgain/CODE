#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
} * Tree, *TreeNode;

Tree MakeEmpty(TreeNode T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

TreeNode Insert(int element, TreeNode T)
{
	if (T == NULL)
	{
		T = (TreeNode)malloc(sizeof(struct tree));
		T->left = NULL;
		T->right = NULL;
		T->key = element;
	}
	else
	{
		if (element < T->key)
			T->left = Insert(element, T->left);
		else if (element > T->key)
			T->right = Insert(element,T->right);
	}

	return T;
}

void PrintNodeKey(TreeNode T)
{
	if (T != NULL)
	{
		printf("%d,", T->key);
	}
	else
	{
		printf("Print error!");
	}
}

void PreorderTraversal(TreeNode T)
{
	if(T)
	{
		PrintNodeKey(T);
		
		if(T->left)
		{
			PreorderTraversal(T->left);
		}

	//!错误之处为此处不应该用else if，只用if就行
	//!	else if(T->right!=NULL)X
	//? if(T->right!=NULL)√

		if(T->right)
		{
			PreorderTraversal(T->right);
		}
	}
}

int main()
{
	Tree T = MakeEmpty(T);

	int input;
	//!学一学如何高效过滤‘，’在没有count的情况下
    while(scanf("%d,",&input)!=EOF)
    {
		//printf("input=%d\n", input);
		T = Insert(input, T);
	}

	PreorderTraversal(T);
	
	printf("\n");
	    T=MakeEmpty(T);
	return 0;
}

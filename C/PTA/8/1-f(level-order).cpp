#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
} * TreeNode, *Tree;

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
		//!居然忘了这一句:T->key = element;
		T->key = element;
		//!我真的是傻逼
	}
	else
	{
		if (element < T->key)
		{
			T->left = Insert(element, T->left);
		}
		else if (element > T->key)
		{
			T->right = Insert(element, T->right);
		}
	}

	return T;
}

int PrintTree(int deepth, TreeNode T)
{
	if (T == NULL)
	{
		return 0;
	}
	else if (deepth == 0)

	{
		printf("%d,", T->key);
		return 1;
	}
	else
	{
		int a = PrintTree(deepth - 1, T->left);
		int b = PrintTree(deepth - 1, T->right);
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
	Tree T = MakeEmpty(T);
	int number;
	scanf("%d", &number);
int x;
//!问题源自这一段的输入！
/*!
	for (int i = 0; i < number; i++)
	{
		
		scanf("%d", &x);

		//?? scanf("%d", &x);差了一个','千差万别！

		//!! scanf("%d,", &x);


		printf("x=%d\n",x);
		T = Insert(x, T);
		printf("T->kry=%d\n",T->key);
	}*/
	//!!!!!!!!!\

	////????????
   for(int i=0;i<number;i++)
    {
        scanf("%d,",&x);
        //printf("x=%d\n",x);
        T=Insert(x,T);
        //printf("T->Data=%d\n",T->Data);
    }
///////????????

	int deepth;
	scanf("%d", &deepth);

	if (PrintTree(deepth - 1, T) == 0)
	{
		printf("-1");
	}

	T = MakeEmpty(T);
	printf("\n");

	return 0;
}
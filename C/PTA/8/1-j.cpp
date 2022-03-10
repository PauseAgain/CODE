#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
 int Data;
 struct tree *LeftChild;
 struct tree *RightChild;
} * TreeNode, *Tree;

TreeNode Insert(Tree root, int element)
{
 if (root == NULL)
 {
  root = (TreeNode)malloc(sizeof(struct tree));
  root->LeftChild = NULL;
  root->RightChild = NULL;
  root->Data = element;
        //printf("root->Data=%d\n",root->Data);
 }
 else
 {
  if (element > root->Data)
  {
   root->RightChild = Insert(root->RightChild, element);
  }
  else if (element < root->Data)
            {
   root->LeftChild = Insert(root->LeftChild, element);
  }
 }
 return root;
}

Tree MakeEmpty(Tree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->LeftChild);
        MakeEmpty(T->RightChild);
        free(T);
    }
    return NULL;
}

int PrintDepthTree(Tree T,int Depth)
{
    if(T==NULL)
        return 0;
    else if(Depth==0)
    {
        printf("%d,",T->Data);
        return 1;
    }
    else{
        int a=PrintDepthTree(T->LeftChild,Depth-1);
        int b=PrintDepthTree(T->RightChild,Depth-1);
        if(a==0&&b==0)
            return 0;
        else 
            return 1;
    }
}

int main()
{
    Tree T=MakeEmpty(T);
    int num,x;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d,",&x);
        //printf("x=%d\n",x);
        T=Insert(T,x);
        //printf("T->Data=%d\n",T->Data);
    }
    int Depth;
    scanf("%d",&Depth);
    if(PrintDepthTree(T,Depth-1)==0)
        printf("-1");
    T=MakeEmpty(T);
    printf("\n");
    return 0;
}
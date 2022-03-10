#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node *position;
typedef struct Node *tree;
struct Node
{
    int x;
    position left, next;
};
typedef struct collection
{
    int size;
    tree array[200];
}*queue;
queue merge(queue h1, queue h2);
tree combine(tree t1, tree t2);
void printTree(tree T, int k);
queue merge(queue h1, queue h2)//合并两个二项队列 
{
    tree t1, t2, carry = NULL;
    int i, j;
    h1->size = h1->size + h2->size;
    for (i = 0, j = 1; j <= h1->size; j = j * 2, i++)
    {
        t1 = h1->array[i];
        t2 = h2->array[i];
        int judge = !!t1 + 2 * !!t2 + 4 * !!carry;
        if (judge == 2)
        {
            h1->array[i] = t2;
            h2->array[i] = NULL;
        }
        else if (judge == 4)
        {
            h1->array[i] = carry;
            carry = NULL;
        }
        else if (judge == 3)
        {
            carry = combine(t1, t2);
            h1->array[i] = h2->array[i] = NULL;
        }
        else if (judge == 5)
        {
            carry = combine(t1, carry);
            h1->array[i] = NULL;
        }
        else if (judge == 6)
        {
            carry = combine(t2, carry);
            h2->array[i] = NULL;
        }
        else if (judge == 7)
        {
            h1->array[i] = carry;
            carry = combine(t1, t2);
            h2->array[i] = NULL;
        }
    }
    return h1;
}
void printTree(tree T, int k)//level order输出 
{
    int num = pow(2, k);
    position p = T;
    if (T == NULL) printf("0,");
    else
    {
        for (int i = 1; i <= num; i++)
        {
            printf("%d,", p->x);
            if (p->next == NULL) p = p->left;
            else p = p->next; 
        }
    }
}
tree combine(tree t1, tree t2)
{
    if (t2->x < t1->x) return combine(t2, t1);
    position p = t1->left;
    if (p == NULL) t1->left = t2;
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t2;
    }
    return t1;
}

int main()
{
    char y;
    int x = 0;
    queue H0, H; //用来存储新元素的一个二项队列，且永远只有一个元素
    H0 = (struct collection*)malloc(sizeof(struct collection));
    H0->size = 1;
    H = (struct collection*)malloc(sizeof(struct collection));
    H->size = 0;
    do
    {
        y = getchar();
        if (y != ',')
        {
            x = x * 10 + y - '0';
        }
        else
        {
            tree T =(struct Node*) malloc(sizeof(struct Node));
            T->left = T->next = NULL;
            T->x = x;
            H0->array[0] = T;
            H = merge(H, H0);
            H0->array[0] = NULL;
            x = 0;
        }
    } while (y != '\n');
    int k;
    scanf("%d", &k);
    printTree(H->array[k], k);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node{
	int x;
	struct Node *Leftchild;
	struct Node *Sibling;
} * Position, *Tree;
typedef struct Collection{
	int size;
	Tree Array[200];
} * BinomialQueue;
Tree CombineBinomialTree(Tree T1,Tree T2)
{
	if(T1->x>T2->x)
	{
		return CombineBinomialTree(T2, T1);
	}
	T2->Sibling = T1->Leftchild;
	T1->Leftchild = T2;
	return T1;
}
BinomialQueue Initialize(void)
{
	BinomialQueue H;
	H = (BinomialQueue)malloc(sizeof(Collection));
	H->Array = (Tree)(malloc(200 * sizeof(Node)));
	return H;
}
BinomialQueue merge(BinomialQueue H1,BinomialQueue H2)
{
	Tree T1, T2, Carry = NULL;
	int i, j;
	H1->size = H1->size + H2->size;
	for (i = 0; j = 1; j < H1->size;i+,j*=2)
	{
		T1 = H1->Array[i];
		T2 = H2->Array[i];
		switch(!!T1+2*!!T2+4*!!Carry)
		{
			case 0:
			case 1:
				break;
			case 2:
				H1->Array[i] = T2;
				H2->Array[i] = NULL;
				break;
			case 4:
				H1->Array[i] = Carry;
				Carry = NULL;
			case 3:
				Carry = CombineBinomialTree(T1, T2);
				H1->Array[i] = H2->Array[i] = NULL;
				break;
			case 5:
				Carry = CombineBinomialTree(T1, Carry);
				H1->Array[i] = NULL;
			case 6:
				Carry = CombineBinomialTree(T2, Carry);
				H2->Array[i] = NULL;
			case 7:
				H1->Array[i] = Carry;
				Carry = CombineBinomialTree(T1, T2);
				H2->Array[i] = NULL;
				break;
			}
	}
	return H1;
}
void PrintTree(Tree T,int k)
{
	int num = pow(2, k);
	Tree p = T;
	if(T==NULL){
		printf("0,");
	}
	else{
		for (int i = 1; i <= num;i++)
		{
			printf("%d,", p->x);
			if(p->Sibling==NULL)
			{
				p = p->Leftchild;

			}
			else {
				p = p->Sibling;
			}
		}
	}
}
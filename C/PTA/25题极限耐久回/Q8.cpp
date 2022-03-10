#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxlen 100
typedef char ElementType;
typedef struct HoffmanNode
{
	double weight;
	ElementType element;
	struct HoffmanNode *left;
	struct HoffmanNode *right;
} HoffmanNode, *HoffmanTree;

void FindTwoMinNumber(HoffmanTree *Array, int n, int *P1, int *p2);
HoffmanTree CreatHoffmanTree(ElementType *str, double *w, int n);
int main()
{
	int number=8;//总共有8个
	ElementType str[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	double w[8] = {7, 19, 2, 6, 32, 3, 21, 10};
	ElementType X[Maxlen];
	int n; // n=len of X
	scanf("%s", X);
	n = strlen(X);

	HoffmanTree T, P;
	T = CreatHoffmanTree(str, w, number);
	P = T;

	for (int i = 0; i < n; i++)
	{
		if (X[i] - '0' == 0)
		{
			T = T->left;
		}
		if (X[i] - '0' == 1)
		{
			T = T->right;
		}

		if (T->element != '0')
		{
			printf("%c", T->element);
			T = P;
		}
	}
	printf("\n");
	return 0;
}

void FindTwoMinNumber(HoffmanTree *Array, int n, int *P1, int *P2)
{
	double fir = 65535;
	double sec = 65534;
	if (Array != NULL)
		for (int i = 0; i < n; i++)
		{
			if (Array[i] != NULL)
				if (Array[i]->weight < fir)
				{
					sec = fir;
					fir = Array[i]->weight;
					*P2 = *P1;
					*P1 = i;
				}
				else if (Array[i]->weight < sec)
				{
					sec = Array[i]->weight;
					*P2 = i;
				}
				else{}
		}
}

HoffmanTree CreatHoffmanTree(ElementType *str, double *w, int n)
{
	int P1 = 0;
	int P2 = 0;
	HoffmanTree NewNode = NULL;
	HoffmanTree Array[Maxlen];
	memset(Array, 0, sizeof(HoffmanNode) * n);

	for (int i = 0; i < n; i++)
	{
		NewNode = (HoffmanTree)malloc(sizeof(HoffmanNode));
		memset(NewNode, 0, sizeof(HoffmanNode));

		NewNode->element = str[i];
		NewNode->weight = w[i];
		NewNode->left = NewNode->right = NULL;
		Array[i] = NewNode;
	}

	for (int i = 0; i < n - 1; i++)
	{
		FindTwoMinNumber(Array, n, &P1, &P2);

		NewNode = (HoffmanTree)malloc(sizeof(HoffmanNode));
		memset(NewNode, 0, sizeof(HoffmanNode));

		NewNode->weight = Array[P1]->weight + Array[P2]->weight;
		NewNode->element = '0';

		NewNode->left = Array[P1];
		NewNode->right = Array[P2];

		Array[P1] = NULL;
		Array[P2] = NewNode;
	}

	return NewNode;
}
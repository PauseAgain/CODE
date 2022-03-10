#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char DataType;

typedef struct HuffmanNode{
	struct HuffmanNode *left;
	struct HuffmanNode *right;
	int weight;
	DataType data;

}HuffmanNode, * HuffmanTree;

int FindTwoSmallestData(HuffmanTree *array,int n, int *p1,int *p2);
HuffmanTree CreatHuffmanTree(int *a, char *b, int n);

int FindTwoSmallestData(HuffmanTree *array,int n, int *p1,int *p2)
{
	int f = 10086, s = 10086;

	if(array==NULL)
		return 1;
	for (int index = 0; index < n;index++)
	{
		if(array[index]!=NULL)
		{
			if(array[index]->weight<f)
			{
				s = f;
				f = array[index]->weight;
				*p2 = *p1;
				*p1 = index;
			}//前后两条件互斥就不用赘述index>f了
			else if (array[index]->weight<s)
			{
				s = array[index]->weight;
				*p2 = index;
			}
		}
	}
	return 0;
}

HuffmanTree CreatHuffmanTree(int *w,DataType *d,int n)
{
	int f = 0;
	int s = 0;
	int index = 0;
	HuffmanTree NewNode = NULL;

	HuffmanTree array[100];
	memset(array, 0, sizeof(HuffmanNode));//前后sizeof的都是node

	for (index = 0; index < n;index++)
	{
		NewNode =(HuffmanTree) malloc(sizeof(HuffmanNode));
		memset(NewNode, 0, sizeof(HuffmanNode));

		NewNode->weight = w[index];
		NewNode->data = d[index];

		NewNode->left = NULL;
		NewNode->right = NULL;

		array[index] = NewNode;
	}

	for (index = 0; index < n - 1;index++)
	{
		//先寻找f,s
		FindTwoSmallestData(array, n, &f, &s);

		NewNode = (HuffmanTree)malloc(sizeof(HuffmanNode));
		memset(NewNode, 0, sizeof(HuffmanNode));

		NewNode->weight = array[f]->weight + array[s]->weight;
		NewNode->data = '0';

		NewNode->left = array[f];
		NewNode->right = array[s];

		array[f] = NULL;
		array[s] = NewNode;
	}

	return NewNode;

}

int main()
{
	//或者scanf &n   n=8
	int n = 8;
	int len;
	int w[8]={7,19,2,6,32,3,21,10};
	DataType d[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	char str[100];

	scanf("%s", str);
	len = strlen(str);

	HuffmanTree T, P;
	T = CreatHuffmanTree(w, d, n);

	P = T;

	for (int i= 0; i < n;i++)
	{
		if(str[i]-'0'==0)
		{
			T = T->left;
		}
		if(str[i]-'0'==1)
		{
			T = T->right;
		}

		if(T->data!='0')
		{
			printf("%c", T->data);
			T = P;
		}
	}

	return 0;
}
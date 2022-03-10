#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MinData -100086
typedef int ElementType;

typedef struct
{
	int size;
	int Capacity;
	ElementType *element;
} HeapStruct, *PriorityQueue;

PriorityQueue PQInitialize(int MaxElement)
{
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(HeapStruct));
	H->element = (ElementType *)malloc((MaxElement + 1) * (sizeof(ElementType)));

	H->Capacity = MaxElement;
	H->size = 0;
	H->element[0] = MinData;

	return H;
}

PriorityQueue Sort(PriorityQueue T)
{
	for (int j = 0; j <T->size; j++)
	{
		int i;
		for (i = T->size; i  != 1; i--)
		{
			if (T->element[i] < T->element[i / 2])
			{
				int temp;
				temp = T->element[i];
				T->element[i] = T->element[i / 2];
				T->element[i / 2] = temp;
			}
		}
	}
	return T;
}

void PQInsert(ElementType X, PriorityQueue H)
{
	int i;
	for (i = ++H->size; H->element[i / 2] > X; i /= 2) //!此处为++H->size
	{
		H->element[i] = H->element[i / 2];
	}
	H->element[i] = X;
}

int main()
{
	int n;
	scanf("%d", &n);
	int number[n];
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d,", &number[i]);
	}
	scanf("%d", &number[n - 1]);
	////!检测是否录入number成功
	// printf("\n收录的number数组为：");
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("%d", number[i]);
	// }
	// printf("\n");
	////!第一种方法
	PriorityQueue H = PQInitialize(n);

	for (int i = 0; i < n; i++)
	{
		PQInsert(number[i], H);
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (i != n)
		{
			printf("%d,", H->element[i]);
		}
		else if (i == n)
		{
			printf("%d", H->element[i]);
		}
	}
	printf("\n");
	////!第二种方法！
	PriorityQueue T = PQInitialize(n);

	T->size = n;

	for (int i = 0; i < n; i++)
	{
		T->element[i + 1] = number[i];
	}

	T = Sort(T);

	for (int i = 1; i < n + 1; i++)
	{
		if (i != n)
		{
			printf("%d,", T->element[i]);
		}
		else if (i == n)
		{
			printf("%d", T->element[i]);
		}
	}
	printf("\n");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MinData -10086
typedef int ElementType;

typedef struct HeapStruct
{
	int HeapSize;
	int Capacity;
	ElementType *element;
} HeapStruct, *PriorityQueue;
PriorityQueue PQInitialize(int MaxElement)
{
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(HeapStruct));
	H->element = (ElementType *)malloc((MaxElement + 1) * sizeof(ElementType));

	H->Capacity = MaxElement;
	H->HeapSize = 0;
	H->element[0] = MinData;
	return H;
}
void PQInsert(ElementType X, PriorityQueue H)
{
	int i;
	for (i = ++H->HeapSize; H->element[i / 2] > X; i /= 2)
	{
		H->element[i] = H->element[i / 2];
	}
	H->element[i] = X;

}
PriorityQueue Sort(PriorityQueue T)
{
	for (int j = 0; j < T->HeapSize; j++)
	{
		int i;
		for (i = T->HeapSize; i != 1; i--)
		{
			if (T->element[i] < T->element[i / 2])
			{
				int Temp;
				Temp = T->element[i];
				T->element[i] = T->element[i / 2];
				T->element[i / 2] = Temp;
			}
		}
	}
	return T;
}

int main()
{
	int n;
	scanf("%d", &n);
	int number[n];
	for (int i = 0; i < n - 1;i++)
	{
		scanf("%d,", &number[i]);
	}
	scanf("%d", &number[n - 1]);
	PriorityQueue H = PQInitialize(n);
	for (int i = 0; i < n;i++)
	{
		PQInsert(number[i], H);
	}
	for (int i = 1; i < n+1;i++)
	{
		if(i<n)
		{
			printf("%d,", H->element[i]);
		}
		else{
			printf("%d", H->element[i]);
		}
	}
	printf("\n");

	PriorityQueue T = PQInitialize(n);
	T->HeapSize = n;

	for (int i = 0; i < n;i++)
	{
		T->element[i+1] = number[i];
	}
	T = Sort(T);
	for (int i = 1; i < n+1;i++)
	{
		if(i<n)
		{
			printf("%d,", T->element[i]);
		}
		else{
			printf("%d", T->element[i]);
		}
	}
	printf("\n");
	return 0;
}
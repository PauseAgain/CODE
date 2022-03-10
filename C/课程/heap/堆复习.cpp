#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElementType;
#define MinData -10086;
typedef struct PQNode{
	int Capacity;
	int size;
	ElementType *elements;
} PQNode, *PriorityQueue;

PriorityQueue PQInitialize(int MaxElements)
{
	ElementType *H;
	H = (PriorityQueue)malloc(sizeof(PQNode));
	H->elements = (ElementType *)malloc((MaxElements + 1) * sizeof(ElementType));
	H->size = 0;
	H->Capacity = MaxElements;
	H->elements[0] = MinData;

	return H;
}

PriorityQueue PQInsert(ElementType X,PriorityQueue H)
{
	int i;
	for (i = ++H->size; H->elements[i / 2] > X;i/2)
	{
		H->elements[i] = H->elements[i / 2];
	}
	H->elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
	int i, child;
	ElementType LastElement, MinElement;

	MinElement = H->elements[1];
	LastElement = H->elements[H->size--];

	for (i = 1; i * 2 < H->size;i=child)
	{
		child = i * 2;
		
		if(child!=H->size &&H->elements[child]>H->elements[child+1])
		{
			child++;
		}
		if(H->elements[child]<LastElement)
		{
			H->elements[i] = H->elements[child];
		}
		else{
			break;
		}
	}
	H->elements[i] = LastElement;

	return MinElement;
}
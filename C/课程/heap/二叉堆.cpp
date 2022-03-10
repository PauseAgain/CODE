#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MinPQsize 1
#define MinData -10086

typedef int ElementType;

struct HeapStruct;
typedef HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Distory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

typedef struct HeapStruct
{
     int Capacity;
     int size;
     ElementType *elements;
} HeapStruct, *PriorityQueue;

PriorityQueue Initialize(int MaxElements)
{
     PriorityQueue H;
     if (MaxElements < MinPQsize)
          printf("Priority queue size is too small");

     H =(HeapStruct *) malloc(sizeof(HeapStruct));
     if (H == NULL)
     {
          printf("Out of space");
     }

     H->elements =(ElementType *) malloc((MaxElements + 1) * (sizeof(ElementType)));
     if (H->elements == NULL)
     {
          printf("Out of space");
     }

     H->Capacity = MaxElements;
     H->size = 0;
     H->elements[0] = MinData;

     return H;
}

void Insert(ElementType X, PriorityQueue H)
{
     int i;

     if (IsFull(H))
     {
          printf("error!The Priority queue is FUll!");
          return;
     }
     //!_________________________________________________________
     for (i = ++H->size; H->elements[i / 2] > X; i /= 2)
     {
          H->elements[i] = H->elements[i / 2];
     }
     H->elements[i] = X;
     //!_________________________________________________________
}

ElementType DeleteMin(PriorityQueue H)
{
     int i, child;
     ElementType MinElement, LastElement;

     if (IsEmpty(H))
     {
          printf("Error! Priority Queue is Empty!");
          return H->elements[0];
     }

     MinElement = H->elements[1];//!从1，而非存放MinData的0开始
     LastElement = H->elements[H->size--];

     for (i = 1/*从1开始*/; i * 2 <= H->size; i = child)
     {
          child = i * 2;
          //!先判断子节点有没有右子树，如果有 && 右子树更小，child++（变成指向右子节点）
          if (child != H->size && H->elements[child + 1] < H->elements[child])
          {
               child++;
          }
          //!如果要插入的最后一个元素比空槽的子节点要大，就把空槽的子节点放进空槽里
          //!自然的，空槽的原子节点形成了新的空槽，以此循环直到不满足条件
          if(LastElement>H->elements[child])
          {
               H->elements[i] = H->elements[child];
          }
          else
          {
               break;
          }
     }
     //!不满足条件时直接将最后节点放入空槽
     H->elements[i] = LastElement;
     //!返回最小值原来的element【1】就可
     return MinElement;
}
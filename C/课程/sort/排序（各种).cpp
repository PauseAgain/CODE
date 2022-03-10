#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define cutoff 10 ////用于管理快速排序切换InsertionSort的数组大小
typedef int ElementType;

//**插入排序**//InsertionSort

void InsertionSort(ElementType *A, int n)
{
	int j, p;
	ElementType temp;
	for (p = 1; p < n; p++)
	{
		temp = A[p];
		for (j = p; j > 0 && A[j - 1] > temp /* 不是A[j]*/; j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;
	} //没有return值
}

//**希尔排序**//ShellSort

void ShellSort(ElementType *A, int n)
{
	int i, j, increment;
	ElementType temp;

	//!只有最外层的👇循环是特殊的新增的

	for (increment = n / 2; increment > 0; increment /= 2)
	//?👆👆👆👆👆👆👆👆

	{									/* h sequence */
										//!以下就是Insertion Sort
		for (i = increment; i < n; i++) //? increment 代替了 p=1中 1 的位置
		{
			temp = A[i];								//!忘了这一句
			for (j = i; j >= increment; j -= increment) //! p-=1->p--,但是类比是| j-=increment |而 不是j--！！！
			//! j>=increment 也可以改写成 j>increment-1
			{
				if (temp < A[j - increment])
				{
					A[j] = A[j - increment];
				}
				else
				{
					break;
				}
				A[j] = temp;
			}
			//!位置错了，在上面A[j] = temp;
		}
	}
}

//**归并排序**//MergeSortM

//! Merge(合并函数)
void Merge(ElementType *A, ElementType *TempArray /*临时数组*/, int LeftPos /*左开头*/, int RightPos /*右开头*/, int RightEnd /*右结尾*/)
{
	int i, LeftEnd, NumElements, TempPos;
	LeftEnd = RightPos - 1;				  //!左结尾是右结尾的左边一个数字
	TempPos = LeftPos;					  //! temp开头是左开头起始
	NumElements = RightEnd - LeftPos + 1; //?从左开头到右结尾的总节点数量(R-F+1)

	while (LeftPos <= LeftEnd && RightPos <= RightEnd) //! main loop
	{
		if (A[LeftPos] <= A[RightPos])
		{
			TempArray[TempPos++] = A[LeftPos++];
		}
		else
		{
			TempArray[TempPos++] = A[RightPos++];
		}
	}

	while (LeftPos <= LeftEnd)
	{
		TempArray[TempPos++] = A[LeftPos++];
	}

	while (RightPos <= RightEnd)
	{
		TempArray[TempPos++] = A[RightPos++];
	}

	for (i = 0; i < NumElements; i++, RightEnd--)
	{
		A[RightEnd] = TempArray[RightEnd];
	}
}
//! Msort(寻找中心-递归分治)
void Msort(ElementType *A, ElementType *TempArray, int left, int right)
{
	int center;		  //?正中央，属于左半边最后一个，右半边第一个是center+1
	if (left < right) /* If there are elements to be sorted*/
	{				  //!找到中心
		center = (left + right) / 2;
		//!递归Msort
		Msort(A, TempArray, left, center);
		Msort(A, TempArray, center + 1, right);
		//! Merge函数将left与right粘合起来！
		Merge(A, TempArray, left, center + 1, right);
	}
}
//! MergeSort
void MergeSort(ElementType *A, int n)
{
	//!在此处申请临时数组 ElementType *TempArray
	ElementType *TempArray;
	TempArray = (ElementType *)malloc(/*！！忘了！！*/ n * sizeof(ElementType)); //!前往勿忘 n* sizeof,毕竟是申请由n个int组成的数组

	Msort(A, TempArray, 0 /*left*/, n - 1 /*right*/);

	free(TempArray); //!使用完就残忍抛弃临时TempArray
}

//**快速排序**/QuickSort
void Swap(ElementType *a, ElementType *b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

ElementType Median3(ElementType *A, int left, int right) //!输入左右返回Center
{
	int center = (left + right) / 2; //先求中心值

	//!三个条件交换唯一目的是实现到底下的时候  左<中心<右
	if (A[left] > A[center])
	{
		Swap(&A[left], &A[center]);
	}
	if (A[left] > A[right])
	{
		Swap(&A[left], &A[right]);
	}
	if (A[center] > A[right])
	{
		Swap(&A[center], &A[right]);
	}
	//**到这里，已经左<中心<右

	//?因为没必要排序已经排序好的最左边，最右边两个数，返回也只返回center
	//!所以要做的就是以 需要比较的 最右侧一位 [right-1] 储存 center，所以swap一下:
	Swap(&A[center], &A[right - 1]);

	return A[right - 1]; //!返回center值
}
void QuickSort(ElementType *A, int left,int right)
{
	

	int i, j; //!
	//👇👇👇👇👇👇👇//!这个就是大名鼎鼎的「枢纽元」
	ElementType Pivot;
	//👆👆👆👆👆👆👆👆

	//!这个if/else有说法    如果左右相差太小，其实再递归的排序得不偿失，直接插入排序InsertionSort
	if (left+cutoff<=right) /*define cutoff 10 */
	{
		Pivot = Median3(A, left, right); //? Pivot = Center
		i = left;						 // i从左边第一个开始，//!为什么i！=left+1呢，是因为下面的++i一开始就先++，不需要剔除已经不用排序的最左数
		j = right - 1;					 // j从右边第一个，同理👆，也不用right-2，-1是因为第right=[right-1]

		for (;;) //!无条件循环直到Break
		{

			//!如果A[++i](P的左边)比Pivot小（符合要求），就继续进位向右
			while (A[++i] < Pivot)
			{
			}
			//!如果A[--j](P的右边)比Pivot大（符合要求），就继续进位向左
			while (A[--j] > Pivot)
			{
			}

			//在不满足上述继续的条件之后：
			if (i < j) //?如果恰好左右没碰到呢
			{
				Swap(&A[i], &A[j]) //!交换左右指针的值
			}
			else ////这意味着已经i=j，别说了，可以不用继续了....
			{
				break; //?跳出for循环
			}
			//!然后继续循环，看看能不能直接顺移动，不满足条件就交换左右节点值，然后继续循环，直到发生else
		}
		//?还是老套路，把Pivot 所储存的 center 放到 A[right - 1] 去
		Swap(&A[i], &A[right - 1]);

		//! ** imporant ** //
		//!进行递归！！！
		QuickSort(A, left, i - 1);	//! i就是Pivot了，所以左侧从left递归QuickSort排序到i-1
		QuickSort(A, i + 1, right); //! i就是Pivot了，所以右侧从i+1排序到right
	}
	//小于cutoff的时候用插入排序，可靠#define cutoff 值 调节
	else
	{
		InsertionSort(A + left, right - left + 1 /*new n*/);
	}
}
//**选择排序**//

void SelectionSort(ElementType *A, int len)
{
    int i,j;

        for (i = 0 ; i < len - 1 ; i++)
    {
                int min = i;
                for (j = i + 1; j < len; j++)     //走訪未排序的元素
                        if (A[j] < A[min])    //找到目前最小值
                                min = j;    //紀錄最小值
                Swap(&A[min], &A[i]);    //做交換
        }
}
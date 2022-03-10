/** LeftistHeap*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef int ElementType;
typedef struct LeftistHeapNode
{
	ElementType element;
	LeftistHeapNode *left;
	LeftistHeapNode *right;
	int Npl;
} LeftistHeapNode, *LeftistHeap;

int IsEmpty(LeftistHeap H);
void SwapLFChild(LeftistHeap H);
LeftistHeap Initialize(void);
ElementType FindMin(LeftistHeap H);
LeftistHeap Merge(LeftistHeap H1, LeftistHeap H2);
LeftistHeap LInsert(ElementType X, LeftistHeap H);
LeftistHeap LDeleteMin(LeftistHeap H);

int IsEmpty(LeftistHeap H)
{
	return H->left == NULL && H->right == NULL;
}

void SwapLFChild(LeftistHeap H)
{
	LeftistHeap temp;
	temp = H->left;
	H->left = H->right;
	H->right = temp;
}

LeftistHeap Initialize(void)
{
	LeftistHeap H;
	H = (LeftistHeap)malloc(sizeof(LeftistHeapNode));

	if (H == NULL)
		printf("ERROR!");

	H->right = NULL;
	H->left = NULL;
	H->element = 0;
	H->Npl = 0; //! Npl清零
}

ElementType FindMin(LeftistHeap H)
{
	if (!H)
		return H->element;
	else
		printf("H=NULL!");
	return 0;
}
//!合并左右堆的驱动例程：
/*important*/
LeftistHeap Merge(LeftistHeap H1, LeftistHeap H2) //! H1，H2不分大小
{
	if (H1 == NULL) //!如果有一个函数干脆不存在NULL，就只返回另一个函数
	{
		return H2;
	}
	if (H2 == NULL) //!同理
	{
		return H1;
	}

	if (H1->element < H2->element) //!比较两树root的大小，并且按照大小跳转到真正合并的函数Merge1（小，大）中去
	{
		return Merge1(H1, H2);
	}
	else if (H1->element > H2->element)
	{
		return Merge1(H2, H1);
	}
}
//!合并左右堆的实际例程：
LeftistHeap Merge1(LeftistHeap S /*根节点较小者*/, LeftistHeap L /*根节点较大者*/)
{
	if (S->left == NULL /*如果较小节点的左子树根部就不存在*/)
	{
		S->left = L; //!直接将L当作S的左子树
	}
	else
	{
		//! S->left S的左子树不动
		S->right = Merge(S->right, L);
		//!👆S 的右子树是 经过merge粘合的 原右子树和较大根L

		/*important*/
		//!如果S的左子树比右子树小，就是👇👇判断，就满足扭的条件
		if (S->Left->Npl < S->Right->Npl)

		{					/*important*/
			SwapLFChild(S); //!每次粘贴完之后都“左右扭一次”
		}

		/*important*/				//?更新零路径长度：
		S->Npl = S->right->Npl + 1; //!更新的 零路径长度是 原长度 右子树 +1
	}
	return S; //?返回根节点比较小的那个
}

LeftistHeap LInsert(ElementType X, LeftistHeap H)
{ //!创造新节点
	LeftistHeap NewNode;
	NewNode = Initialize();
	//!写入新节点
	NewNode->element = X;
	//!将新节点作为root进行粘合,并将新的左堆赋予原来的H地址
	H = Merge(NewNode, H);

	return H;
}

LeftistHeap LDeleteMin(LeftistHeap H)
{
	if (IsEmpty(H)) //!先判断非空
	{
		printf("Delete ERROR!");
	}
	//!申请临时左右子节点并且将H的左右子树赋值地址
	LeftistHeap LEFT, RIGHT;
	LEFT = H->left;
	RIGHT = H->right;
	//!解放H节点（直接删除附带的信息）
	free(H);
	//!返回两者缝合的新值覆盖原来的H
	return Merge(LEFT, RIGHT);
}
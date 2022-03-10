#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MaxTree 1000
#define Infinity 100086
typedef int ElementType;
typedef struct BinNode
{
	ElementType element;
	BinNode *LeftChild; //?左孩子指针
	BinNode *Sibling;	//!兄弟指针
} * BinaryTree, *Position;

typedef struct Collection
{
	int CurrentSize;
	BinaryTree TheTrees[MaxTree];
} * BinaryQueue;
//!合并T1，T2两棵树(BinaryTree类)
BinaryTree CombineBinaryTree(BinaryTree T1, BinaryTree T2)
{
	//!先判断T1，T2大小，不符合条件的（T2<T1)ruturn (T2,T1)
	if (T1->element > T2->element)
		return CombineBinaryTree(T2, T1);
	//?因为T2的element比T1大，所以T2在下面，T1还是Root
	//! T2的兄弟节点=T1的左子节点。T2成为T1的左子树（等于是放在T1下面，T1左子节点左边了)
	T2->Sibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1; //返回T1的值
}
BinaryQueue Initialize(void)
{
	BinaryQueue H;
	H = (BinaryQueue)malloc(sizeof(Collection));
	H->TheTrees = (BinaryTree *)malloc(MaxTree * sizeof(BinNode));
	return H;
}
//!合并H1，H2两个优先队列（二叉堆）(BinaryQueue类)
BinaryQueue Merge(BinaryQueue H1,BinaryQueue H2)
{
	int i, j;
	/**注意是BinaryTree**/
	BinaryTree T1, T2;
	BinaryTree Carry = NULL;
	//!先把两者size相加
	H1->CurrentSize = H1->CurrentSize + H2->CurrentSize;

	for (i = 0, j = 1; j < H1->CurrentSize /*循环直到j>=H1-size*/;i++,j*=2)//! i每次++.j每次翻倍
	{
		/*T1、T2分别负责储存每一轮循环中H1\H2 TheTrees[i]的值*/
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[i];

//!对于下面的switch判断条件，我只能好奇“李在干什么？？？”
		switch(!!T1 + 2 * !!T2 + 4 * !!Carry)//!别忘了carry=NULL始定义
        {//?反正是要返回H1的，所以就算是NULL也要把Merge好的让H1做指针
            case 0 : //!空树,H1&&H2=NULL
            case 1://!只有H1,H2=NULL
                break ; 
            case 2://!只有H2,H1=NULL
                H1->TheTree[i] = T2
                H2->TheTree[i] = NULL ;
                break ;
            case 4://! 我懂了!递归到只剩carry，因为之前递归的时候只保留Carry， //*其他的统统手动=NULL*//
                H1->TheTree[i] = Carry ;
                Carry = NULL ;//?只有case 4: Carry=NULL
            case 3: //!h1 and h2 1+2, ｜｜**都有就用Carry=CombinTrees（T1，T2）来递归，下面也是，break
                Carry = CombineTrees(T1,T2) ;//? 递归
                H1->TheTree[i] = H2->TheTree[i] = NULL ;
                break ;
            case 5: //!h1 and carry  5=4+1 这个是case 4:在有T1没T2的情况下又循环了一遍,不break，NULL除了Carry之外的，
                Carry = ConbineTrees(T1,Carry) ;//? 递归，进Case4了
                H1->TheTrees[i] = NULL ;
            case 6://!h2 and carry  6=4+2 这个是case 4:在有T2没T1的情况下又循环了一遍,不break，NULL除了Carry之外的
                Carry = ConbineTrees(T2,Carry) ;//? 递归，进Case4了
                H2->TheTrees[i] = NULL ;
            case 7: //!都有1+2+4=7,这下团建了，break
                H1->TheTree[i] = Carry ;
                Carry = CombineTrees(T1,T2) ;//? 递归，
                H2->TheTrees[i] = NULL ;
                break ;
                
        }
	}
	return H1;//**最后返回H1，已经Merge好了！s
}

ElementType DeleteMin(BinaryQueue H)
{
	int i, j;
	int MinTree;
	BinaryQueue DeletedQueue;
	Position DeletedTree, OldRoot;
	ElementType MinItem;

	MinItem = Infinity;//!先假设MinItem是极大的常数

	for (i = 0; i < MaxTree;i++)
	{
		if (H->TheTrees[i] /*Trees[i]存在*/ && H->TheTrees[i]->element<MinItem/*发现新的最小值*/)
		{
			/*Update Mininum*/ //!更新
			MinItem = H->TheTrees[i]->element;
			MinTree /* int */ = i;
		}
	}
	//!用DeletedTree保存H->TheTrees[MinTree]的地址
	DeletedTree = H->TheTrees[MinTree];
	//！用OldRoot保存DeletedTree地址
	OldRoot = DeletedTree;

	DeletedTree = DeletedTree->LeftChild;//!覆盖最小树指针=原最小的左子树指针
	free(OldRoot);//?将老的树指针free
//!已经不明所以无所谓了
	DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;

	for (j = MinTree - 1; j >= 0;j--)
	{	DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->Sibling;
		DeletedQueue->TheTrees[j]->Sibling = NULL;
	}

	H->TheTrees[MinTree] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;

	Merge(H, DeletedQueue);
	return MinItem;
	
}

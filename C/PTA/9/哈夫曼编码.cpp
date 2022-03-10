#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct HuffmanNode
{
	struct HuffmanNode *left,*right;//!左右子树
	int weight;//!权重
	char zimu;//!携带信息的Data
} HuffmanNode,*HuffmanTree;

int findSmallData(HuffmanTree *Array,int n,int* p1,int *p2)//虽然返回的值只表示0 find/1 unfind，但是本身的信息已经保存在地址p1,p2里了
//! HuffmanTree *Array 结构体指针数组
{
	int fir_small=65535,sec_small=65535; //!先设最小值和次小值

	if(Array==NULL) 
		return 1; ////出错就返回1

	for(int index=0;index<n;index++)//? index：i   p1:保存最小权重index的地址   p2:保存次小权重index的地址
	{
		if(Array[index]!=NULL)
		{
			if(Array[index]->weight<fir_small)
			//!假如 当前节点的权重 小于 最小权重fir_small
			{
				sec_small=fir_small;//将次小的值变为 前 最小权重fir_small
				fir_small=Array[index]->weight;//最小权重fir_small = 新的最小
				*p2=*p1; //?地址不变，地址对应的index值变化
				*p1=index;	//?同上
			}
			else if(Array[index]->weight<sec_small)
			{
				//!假如 当前节点的权重 小于 次小权重fir_small
				sec_small=Array[index]->weight;//
				*p2=index;//?地址不变，地址对应的index值变化
			}
		}
	}
	return 0;	
}

HuffmanTree CreateHuffmanTree(int *a,char *b,int n)//*b是 按照字母表排列 的 字母串，a是 字母串对应的 出现频率 ？，n是数据个数
{

	int fir_small=0,sec_small=0;//!创造树的时候先把老三样初始化为0
	int index=0;
	HuffmanTree NewNode=NULL;//?

	HuffmanTree Array[100];//!创造结构体指针数组

//?memset是计算机中C/C++语言初始化函数。作用是将 某一块内存中的内容 全部设置为 指定的值， 这个函数通常为 新申请的内存 做 初始化 工作。

	memset(Array/*头指针*/,0/*初始化为0*/,sizeof(HuffmanNode)*n/*新申请的内存*/);


	for(index=0;index<n;index++)
	{
		NewNode=malloc(sizeof(HuffmanNode));//!为指针NewNode申请空间
		memset(NewNode,0,sizeof(HuffmanNode));//!将NewNode指针的空间初始化

		NewNode->weight=a[index];//?为新节点->权重赋值
		NewNode->zimu=b[index];//?为新节点->字母赋值

		NewNode->left=NewNode->right=NULL;//!新节点左右子树=NULL

		Array[index]=NewNode;//?把节点指针放进结构体指针数组
	}


	for(index=0;index<n-1;index++)//?N个节点需要排序N-1次
	{
		//!之前已经利用过NewNode来创建包含权重和字母的节点了，现在重新利用NewNode之前要初始化一边
		findSmallData(Array,n,&fir_small/*输入的是f_s,s_s的指针*/,&sec_small);//寻找最小和次小
//!这个& 用的机油意思，自己琢磨一下
		NewNode=malloc(sizeof(HuffmanNode));//!为指针NewNode申请空间
		memset(NewNode,0,sizeof(HuffmanNode));//!将NewNode指针的空间初始化

		NewNode->weight=Array[fir_small]->weight+Array[sec_small]->weight;//?新节点的权重= 最小权重树 + 次小权重树之和
		NewNode->zimu='0';//?非叶子父节点不保存字母信息，初始化为'0'

		NewNode->left=Array[fir_small];//!新节点左子树是最小
		NewNode->right=Array[sec_small];//!右子树是次小

		Array[fir_small]=NULL;//最小指针空着
		Array[sec_small]=NewNode;//新节点指针变成了次小节点指针
	}


	return NewNode;
}
int main()
{
	int n=8,len;

    int a[8]={7,19,2,6,32,3,21,10};
    char b[8]={'a','b','c','d','e','f','g','h'};

    char str[100];
    scanf("%s",str);
    len=strlen(str);//!len记录了 读取str的对应大小

	HuffmanTree T,P;//创建两个树指针T、P

	T=CreateHuffmanTree(a,b,n);//!将T-tree组成霍夫曼树

	P=T; 

    for(int i=0;i<len;i++)
    {
		if(str[i]-'0'==0)//! str[i]==0,turn left
			T=T->left;
		if(str[i]-'0'==1)//! str[i]==1,turn right 
			T=T->right;

		if(T->zimu!='0')//*如果T不是不携带信息的父节点（意思是如果T是叶子节点）
    	{
    		printf("%c",T->zimu);//!打印T所携带的信息

    		T=P;
			//?如果打印了字母，就T=P让T指针回到Root，
			//?这样就可以重新开始， 
			//!同时str[i]该走几位已经走了几位了,i是会积累的
		}
	}
	return 0;
}

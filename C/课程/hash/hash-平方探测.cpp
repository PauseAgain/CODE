#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum status //!枚举，设定legimate 为0，empty为1

{
	legitimate, //满
	empty		//空
};

typedef struct Cell
{
	enum status Info; //*意思是info是一个0/1型变量
	char *Telnum;	  //字符串数组保存电话号码信息
} Cell;
//!这个包含一个 0/1status型 变量info、char* Telnum的结构体叫 Cell

typedef struct HashTableNode //构架hashtable
{
	int tablesize;	 //! Tablesize Hash表的节点数量
	Cell *Thiscells; //?包含一个cell型的指针

} HashTableNode, *HashTable; /**HashTable本身就是指针*/

int Hash(char *key, int num) //构建哈希算法—— //!int返回值
{							 //此处采用尾号来直接获得hash值
	return (key[10 /*尾号最后一位*/] - '0') % num;
}

HashTable Initial(int tablesize) //!构造Hash表 --HashTable指针返回值
{
	HashTable H; //申请并创造Hash表指针
	H = malloc(sizeof(HashTableNode));
	//!对hash表进行赋值tablesize和申请Thiscells cell类指针的空间
	H->tablesize = tablesize;
	//申请空间大小==//?   sizeof(HashTableNode) X Tablesize
	H->Thiscells = malloc(sizeof(Cell) * tablesize);
	//!下面一步是要完成对长申请的hash表的 ThisCell Cell类数组
	//!从ThisCell[0]到Thiscell[Tablesize-1]进行申请空间\初始化
	for (int i=0; i < tablesize; i++)
	{
		H->Thiscells[i].Telnum = malloc(sizeof(char) * 11 /*11位电话号码的字符串数组大小*/);
		H->Thiscells[i].Info = empty; //初始化
	}

	return H;
}

int Find(char *key /*key是携带电话的字符串数组*/, HashTable H)
{
	int cnum = 0;
	int i;
	i = Hash(key, H->tablesize);

	while (H->Thiscells[i].Info != empty /* ！=EMPTY说明这个桶已经有占用了必须另寻新的*/ && strcmp /*比较函数*/ (H->Thiscells[i].Telnum, key) != 0 /*不为0说明有差别,说明已经存在的字符串和将要放入的字符串不是一个*/)
	{
		i += 2 * (++cnum /*初始化的时候是0，先++从i开始算*/) - 1;
		if (i >= H->tablesize) //如果i的值超出了tablesize的限制
		{
			i -= H->tablesize; //!大不了从头再来
		}
	}
	return i; //!返回的是Hash表中找到相应桶的编号
}

void Insert(char *key, HashTable H) //向Hash筒中插入--//!平方探测
{
	int pos;
	pos = Find(key, H);
	//用pos（int）保存已经找到的桶的位置
	if (H->Thiscells[pos].Info != legitimate) //如果pos所对应的位置不是满的,就是空的
	{
		H->Thiscells[pos].Info = legitimate;   //!先改成已满
		strcpy(H->Thiscells[pos].Telnum, key); //!再吧信息复制进去
	}
}

int main()
{
	char str[200];
	HashTable H;
	H = Initial(10); //!创造大小为10的表

	while (scanf("%11s,", str) != EOF) //?这个scanf只能说牛皮
	{
		Insert(str, H);
	}
	
	for (int i = 0; i < H->tablesize; i++)
	{
		if (i == H->tablesize - 1) //!当是最后一个的时候
		{
			if (H->Thiscells[i].Info == empty) //?遇见空桶 p=‘0’
			{
				printf("0");
			}
			else
			{
				printf("%s", H->Thiscells[i].Telnum);
				//否则该是啥就是啥
			}
		}
		else
		{

			if (H->Thiscells[i].Info == empty)
			{
				printf("0,");//多了，
			}
			else
			{
				printf("%s,", H->Thiscells[i].Telnum);
			}
		}
	}
	return 0;
}
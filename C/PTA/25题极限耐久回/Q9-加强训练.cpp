// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef char ElementType;
// #define TelephonLen 11;

// // enum status
// // {
// // 	empty,
// // 	full
// // };
// // typedef struct Cell
// // {
// // 	enum status Info;
// // 	ElementType *Telstr;
// // } Cell;
// // typedef struct HashTableNode
// // {
// // 	Cell *ThisCell;
// // 	int tablesize;
// // } HashTableNode, *HashTable;

// // int Hush(ElementType *TelStr, int Tablesize)
// // {
// // 	return (TelStr[10] - '0') % Tablesize;
// // }
// // HashTable Initial(int Tablesize)
// // {
// // 	HashTable H = (HashTable)malloc(sizeof(HashTableNode));
// // 	H->tablesize = Tablesize;
// // 	H->ThisCell = (Cell *)malloc(sizeof(Cell)*Tablesize);
// // 	for (int i = 0; i < Tablesize; i++)
// // 	{
// // 		H->ThisCell[i].Info = empty;
// // 		H->ThisCell[i].Telstr = ((ElementType *)malloc(11 * sizeof(ElementType)));
// // 	}
// // 	return H;
// // }
// // int Find(ElementType*TelStr,HashTable H)
// // {
// // 	int cnum = 0;
// // 	int hushnum = Hush(TelStr, H->tablesize);
// // 	while(H->ThisCell[hushnum].Info!=empty && strcmp(H->ThisCell[hushnum].Telstr,TelStr)!=0)
// // 	{
// // 		hushnum += 2 * (++cnum) - 1;
// // 		if(hushnum>=H->tablesize)
// // 		{
// // 			hushnum -= H->tablesize;
// // 		}

// // 	}
// // 	return hushnum;
// // }
// // void Insert(ElementType *TelStr,HashTable H)
// // {
// // 	int hushnum = Find(TelStr, H);
// // 	if(H->ThisCell[hushnum].Info!=full)
// // 	{
// // 		H->ThisCell[hushnum].Info = full;
// // 		strcpy(H->ThisCell[hushnum].Telstr, TelStr);
// // 	}
// // }
// // int main()
// // {
// // 	char str[100];
// // 	HashTable H;
// // 	H= Initial(10);
// // 	while(scanf("%11s,",str)!=EOF)
// // 	{
// // 		Insert(str, H);
// // 	}
// // 	for (int i = 0; i < H->tablesize;i++)
// // 	{
// // 		if(i!=H->tablesize-1)
// // 		{
// // 			if(H->ThisCell[i].Info==empty)
// // 			{
// // 				printf("0,");
// // 			}
// // 			else
// // 			{
// // 				printf("%s,", H->ThisCell[i].Telstr);
// // 			}
// // 		}
// // 		else
// // 		{
// // 			if(H->ThisCell[i].Info==empty)
// // 			{
// // 				printf("0");
// // 			}
// // 			else
// // 			{
// // 				printf("%s", H->ThisCell[i].Telstr);
// // 			}
// // 		}

// // 	}
// // 	printf("\n");
// // 	return 0;
// // }

// enum status
// {
// 	empty,
// 	full
// };
// typedef struct Cell{
// 	ElementType *TelStr;
// 	enum status Info;
// } Cell;

// typedef struct HashTableNode{
// 	Cell *ThisCell;
// 	int TableSize;
// } HashTableNode, *HashTable;

// HashTable Initial(int tablesize)
// {
// 	HashTable H = (HashTable)malloc(sizeof(HashTableNode));
// 	H->TableSize = tablesize;
// 	H->ThisCell = (Cell *)malloc(sizeof(Cell) * tablesize);
// 	for (int i = 0; i < tablesize;i++)
// 	{
// 		H->ThisCell[i].Info = empty;
// 		H->ThisCell[i].TelStr=(ElementType *) malloc(sizeof(ElementType) * 11);
// 	}
// 	return H;
// }
// int Hash(ElementType *TelStr,int TableSize)
// {
// 	return (TelStr[10] - '0') % TableSize;
// }

// int Find(ElementType *TelStr,HashTable H)
// {
// 	int cnum = 0;
// 	int hushnum = Hash(TelStr, H->TableSize);
// 	while(H->ThisCell[hushnum].Info!=empty && strcmp(H->ThisCell[hushnum].TelStr,TelStr)!=0)
// 	{
// 		hushnum += 2 * (++cnum) - 1;
// 		if(hushnum>=H->TableSize)
// 		{
// 			hushnum -= H->TableSize;
// 		}
// 	}
// 	return hushnum;
// }
// void InsertTable(ElementType *TelStr,HashTable H)//!千万注意是void，否则直接段错误！！！
// {
// 	int hushnum = Find(TelStr, H);
// 	if(H->ThisCell[hushnum].Info!=full)
// 	{
// 		H->ThisCell[hushnum].Info = full;
// 		strcpy(H->ThisCell[hushnum].TelStr, TelStr);
// 	}

// }

// int main()
// {
// 	ElementType str[100];
// 	HashTable H;
// 	H = Initial(10);
// 	while(scanf("%11s,",str)!=EOF)
// 	{
// 		////printf("STR:%s\n", str); √
// 		InsertTable(str, H);
// 	}

// 	for (int i = 0; i < H->TableSize;i++)
// 	{
// 		if(i<H->TableSize-1)
// 		{
// 			if(H->ThisCell[i].Info==empty)
// 			{
// 				printf("0,");
// 			}
// 			else{
// 				printf("%s,", H->ThisCell[i].TelStr);
// 			}
// 		}
// 		else{
// 			if(H->ThisCell[i].Info==empty)
// 			{
// 				printf("0");

// 			}
// 			else{
// 				printf("%s", H->ThisCell[i].TelStr);
// 			}
// 		}
// 	}
// 	printf("\n");
// 	return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum status
{
	empty,
	full
};

typedef struct Cell
{
	char *TelStr;
	enum status Info;
} Cell;

typedef struct HashTableNode
{
	Cell *ThisCell;
	int TableSize;
} HashTableNode, *HashTable;

int Hash(char *TelStr, int num)
{
	return ((TelStr[10] - '0') % num);
}
HashTable Initial(int Tab)
{
	HashTable H = (HashTable)malloc(sizeof(HashTableNode));
	H->TableSize = Tab;
	H->ThisCell = (Cell *)malloc(sizeof(Cell) * Tab);
	for (int i = 0; i < Tab; i++)
	{
		H->ThisCell[i].Info = empty;
		H->ThisCell[i].TelStr = (char *)malloc(sizeof(char) * 11);
	}
	return H;
}
int Find(char *TelStr, HashTable H)
{
	int hushnum = Hash(TelStr, H->TableSize);
	int cnum = 0;
	while (H->ThisCell[hushnum].Info != empty && strcmp(H->ThisCell[hushnum].TelStr, TelStr) != 0)
	{
		hushnum += 2 * (++cnum) - 1;
		if (hushnum >= H->TableSize)
		{
			hushnum -= H->TableSize;
		}
	}
	return hushnum;
}

void Insert(char *Tel, HashTable H)
{
	int hush = Find(Tel, H);
	if (H->ThisCell[hush].Info == empty)
	{
		H->ThisCell[hush].Info = full;
		strcpy(H->ThisCell[hush].TelStr, Tel);
	}
}
int main()
{
	char str[100];
	HashTable H;
	H = Initial(10);

	while (scanf("%11s,", str) != EOF)
	{
		Insert(str, H);
	}
	for (int i = 0; i < H->TableSize; i++)
	{
		if (i !=H->TableSize - 1)
		{
			if (H->ThisCell[i].Info == empty)
			{
				printf("0,");
			}
			else
			{
				printf("%s,", H->ThisCell[i].TelStr);
			}
		}
		else
		{
			if (H->ThisCell[i].Info == empty)
			{
				printf("0");
			}
			else
			{
				printf("%s", H->ThisCell[i].TelStr);
			}
		}
	}
	printf("\n");
	return 0;
}

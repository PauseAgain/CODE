#include<string.h>
#include<stdio.h>
#include <stdlib.h>
typedef char ElementType;
#define Tellen 11
enum status
{
	emtpy,
	full
};

typedef struct Cell
{
	enum status Info;
	ElementType *Telnum;
} Cell;

typedef struct HushTableNode{
	Cell *ThisCell;
	int tablesize;
}HashTableNode,* HashTable;

int Hush(ElementType *tel,int num)
{
	return ((tel[Tellen-1] - '0') % num);
}
HashTable Initial(int Tablesize)
{
		HashTable H = (HashTable)malloc(sizeof(HashTableNode));
	H->tablesize = Tablesize;
	H->ThisCell = (Cell *)malloc(sizeof(Cell) * Tablesize);
	for (int i = 0; i < Tablesize;i++)
	{
		H->ThisCell[i].Info = emtpy;
		H->ThisCell[i].Telnum = (ElementType *)malloc(Tellen * sizeof(ElementType));
	}
	return H;
}
int Find(ElementType *Telnumber,HashTable H)
{
	int cnum = 0;
	int afthush = Hush(Telnumber, H->tablesize);
	while(H->ThisCell[afthush].Info!=emtpy&& strcmp(H->ThisCell->Telnum,Telnumber)!=0)
	{
		//!
		afthush += 2 * (++cnum) - 1;
		//!

		if(afthush>=H->tablesize)
		{
			afthush -= H->tablesize;
		}
	}
	return afthush;
}

void Insert(ElementType *telstr,HashTable H)
{
	int position = Find(telstr, H);
	if(H->ThisCell[position].Info!=full )
	{
		H->ThisCell[position].Info = full;
		strcpy(H->ThisCell[position].Telnum, telstr);
	}
}

int main()
{
	char str[100];
	HashTable H;
	H = Initial(Tellen - 1);
	while(scanf("%11s,",str)!=EOF)
	{
		Insert(str, H);

	}

	for (int i = 0; i < H->tablesize;i++)
	{
		if(i!=H->tablesize-1)
		{
			if(H->ThisCell[i].Info==emtpy)
			{
				printf("0,");
			}
			else{
				printf("%s,", H->ThisCell[i].Telnum);
			}
		}
		else{
			if(H->ThisCell[i].Info==emtpy)
			{
				printf("0");
			}
			else{
				printf("%s", H->ThisCell[i].Telnum);
			}
		}
	}
	printf("\n");
	return 0;
}
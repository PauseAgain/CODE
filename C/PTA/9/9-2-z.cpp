#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum status
{
    legitimate,
    empty
};
typedef struct Cell
{
    enum status Info;
    char *Telnum;
} Cell;
typedef struct HashTableNode
{
    int tablesize;
    Cell *Thiscells;
} HashTableNode, *HashTable;
int Hash(char *Key, int num)
{
    return (Key[10] - '0') % num;
}
HashTable Initial(int tablesize)
{
    HashTable H;
    H = malloc(sizeof(HashTableNode));
    H->tablesize = tablesize;
    H->Thiscells = malloc(sizeof(HashTableNode) * tablesize);
    for (int i = 0; i < tablesize; i++)
    {
        H->Thiscells[i].Telnum = malloc(sizeof(char) * 11);
        H->Thiscells[i].Info = empty;
    }
    return H;
}
int Find(char *Key, HashTable H)
{
    int cmun = 0;
    int i;
    i = Hash(Key, H->tablesize);
    while (H->Thiscells[i].Info != empty && strcmp(H->Thiscells[i].Telnum, Key) != 0)
    {
        i += 2 * ++cmun - 1;
        if (i >= H->tablesize)
        {
            i -= H->tablesize;
        }
    }
    return i;
}
void Insert(char *Key, HashTable H)
{
    int pos;
    pos = Find(Key, H);
    if (H->Thiscells[pos].Info != legitimate)
    {
        H->Thiscells[pos].Info = legitimate;
        strcpy(H->Thiscells[pos].Telnum, Key);
    }
}
int main()
{
    char str[200];
    HashTable H;
    H = Initial(10);
    while (scanf("%11s,", str) != EOF)
    {
        Insert(str, H);
    }
    for (int i = 0; i < H->tablesize; i++)
    {
        if (i == H->tablesize - 1)
        {
            if (H->Thiscells[i].Info == empty)
            {
                printf("0");
            }
            else
                printf("%s", H->Thiscells[i].Telnum);
        }
        else
        {
            if (H->Thiscells[i].Info == empty)
            {
                printf("0,");
            }
            else
                printf("%s,", H->Thiscells[i].Telnum);
        }
    }
    return 0;
}
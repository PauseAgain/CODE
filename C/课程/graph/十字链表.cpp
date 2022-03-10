#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ArcBox{
    int headVex,tailVex;
    struct ArcBox *hLink;
    struct ArcBox *tLink;
}ArcBox;//弧结点

typedef struct VexNode{
    int data;
    int like[5];
    int belike[5];
    ArcBox *firIn;
    ArcBox *firOut;
}VexNode;//顶点结点

typedef struct{
    VexNode List[5];
    int vexnums,arcnums;
}Graph;//十字链表


int TransStrToInt(int *num, const char *str)
{
    int i = 0; int j = 0;
    int tmp = 0;
    int len = 0;
    while(str[i]!='\0')
    {

        while(str[i] != ',')
        {
            tmp = tmp * 10 + str[i] - '0';
            ++i;
        }
        num[j] = tmp;
        len++;
        tmp = 0;
        i ++;
        j ++;
    }
    return j;
}//将逗号分隔的数字串转为数组 并返回数组的长度

void Connect(Graph* G,int x,int y)//插入弧
{
    ArcBox *A = (ArcBox*)malloc(sizeof(ArcBox));
    A->tailVex = x;
    A->headVex = y;
    A->tLink = G->List[x].firOut;
    A->hLink = G->List[y].firIn;
    G->List[x].firOut = A;
    G->List[y].firIn = A;
}

void sort(int *a, int length)//数组排序
{
    int i, j, temp;
    for(i = 0; i < length; ++i){
        for(j = length - 1; j > i; --j){
            if(a[j] < a[j - 1]){
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}
void like(Graph *G,int index)//来点赞了
{
    ArcBox *ptr = G->List[index].firOut;
    int i = 0;
    int cont = 0;
    while (ptr)//获取好友列表 like[]
    {
        G->List[index].like[i] = ptr->headVex;
        cont++;i++;
        ptr = ptr->tLink;
    }
    sort(G->List[index].like, cont);//给like[]排序

    for (int j = 0; j < cont;j = j+2)//给排序单数的好友点赞！！
    {
        int n = G->List[index].like[j];
        G->List[n].belike[index] = index;
    }
}
//输出点赞结果
void printflike(Graph *G,int index)
{
    int flag = 0;
    for (int i = 0; i < 5; ++i) {
        if(G->List[index].belike[i] != -1)
        {
            printf("%d,",i);
            flag = 1;
        }
    }
    if(!flag)
        printf("-1");
}

//打印好友关系（没用）
void printDG(Graph *G)
{
    for(int i = 0; i < 5; i++)
    {
        ArcBox *ptail = G->List[i].firOut;
        ArcBox *phead = G->List[i].firIn;


        while (ptail) {
            printf("%d-%d ", ptail->tailVex, ptail->headVex);
            ptail = ptail->tLink;
        }
        printf("\n");


        while (phead) {
            printf("%d-%d ", phead->tailVex, phead->headVex);
            phead = phead->hLink;
        }
        printf("\n");
    }
}
int main()
{
    Graph G;
    G.vexnums = 5;
    G.arcnums = 5;
    for(int i = 0;i < 5; i++)//初始化
    {
        G.List[i].data = i;
        G.List[i].firIn=G.List[i].firOut=NULL;
        memset(G.List[i].like,-1,sizeof(int)*5);
        memset(G.List[i].belike,-1,sizeof(int)*5);
    }

    char str[100] = {'\0'};
    int num[100] = {0};
    scanf("%s",str);

    int Len;
    Len = TransStrToInt(num,str);

    for (int j = 0; j < Len; j = j + 2 )//将好友关系输入十字链表中
        Connect(&G, num[j],num[j+1]);

    for (int k = 0; k < 5; ++k) //开始点赞
        like(&G,k);

    int targ;
    scanf("%d", &targ);

    printflike(&G, targ);

}


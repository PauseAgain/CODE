#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000007
int la,lb;
int next[N];
char a[N],b[N];
//next[i]=j,表示前缀j-1和后缀j-1位一定一样，开始匹配第j位
//所以next[i]=j。然后看后面第i位是不是前缀的第j位，
//是的话就开始比较i+1,否则执行else,j=next[j],就是前面最大的是j，所以第i+1的最大的相同前后缀是next[j]
//++i
//：先增加，后引用，先执行i=i+1;再用运算后的i进行其它计算。
void Next()
{
    int i=2;//因为中国人习惯用1，所以next【0】不改变，next[1]是0，next【2】是1
    int j=0;
    for(i=2; i<=lb; i++)
    {
        while(j>0&&b[j+1]!=b[i])
        {//遇到第一个不匹配
            j=next[j];
        }
        if(b[j+1]==b[i])
        {
            j++;
        }
        next[i]=j;
    }
}
void KMP(){
    int j=0;
for(int i=1;i<=la;i++){
    while(j>0&&b[j+1]!=a[i]){//遇到第一个不匹配
        j=next[j];
    }
    if(b[j+1]==a[i]){//匹配
        j++;
    }
    if(j==lb){
// 当模式串下标后移 lb位，说明找到了一个完整的模式串
        printf("%d\n",i-lb+1);
        j=next[j];//退回
    }
}

}
int main()
{

    scanf("%s",a+1);// 字符串从[ s地址 + 1 ]开始
    scanf("%s",b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
    Next();
    KMP();
    for(int i=1; i<=lb; i++)
    {
        if(i != 1) printf(" ");
        printf("%d",next[i]);
    }
    printf("\n");
    return 0;
}
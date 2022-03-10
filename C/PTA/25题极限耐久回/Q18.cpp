
#include <stdio.h>
int main()
{
    int A[11] = {0, 2, 1, 3, 2, 4, 2, 1, 1, 2, 3}; //! A[i]代表了从A->I,S->T的入度
    int B[11] = {0};                               // B[i]表示是否已经打印
    char a1, a2;
    int i, j, a, b;
    scanf("%c,%c", &a1, &a2);
    if (a1 < 83) // a,b代表这两个数的以A为0起点的字母的序号，因为从有I->S的跳跃，所以分情况讨论
        a = a1 - 64;
    else
        a = a1 - 83;
    if (a2 < 83)
        b = a2 - 64;
    else
        b = a2 - 74;

    A[b]--; //!被删除边指向节点（b）的入度要-1

    while (A[10] != -1 /*当最后一个T A[10]入度不为零之前*/)
    { //! 下面是打印模块
        for (j = 0; j < 11; j++)
        {
            if (A[j] == 0) //!每一次都遍历A[j]寻找入度为0的点打印字母
            {
                if (j == 0)
                {
                    printf("S,");
                    B[j] = 1; //!打印结束B[i]=1标记
                }
                else if (j > 0 && j < 10) //
                {
                    a1 = j + 64;
                    printf("%c,", a1);
                    B[j] = 1;
                }
                else
                {

                    printf("T,");
                    B[j] = 1;
                }
            }
        }
        ////
        for (i = 0; i < 11; i++)
        {
            if (B[i] == 1)
            {
                if (i == 0)
                {
                    if (a == i)
                        A[b]++;
                    A[i] = -1; //?
                    i = 0;
                    B[i]--; //!
                    A[1]--;
                    A[4]--;
                    A[7]--;
                }
                else if (i > 0 && i < 10)
                {
                    A[i] = -1; //?把点删掉了？
                    B[i]--;    //!
                    if (i == 1)
                    {
                        if (a == i)
                            A[b]++;
                        A[2]--;
                        A[5]--;
                    }
                    if (i == 2)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                    }
                    if (i == 3)
                    {
                        if (a == i)
                            A[b]++;
                        A[10]--;
                    }
                    if (i == 4)
                    {
                        if (a == i)
                            A[b]++;
                        A[1]--;
                        A[5]--;
                    }
                    if (i == 5)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                        A[6]--;
                        A[9]--;
                    }
                    if (i == 6)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                        A[10]--;
                    }
                    if (i == 7)
                    {
                        if (a == i)
                            A[b]++;
                        A[4]--;
                        A[5]--;
                        A[8]--;
                    }
                    if (i == 8)
                    {
                        if (a == i)
                            A[b]++;
                        A[5]--;
                        A[9]--;
                    }
                    if (i == 9)
                    {
                        if (a == i)
                            A[b]++;
                        A[6]--;
                        A[10]--;
                    }
                }
                else
                {
                    A[10] = -1;
                }
            }
        }
    }
    printf("\n");
    return 0;
}

//!联系， i<10而不是i<9,else if 打成 if 导致耻辱性的 S,B 输出
#include <stdio.h>
int main()
{
    int A[11] = {0, 2, 1, 3, 2, 4, 2, 1, 1, 2, 3};
    int B[11] = {0};
    int a, b, i, j;
    char a1, a2;
    scanf("%c,%c", &a1, &a2);
    if (a1 < 83)
        a = a1 - 64;
    else
        a = a1 - 83;
    if (a2 < 83)
        b = a2 - 64;
    else
        b = a2 - 74;
    A[b]--;

    while (A[10] != -1)
    {
        for (j = 0; j < 11; j++)
        {
            if (A[j] == 0)
            {
                if (j == 0)
                {
                    printf("S,");
                    B[j] = 1;
                }
                else if (j > 0 && j < 10)
                {
                    a1 = (j + 64);
                    printf("%c,", a1);
                    B[j] = 1;
                }
                else
                {
                    printf("T,");
                    B[j] = 1;
                }
            }
        }
        for (i = 0; i < 11; i++)
        {
            if (B[i] == 1)
            {
                if (i == 0)
                {
                    if (i == a)
                    {
                        A[b]++;
                    }
                    A[i] = -1;
                    i = 0;
                    B[i]--;
                    A[1]--;
                    A[4]--;
                    A[7]--;
                }
                //!    XXX if XXX (i > 0 && i < 10)
                else if (i > 0 && i < 10)
                {
                    A[i] = -1;
                    B[i]--;

                    if (i == 1)
                    {
                        if (a == i)
                        {
                            A[b]++;
                        }
                        A[2]--;
                        A[5]--;
                    }
                    if (i == 2)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                    }
                    if (i == 3)
                    {
                        if (a == i)
                            A[b]++;
                        A[10]--;
                    }
                    if (i == 4)
                    {
                        if (a == i)
                            A[b]++;
                        A[1]--;
                        A[5]--;
                    }
                    if (i == 5)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                        A[6]--;
                        A[9]--;
                    }
                    if (i == 6)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                        A[10]--;
                    }
                    if (i == 7)
                    {
                        if (a == i)
                            A[b]++;
                        A[4]--;
                        A[5]--;
                        A[8]--;
                    }
                    if (i == 8)
                    {
                        if (a == i)
                            A[b]++;
                        A[5]--;
                        A[9]--;
                    }
                    if (i == 9)
                    {
                        if (a == i)
                            A[b]++;
                        A[6]--;
                        A[10]--;
                    }
                }
                else
                {
                    A[10] = -1;
                }
            }
        }
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
int main()
{
    int i, j;
    int A[11] = {0, 2, 1, 3, 2, 4, 2, 1, 1, 2, 3};
    int B[11] = {0};
    int a, b;
    char a1, a2;
    scanf("%c,%c", &a1, &a2);

    //! XXX  if (a1 - '0' < 83)
    if (a1 < 83)
    {
        a = a1 - 64;
    }
    else
    {
        a = a1 - 83;
    }
    //! XXX  if (a2 - '0' < 83)
    if (a2 < 83)
    {
        b = a2 - 64;
    }
    else
    {
        b = a2 - 74;
    }
    //! 【耻辱】  忘了！！！！    A[b]--;
    A[b]--;
    while (A[10] != -1)
    {
        for (j = 0; j < 11; j++)
        {
            if (A[j] == 0)
            {
                if (j == 0)
                {
                    printf("S,");
                    B[j] = 1;
                }
                else if (j > 0 && j < 10)
                {
                    a1 = (j + 64);
                    printf("%c,", a1);
                    B[j] = 1;
                }
                else
                {
                    printf("T,");
                    B[j] = 1;
                }
            }
        }

        for (i = 0; i < 11; i++)
        {
            if (B[i] == 1)
            {
                if (i == 0)
                {
                    if (i == a)
                    {
                        A[b]++;
                    }
                    A[i] = -1;
                    B[i]--;
                    A[1]--;
                    A[4]--;
                    A[7]--;
                }
                else if (i > 0 && i < 10)
                {
                    A[i] = -1;
                    B[i]--;
                    if (i == 1)
                    {
                        if (a == i)
                        {
                            A[b]++;
                        }
                        A[2]--;
                        A[5]--;
                    }
                    if (i == 2)
                    {
                        if (a == i)
                        {
                            A[b]++;
                        }
                        A[3]--;
                    }
                    if (i == 3)
                    {
                        if (a == i)
                            A[b]++;
                        A[10]--;
                    }
                    if (i == 4)
                    {
                        if (a == i)
                            A[b]++;
                        A[1]--;
                        A[5]--;
                    }
                    if (i == 5)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                        A[6]--;
                        A[9]--;
                    }
                    if (i == 6)
                    {
                        if (a == i)
                            A[b]++;
                        A[3]--;
                        A[10]--;
                    }
                    if (i == 7)
                    {
                        if (a == i)
                            A[b]++;
                        A[4]--;
                        A[5]--;
                        A[8]--;
                    }
                    if (i == 8)
                    {
                        if (a == i)
                            A[b]++;
                        A[5]--;
                        A[9]--;
                    }
                    if (i == 9)
                    {
                        if (i == a)
                        {
                            A[b]++;
                        }
                        A[6]--;
                        A[10]--;
                    }
                }
                else
                {
                    A[10] = -1;
                }
            }
        }
    }
    printf("\n");
    return 0;
}

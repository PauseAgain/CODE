#include <stdio.h>
void to1(int a[10][10], int i, int j);
void DFS(int a[10][10], int flag[], int start);
int main()
{
    int a[10][10];
    int flag[10];

    for (int i = 1; i <= 8; i++)
    {
        flag[i] = 0;
    }
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            a[i][j] = 0;
        }
    }
    to1(a, 1, 2);
    to1(a, 1, 3);
    to1(a, 2, 4);
    to1(a, 2, 5);
    to1(a, 3, 6);
    to1(a, 3, 7);
    to1(a, 4, 8);
    to1(a, 5, 8);
    to1(a, 6, 8);
    to1(a, 7, 8);
    int start;
    scanf("%d", &start);
    flag[start] = 1;
    printf("%d,", start);
    DFS(a, flag, start);

    return 0;
}

void to1(int a[10][10], int i, int j)
{
    a[i][j] = 1;
    a[j][i] = 1;
}

void DFS(int a[10][10], int flag[], int start)
{
    for (int j = 1; j <= 8; j++)
    {
        if (a[start][j] == 1 && flag[j] == 0)
        {
            printf("%d,", j);
            flag[j] = 1;
            DFS(a, flag, j);
        }
    }
}
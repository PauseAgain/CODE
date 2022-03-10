#include <stdio.h>
#define inf 1e9
int main()
{
    int a[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a[i][j] = inf;
        }
    }

    a[1][2] = 3;
    a[1][3] = 3;
    a[1][4] = 6;
    a[2][4] = 2;
    a[2][5] = 5;
    a[3][4] = 3;
    a[3][6] = 3;
    a[4][5] = 2;
    a[4][6] = 2;
    a[4][7] = 5;
    a[5][7] = 3;
    a[6][7] = 4;

    int x1, x2, x;
    scanf("%d,%d,%d", &x1, &x2, &x);
    a[x1][x2] = inf;

    int array[130];
    int front = 0;
    int rear = -1;
    int size = 0;

    int E[8];
    int L[8];
    for (int i = 0; i < 8; i++)
    {

        E[i] = 0;
        L[i] = inf;
    }
    int v, w; // from v to w;
    array[++rear] = 1;
    size++;
    E[1] = 0;
    while (size != 0)
    {
        v = array[front++];
        size--;
        for (w = 1; w <= 7; w++)
        {
            if (a[v][w] != inf)
            {
                array[++rear] = w;
                size++;
                if (a[v][w] + E[v] > E[w])
                {
                    E[w] = a[v][w] + E[v];
                }
            }
        }
    }

    L[7] = E[7];
    front = 0;
    rear = -1;
    size = 0;
    array[++rear] = 7;
    size++;

    while (size != 0)
    {
        w = array[front++];
        size--;
        for (v = 1; v <= 7; v++)
        {
            if (a[v][w] != inf)
            {
                array[++rear] = v;
                size++;
                if (L[w] - a[v][w] < L[v])
                {
                    L[v] = L[w] - a[v][w];
                }
            }
        }
    }

    int result = 0;
    result = L[x] - E[x];
    printf("%d", result);
    return 0;
}
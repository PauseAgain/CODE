#include <stdio.h>
#include <stdlib.h>
#define inf 1e9
// dist-距离 Vex-顶点
#define NodeNum 11
void aDist(int a[NodeNum][NodeNum], int dist, int i, int j);

typedef struct table
{
	int x;
	int known;
	int dist;
	int lastVex;
} tab, *Table;

void dijkstra(Table T[], int a[NodeNum][NodeNum]);
void insertSort(int a[]);
int main()
{
	Table T[NodeNum];
	// initailize T
	for (int i = 0; i < NodeNum; i++)
	{
		T[i] = malloc(sizeof(tab));
		T[i]->known = 0;
		T[i]->dist = inf;
		T[i]->lastVex = 0;
	}

	int a[NodeNum][NodeNum];
	for (int i = 0; i < NodeNum; i++)
	{
		for (int j = 0; j < NodeNum; j++)
		{
			a[i][j] = inf;
		}
	}

	aDist(a, 3, 1, 2);//
	aDist(a, 10, 2, 3);//
	aDist(a, 4, 1, 4);//
	aDist(a, 4, 1, 5);//
	aDist(a, 2, 2, 5);//
	aDist(a, 3, 2, 6);//
	aDist(a, 6, 3, 6);//
	aDist(a, 1, 3, 7);//
	aDist(a, 5, 4, 5);//
	aDist(a, 11, 5, 6);//
	aDist(a, 2, 6, 7);//
	aDist(a, 6, 4, 8);//
	aDist(a, 2, 5, 8);//
	aDist(a, 1, 5, 9);//
	aDist(a, 3, 6, 9);//
	aDist(a, 11, 6, 10);//
	aDist(a, 8, 7, 10);//
	aDist(a, 4, 8, 9);//
	aDist(a, 7, 9, 10);//

	char x, y;
	int dist;
	//!录入并且修改 数据
	x = getchar();
	getchar(); // catch','
	y = getchar();
	getchar(); //  catch','
	scanf("%d", &dist);
	int x1, x2;
	x1 = x - 'A' + 1;
	x2 = y - 'A' + 1;

	a[x1][x2] = dist;
	a[x2][x1] = dist;
	T[1]->dist = 0; //!
/////////////
	dijkstra(T, a);
////////////
	int weight[9];
	for (int i = 2; i <= 10; i++)
	{//weight[0-8]=a
		weight[i - 2] = a[i][T[i]->lastVex];
	}
	insertSort(weight);
	for (int i = 0; i < 9; i++)
	{
		printf("%d,", weight[i]);
	}

	return 0;
}
void aDist(int a[NodeNum][NodeNum], int dist, int i, int j)
{
	a[i][j] = dist;
	a[j][i] = dist;
}

void dijkstra(Table T[], int a[NodeNum][NodeNum])
{
	int v, w;

	for (int cnt = 1; cnt <= 10; cnt++)
	{
		//! Find  Unknown minV
		int min = inf;
		for (int i = 1; i <= 10; i++)
		{
			if (T[i]->known == 0)
			{
				if (min > T[i]->dist)
				{
					min = T[i]->dist;
					v = i;
				}
			}
		}
/////////////////////////////////////////////
		T[v]->known = 1;//!Know V
/////////////////////////////////////////////
//!遍历V  临近  所有  未知节点   W
		for (int w = 1; w <= 10; w++)//!遍历 所有
		{
			if (a[v][w] != inf/*临近*/ && T[w]->known == 0/*未知节点*/)
			{
				if (a[v][w] < T[w]->dist)//!如果 dv+dvw < dw    
				{
					T[w]->dist = a[v][w];//!dw = a[v][w]
					T[w]->lastVex = v;
				}
			}
		}
/////////////////////////////////////////////
	}
}

void insertSort(int a[])
{
	int temp, j;
	int n = 9;
	for (int i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i; j > 0 && temp < a[j - 1]; j--)

		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}
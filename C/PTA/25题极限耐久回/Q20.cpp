#include <stdio.h>
#include <stdlib.h>
#define NodeNum 11
#define broke 1e9
enum status
{
	unknown,
	known
};
typedef struct tab
{
	int x;
	enum status Info;
	int dist;
	int LastVex;
} tab, *Table;
void aDist(int a[NodeNum][NodeNum], int dist, int i, int j)
{
	a[i][j] = dist;
	a[j][i] = dist;
}
void InsertionSort(int *a, int n)
{
	int i, j, temp;

	//! XXX  i=0  XXX
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i; j > 0 && temp < a[j - 1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}
Table *InitializeTable(Table *T, int TableSize)
{
	T = (Table *)malloc(sizeof(tab) * TableSize);
	for (int i = 0; i < TableSize; i++)
	{
		T[i] = (Table)malloc(sizeof(tab));
		T[i]->dist = broke;
		T[i]->Info = unknown;
		T[i]->LastVex = 0;
	}
	return T;
}

// void Dijkstra(Table *T, int a[NodeNum][NodeNum])
// {
// 	int v, w;
// 	////
// 	for (int i = 1; i <= 10; i++)
// 	{
// 		int MinNum = broke;
// 		for (int j = 1; j <= 10; j++)
// 		{

// 			if (T[j]->Info == unknown)
// 			{
// 				if (MinNum > T[j]->dist)
// 				{
// 					MinNum = T[j]->dist;
// 					v = j;
// 				}
// 			}
// 		}
// 	}
// 	////
// 	T[v]->Info = known;
// 	////
// 	for ( w = 1; w <= 10; w++)
// 	{
// 		if (a[v][w] != broke && T[w]->Info == unknown)
// 		{
// 			if (a[v][w] < T[w]->dist)
// 			{
// 				T[w]->dist = a[v][w];
// 				T[w]->LastVex = v;
// 			}
// 		}
// 	}
// }

void Dijkstra(Table T[], int a[NodeNum][NodeNum])
{
	int v, w;

	for (int cnt = 1; cnt <= 10; cnt++)
	{
		//! Find  Unknown minV
		int min = broke;
		for (int i = 1; i <= 10; i++)
		{
			if (T[i]->Info == unknown)
			{
				if (min > T[i]->dist)
				{
					min = T[i]->dist;
					v = i;
				}
			}
		}
		/////////////////////////////////////////////
		T[v]->Info = known; //! Know V
		/////////////////////////////////////////////
		//!遍历V  临近  所有  未知节点   W
		for (w = 1; w <= 10; w++) //!遍历 所有
		{
			if (a[v][w] != broke /*临近*/ && T[w]->Info == unknown /*未知节点*/)
			{
				if (a[v][w] < T[w]->dist) //!如果 dv+dvw < dw
				{
					T[w]->dist = a[v][w]; //! dw = a[v][w]
					T[w]->LastVex = v;
				}
			}
		}
		/////////////////////////////////////////////
	}
}

int main()
{

	Table *T = InitializeTable(T, NodeNum);

	int a[NodeNum][NodeNum];
	for (int i = 0; i < NodeNum; i++)
	{
		for (int j = 0; j < NodeNum; j++)
		{
			a[i][j] = broke;
		}
	}

	aDist(a, 3, 1, 2);	 //
	aDist(a, 10, 2, 3);	 //
	aDist(a, 4, 1, 4);	 //
	aDist(a, 4, 1, 5);	 //
	aDist(a, 2, 2, 5);	 //
	aDist(a, 3, 2, 6);	 //
	aDist(a, 6, 3, 6);	 //
	aDist(a, 1, 3, 7);	 //
	aDist(a, 5, 4, 5);	 //
	aDist(a, 11, 5, 6);	 //
	aDist(a, 2, 6, 7);	 //
	aDist(a, 6, 4, 8);	 //
	aDist(a, 2, 5, 8);	 //
	aDist(a, 1, 5, 9);	 //
	aDist(a, 3, 6, 9);	 //
	aDist(a, 11, 6, 10); //
	aDist(a, 8, 7, 10);	 //
	aDist(a, 4, 8, 9);	 //
	aDist(a, 7, 9, 10);	 //

	char str1, str2;
	int p, q, r;
	scanf("%c,%c", &str1, &str2);
	scanf(",%d", &r);
	////printf("\nstr1=%c,str2=%c,r=%d\n", str1, str2, r);
	p = (int)(str1 - 'A' + 1);
	q = (int)(str2 - 'A' + 1);
	a[p][q] = r;
	a[q][p] = r;
	T[1]->dist = 0;

	Dijkstra(T, a);

	int weight[9];
	for (int i = 2; i <= 10; i++)
	{
		weight[i - 2] = a[i][T[i]->LastVex];
		// w[0]=a[2][T[2]->LastVex]
		// w[1]=a[3][T[3]->LastVex]
		//......
		// w[8]=a[10][T[10]->LastVex]
	}

	InsertionSort(weight, 9);

	for (int i = 0; i < 9; i++)
	{
		printf("%d,", weight[i]);
	}

	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define NodeNum 11
#define BrokeLine 1e9
enum status
{
	unknown, known;
};
typedef struct tab
{
	int v;
	enum status Info;
	int dist;
	int LastVex;
} tab, *Table;
void aDist(int A[NodeNum][NodeNum], int dist, int i, int j)
{
	A[i][j] = dist;
	A[j][i] = dist;
}
void InsertionSort(int *A, n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		tmp = a[i];
		for (j = i; j > 0 & tmp < A[j - 1]; j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = tmp;
	}
}
Table *InitializeTable(Table *T, int TableSize)
{
	T = (Table *)malloc(sizeof(tab) * TableSize);
	for (int i = 0; i < TableSize; i++)
	{
		T[i] = (Table)malloc(sizeof(tab));
		T[i]->dist = broke;
		T[i]->Info = unknown;
		T[i]->LastVex = 0;
	}
	return T;
}

void Dijkstra(Table *T, int A[NodeNum][NodeNum])
{
	int v, w;
	for (int cnt = 1; cnt <= 10; cnt++)
	{
		int min = broke;
		for (int i = 1; i <= 10; i++)
		{
			if (T[i]->Info == unknown)
			{
				if (min > T[i]->dist)
				{
					min = T[i]->dist;
					v = i;
				}
			}
		}
		T[v]->Info = known;
		for (w = 1; w <= 10;w++)
		{
			if(A[v][w]!=broke&&T[w]->Info==unknown)
			{
				if(A[v][w]<T[w]->dist)
				{
					T[w]->dist = A[v][w];
					T[w]->LastVex = v;
				}
			}
		}
	}
}
int main()
{
	Table *T = InitializeTable(T, NodeNum);
	int a[NodeNum][NodeNum];
	for (int 1 = 0; i < 11;i++)
	{
		for (j = 0; j < 11;j++)
			a[i][j] = broke;
	}
	aDist(a, 3, 1, 2);	 //
	aDist(a, 10, 2, 3);	 //
	aDist(a, 4, 1, 4);	 //
	aDist(a, 4, 1, 5);	 //
	aDist(a, 2, 2, 5);	 //
	aDist(a, 3, 2, 6);	 //
	aDist(a, 6, 3, 6);	 //
	aDist(a, 1, 3, 7);	 //
	aDist(a, 5, 4, 5);	 //
	aDist(a, 11, 5, 6);	 //
	aDist(a, 2, 6, 7);	 //
	aDist(a, 6, 4, 8);	 //
	aDist(a, 2, 5, 8);	 //
	aDist(a, 1, 5, 9);	 //
	aDist(a, 3, 6, 9);	 //
	aDist(a, 11, 6, 10); //
	aDist(a, 8, 7, 10);	 //
	aDist(a, 4, 8, 9);	 //
	aDist(a, 7, 9, 10);	 //
	char a1, a2;
	int p, q, r;
	scanf("%c,%c,", &a1, &a2);
	scanf("%d",& r);
	p = (a1 - 'A' + 1);
	q = (a2 - 'A' + 1);
	a[p][q] = a[q][p] = r;
	T[1]->dist = 0;
	Dijkstra(T, a);
	int Weight[9];
	for (int i = 2; i <= 10;i++)
	{
		Weight[i - 2] = A[i][T[i]->LastVex];
	}

	InsertionSort(Weight);
	for(int i = 0; i < 9;i++)
	{
		printf("%d,", Weight[i]);
	}
	printf("\n");
	return 0;
}
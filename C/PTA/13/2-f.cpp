#include <stdio.h>
int Graph[1024][1024] = {0};
int V[1024] = {0};
int Vexnum, Arcnum;
int Judge(int N, int *cnt);
int main()
{
	int i, j;
	scanf("%d%d", &Vexnum, &Arcnum);
	for (i = 1; i <= Arcnum; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		Graph[a][b] = Graph[b][a] = 1;
		//!  XXX   V[a]++; XXX // V[b]++;  XXX
	}
	int k;
	scanf("%d", &k);
	for (i = 1; i <= k; i++)
	{
		int N;
		int cnt[1024] = {0};
		scanf("%d", &N);
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &V[j]);
			if (j < N)
			{
				cnt[V[j]]++;
			}
		}
		if (Judge(N, cnt) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
int Judge(int N, int *cnt)
{

	if (V[1] != V[N] || N - Vexnum != 1)
	{
		return 0;
	}
	for (int i = 1; i <= Vexnum; i++)
	{
		//! if (cnt[V[i]] != 1)
		if (cnt[i] != 1)
		{
			return 0;
		}
	}
	//! for (int i = 2; i <= Vexnum; i++)
	for (int i = 2; i <= Vexnum + 1;i++)
	{
		if (Graph[V[i]][V[i - 1]] != 1)
		{
			return 0;
		}
	}
	return 1;
}
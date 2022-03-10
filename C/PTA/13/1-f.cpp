#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 1e9
int n;
int m;
int flag = 0;
int e[1024][1024];
int degree[1024];
int vis[1024];
void DFS(int s, int c);
int Check(void);
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
		degree[a]++;
		degree[b]++;
	}
	vis[1] = 1;
	DFS(1, 1);
	if (flag && Check())
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return 0;
}
int Check(void)
{
	for (int i = 1; i <= n; i++)
		if (degree[i] % 2)
		{
			return 0;
		}

	return 1;
}
void DFS(int s, int c)
{
	if (flag)
	{
		return;
	}

	if (c == n)
	{
		flag = 1;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i] || e[s][i] == 0)
			continue;

		vis[i] = 1;
		DFS(i, c + 1);
		vis[i] = 0;
	}
}

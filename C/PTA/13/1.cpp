// #include <stdio.h>
// int count[1024], spot, edge, from, to, i, parent[1024], fatherf, fathers, sum;
// int find(int index)
// {
// 	////printf("  \n  index=%d,parernt[index]=%d ", index, parent[index]);
// 	if (index == parent[index])
// 		////printf("\nFIND:==,return %d", index);
// 		return index;
// 	////printf("\nFIND:    !=\n");
// 	return parent[index] = find(parent[index]);
// }
// int main()
// {

// 	scanf("%d%d", &spot, &edge);
// 	for (i = 1; i <= spot; i++)
// 		parent[i] = i;
// 	while (edge--)
// 	{
// 		scanf("%d%d" ,&from, &to);
// 		count[from]++;
// 		count[to]++;
// 		fatherf = find(from);
// 		printf("\n  from%d to%d ,fatherf=%d",from,to ,fatherf);
// 		fathers = find(to);
// 		printf("   fathers=%d\n",fathers);
// 		if (fatherf != fathers)
// 			printf("Set parent[%d] = %d \n", fatherf, fathers);
// 			parent[fatherf] = fathers;
// 	}
// 	for (i = 1; i <= spot; i++)
// 		if (count[i] % 2)
// 		{
// 			printf("0");
// 			break;
// 		}
// 	if (i > spot)//!说明没有度为偶数的项
// 	{
// 		for (i = 1/*i又被归1了*/; i <= spot; i++)
// 			if (parent[i] == i)
// 			{
// 				sum++;
// 				if (sum > 1)
// 				{
// 					printf("0");
// 					break;
// 				}
// 			}
// 		if (i > spot)
// 			printf("1");
// 	}
// 	return 0;
// }
//! 1】利用并查集判断是否连通（其实最后就是看是不是有独立的一个点的情况，并且这种点 >1 的时候一定不连通）

//! 2】在利用并查集的时候，可以直接把两个点存进对方的数组里面（因为最后会判断每个点的奇偶，也就是与几个点联通）。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 999999999
int n; //点数量
int m; //边数量
int flag = 0;
int e[1001][1001];//e是邻接矩阵
int vis[1001];
int degree[1001];
void dfs(int s, int c) // DFS算法
{
	if (flag) //初始flag=0，默认不直接return
		return;
	if (c == n) //
	{
		flag = 1; //!当且仅当c==n，flag被标记为1,说明dfs递归到尽头了，让flag=1表示全覆盖
		return;
	}
	for (int i = 1; i <= n; i++)//从1开始循环n次
	{
		if (vis[i] || e[s][i] == 0)//! 跳过执行的必要条件是 【已经被发现】 或者 【从s->i没有链接】
			continue;//!continue语句用于循环语句中，作用是 【不执行循环体剩余部分】

		//如果vis[i]没有被发现或者有s->i链接，先发现，再递归，最后把i再“忘了”
		vis[i] = 1;//?其实我是不理解这个操作的，假意改信，日后悔过？
		dfs(i, c + 1);//!递归，c+1
		vis[i] = 0;//??????????????
	}
}
int check()
{
	for (int i = 1; i <= n; i++)//n次
		if (degree[i] % 2)//!一旦发现奇度项（奇%2 ！=0）
			return 0;//!即return 0
	return 1;//!满足条件return 1
}
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)//m个边，循环m次
	{
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;//无向图，邻接矩阵关系写入
		degree[a]++;//degree保存矩阵的度
		degree[b]++;//同上
	}
	vis[1] = 1;//发现第一个节点
	dfs(1, 1);//从第一个节点开始DFS
	if (flag && check())
		printf("1");
	else
		printf("0");
}
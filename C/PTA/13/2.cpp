//!
//!欧拉回路是指不重复地走过所有路径的回路，
//!而哈密尔顿环是指不重复地走过所有的点，并且最后还能回到起点的回路。

//?满足下面条件即为哈密顿圈：
//?（1）回路，即【第一个顶点=最后一个顶点】且【路径数=顶点数+1】。
//?（2）【除起点外每个顶点只经过1次】。
//?（3）所给【路径前后应连通】，即【G[v[i]][v[i-1]] != 0】

#include <stdio.h>
#define maxn 210

int G[maxn][maxn] = {0}; //存储图
int v[maxn] = {0};		 //用于存储输入的k个结点
int vexnum, arcnum;

int Judge(int N, int cnt[])
{
	if (N != vexnum + 1 || v[1] != v[N]) //!如果路径！=节点数+1，肯定不对  ｜｜ 如果第一个节点和第N个节点不是一个，也return 0
		return 0;
	for (int i = 1; i <= vexnum; i++)//i=1->vexnum,遍历探索
	{
		if (cnt[i] != 1)//!如果不是只经历了一次，一定完蛋
			return 0;
	}
	for (int i = 2/*第一个节点没有后，所以从2开始判断*/; i <= vexnum + 1; i++)//!判断所给的每一个点的前后连通性
	{
		if (!G[v[i]][v[i - 1]])
			return 0;
	}
	return 1;
}

int main()
{
	int i, j;
	scanf("%d %d", &vexnum, &arcnum); // vexnum 点数，arcnum 边数
	for (i = 1; i <= arcnum; i++)	  //图的录入，循环arcnum遍，i=1开始
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
	}
	int k; //有k个例子等待判断
	scanf("%d", &k);
	for (i = 1; i <= k; i++) //循环k次，从i=1开始
	{
		int N;
		int cnt[maxn] = {0};
		scanf("%d", &N);//保存这一行有几个

		for (j = 1; j <= N; j++)//例子数据的录入，循环N次
		{
			scanf("%d", &v[j]);
			if (j < N)
				cnt[v[j]]++;//!cnt[v[j]]记录了【编号为v[j]节点】的经过次数，
				//!而最后一个节点实际上并不计入汉密尔顿图的“经过节点”，所以当j=N（最后一个节点的时候），是不计入cnt[v[j]]次数的
		}

		if (Judge(N, cnt) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
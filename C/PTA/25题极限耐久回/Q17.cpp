
//!重要警告：要想要搞懂这一章去OneNote搜索十字链表
#include <stdio.h>
int main()
{
	int A[5][5], C[5][5];
	int B[20] = {0};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			A[i][j] = -1;
			C[i][j] = -1;
		}
	}
	int k = 0, i = 0, j = 0;
	int NeedNum;
	// 0,1,0,2,0,3,1,4,2,1,2,3,3,2,4,0,4,1,4,3,
	while (1) //?while循环i次,B[i]记录列数
	{
		//!前面的数字A 代表的这个人A  能够看到  后面那个数字B 代表的B人的朋友圈
		scanf("%d", &B[i]); //! B[i]储存人A(列A)

		if (getchar() == '\n' /*此处getchar不仅可以判断有没有换行，而且可以把','吃掉*/)
		{
			NeedNum = B[i]; //!所需第二行的数字被B[i]最后一次扫描吃掉了，这里B[i]就是我们需要的NeedNum
			break;			//换行结束循环
		}

		scanf("%d,", &k); //?k保存A可以看 B的朋友圈的数据：B的编号

		for (j = 0; /*每次j都在此处清零*/ C[B[i]][j] != -1; j++) //?寻找合适的j值
		{
			//!这一趟循环下来就能找到 这一行 已经穿了j个 实数，i不动
		}
		C[B[i]][j] = k; //!在第B[i（0-20）]列（0-5）   第j（from 0）行   写入新数据
		i++;			//循环一次i积累一次
	}

	//对C数组排升序
	for (k = 0; k < 5; k++)
	{
		for (i = 1; C[k][i] != -1; i++)
		{
			int Tmp = C[k][i];
			for (j = i; j > 0 && C[k][j - 1] > Tmp; j--)
			{
				C[k][j] = C[k][j - 1];
			}
			C[k][j] = Tmp;
		}
	}

	i = j = k = 0; //重新作为序数用
				   //!只给奇数点赞 J= 0，2，4...为条件
	for (i = 0; i < 5; i++)
	{
		for (j = 0; C[i][j] != -1; j += 2 /* 相隔2 */)
		{
			for (k = 0; A[C[i][j]][k] != -1; k++)
			{
			}
			A[C[i][j]][k] = i;
		}
	}
	//!只打印被赞表NeedNum行
	for (j = 0; A[NeedNum][j] != -1; j++)
	{
		printf("%d,", A[NeedNum][j]);
	}
	if (A[NeedNum][0] == -1) //!如果一个赞也没有
	{
		printf("-1");
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
int main()
{
	int A[5][5], C[5][5];
	int B[20] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	int num;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			C[i][j] = -1;
			A[i][j] = -1;
		}
	}

	i = j = k = 0;

	while (1)
	{
		scanf("%d", &B[i]);
		if (getchar() == '\n')
		{
			num = B[i];
			////printf("\nnum=%d", num);
			break;
		}

		scanf("%d,", &k);
		for (j = 0; C[B[i]][j] != -1; j++)
		{
		}
		C[B[i]][j] = k;
		i++;
	}

// for (i = 0; i < 5; i++)
// 	{
// 		for (j = 0; j < 5 && C[i][j] != -1; j++)
// 		{
// 			printf("\n C[%d][%d]=%d\n", i, j, C[i][j]);
// 		}
// 	}
///!就是排序有问题！！！！
	i = j = k = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 1; C[i][j]!=-1; j++)
		{
			int Tmp = C[i][j];
			for (k = j; k > 0 && C[i][k - 1] > Tmp; k--)
			{
				C[i][k] = C[i][k - 1];
			}
			C[i][k] = Tmp;
		}
	}

	// for (i = 0; i < 5; i++)
	// {
	// 	for (j = 0; j < 5 && C[i][j] != -1; j++)
	// 	{
	// 		printf("\n C[%d][%d]=%d\n", i, j, C[i][j]);
	// 	}
	// }

	i = j = k = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; C[i][j] != -1; j += 2)
		{
			for (k = 0; A[C[i][j]][k] != -1; k++)
			{
			}
			A[C[i][j]][k] = i;
		}
	}

	i = j = k = 0;

	for (i = 0; A[num][i] != -1; i++)
	{
		printf("%d,", A[num][i]);
	}
	if (A[num][0] == -1)
	{
		printf("-1");
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
int main()
{
	int A[5][5], C[5][5];
	int B[20] = {0};
	int i, j, k;
	i = j = k = 0;
	for (i = 0; i < 5;i++)
	{
		for (j = 0; j < 5; j++)
		{
			A[i][j] = -1;
			C[i][j] = -1;
		}
	}
	i = j =k= 0;
	int NeedNum;
	while (1)
	{
		scanf("%d", &B[i]);
		//!XXX if(getchar()!='\n')  XXX
		if(getchar()=='\n')
		{
			//! XXX B[i] = NeedNum;
			NeedNum = B[i];
			break;
		}
		scanf("%d,", &k);
		for (j = 0; C[B[i]][j] != -1;j++)
		{}
		C[B[i]][j] = k;
		i++;
	}
	i = j = k = 0;
	for (i = 0; i < 5;i++)
	{

		//!XXX  for (j = 1; j < 5;j++)
		for (j = 1; C[i][j] != -1;j++)
		{
			int Tmp = C[i][j];
			for (k = j; k > 0 &&Tmp < C[i][k - 1]/*&&C[i][k]!=-1*/;k--)
			{
				C[i][k] = C[i][k - 1];
			}
			C[i][k] = Tmp;
		}
	}
	i = j = k = 0;
	for (i = 0; i < 5;i++)
	{
		for (j = 0; j < 5 && C[i][j] != -1;j+=2)
		{
			for (k = 0; A[C[i][j]][k] != -1;k++){}
			A[C[i][j]][k] = i;
		}
	}
	i = j = k = 0;
	for (j = 0; A[NeedNum][j] != -1;j++)
	{
		printf("%d,", A[NeedNum][j]);
	}
	if(A[NeedNum][0]==-1)
	{
		printf("-1");
	}
	printf("\n");
	return 0;
}
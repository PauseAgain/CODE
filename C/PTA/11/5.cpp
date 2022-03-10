#include <stdio.h>
void sort(int a[], int n, int exp);
int main()
{
	int x = 0;
	char y;
	int a[20];
	int top = -1;
	while ((y = getchar()) != '\n')
	{//!学一下如何获得，num混杂情况下的a[]纯数字数组（包括>9)的数据
		if (y != ',')//!假如y是数字
		{
			x = x * 10 + y - '0';//x=y-‘0’，X成为下一次getchar得到的数的上一位（X10)
		}
		else//!终于碰见逗号了！！，把x存下来
		{
			a[++top] = x;
			x = 0;//?清零记录
		}
	}
	int n = top + 1;
	int max = a[0];//将max先假定是第一个节点
	for (int i = 1; i < n; i++)//直接从第二个节点开始和max比较
	{ //是n不是10
		if (max < a[i])
		{
			max = a[i];
		}
	}//!到这已经直达max了

	int times = 0;
	int k;
	scanf("%d", &k);
		//!exp从1开始，每一循环扩大十倍
	for (int exp = 1; max / exp > 0 /*结束条件！eg:554/50 =11√;  554/500 =1√  ;554/5000 <0  X  */; exp = exp * 10)
	{
		sort(a, n, exp);
		times++;
		if (times == k)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d,", a[j]);
			}
		}
	}

	return 0;
}
void sort(int a[], int n, int exp)
{
	int bucket[10] = {0};
	int output[n]; // 注意这里的大小
	//统计每一个 最后一位的数字 分别有几个数
	for (int i = 0; i < n; i++)
	{
		int last = (a[i] / exp) % 10;
		bucket[last]++;
	}
	//累计，看最后一位数（包括自己）前面一个有多少的数
	for (int i = 1; i < 10; i++)
	{
		bucket[i] = bucket[i] + bucket[i - 1];
	}
	//把数组中的数 映射到output
	for (int i = n - 1; i >= 0; i--)
	{
		int index, last;
		last = (a[i] / exp) % 10;
		index = bucket[last] - 1;
		output[index] = a[i];
		bucket[last]--;
	}
	//把output 的数组弄到a
	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}

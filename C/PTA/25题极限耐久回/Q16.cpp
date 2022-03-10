#include <stdio.h>
void sort(int a[], int n, int exp);
int main()
{
	int x = 0;
	char y;
	int a[20];
	int top = -1;
	while ((y = getchar()) != '\n')
	{
		if (y != ',')
		{
			x = x * 10 + y - '0';
		}
		else
		{
			a[++top] = x;
			x = 0;
		}
	}
	int n = top + 1;
	int max = a[0];
	for (int i = 1; i < n; i++)
	{ //是n不是10
		if (max < a[i])
		{
			max = a[i];
		}
	}
	int times = 0;
	int k;
	scanf("%d", &k);
	for (int exp = 1; max / exp > 0; exp = exp * 10)
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

#include<stdio.h>
void Sort(int *A,int n,int exp)
{
	int Bucket[10] = {0};
	int OutPut[n];
	for (int i = 0; i < n;i++)
	{
		int last = (A[i] / exp) % 10;
		Bucket[last]++;
	}
	for (int i = 1; i < 10;i++)
	{
		Bucket[i] = Bucket[i] + Bucket[i - 1];
	}
	for (int i = n - 1; i >= 0;i--)
	{
		int index, last;
		last = (A[i] / exp) % 10;
		index = Bucket[last] - 1;
		OutPut[index] = A[i];
		Bucket[last]--;
	}
	for (int i = 0; i < n;i++)
	{
		A[i] = OutPut[i];
	}
	
}

int main()
	{
		int x = 0;
		char y;
		int a[20];
		int top = 0;
		while((y=getchar())!='\n')
		{
			if(y!=',')
			{
				//!x = x * 10 + y（char）;
				x = x * 10 + (y - '0');
			}
			else{
				a[top++] = x;
				x = 0;
			}
		}
		int n = top;
		int max = a[0];
		for (int i = 1; i < n;i++)
		{
			if(max<a[i])
				max = a[i];
		}
		int count=0;
		int k;
		scanf("%d", &k);
		for (int exp = 1; max / exp > 0;exp*=10)
		{
			Sort(a, n, exp);
			count++;
			if(count==k)
			{
				for (int j = 0; j < n; j++)
			{
				printf("%d,", a[j]);
			}
			}
		}
		printf("\n");
		return 0;
	}


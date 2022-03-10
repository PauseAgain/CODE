#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char Array[100]={'\0'};
	char x;
	int number;
	int count = 0;

	for (count = 0; (number = scanf("%d,", &number)) != EOF;count++)
	{
		while(count%2==0)
		{
			Array[count] = number;
		}
	}
	for (int i = 0; Array[i] != '\0';i++)
	{
		printf("%d", Array[i]);
	}
}
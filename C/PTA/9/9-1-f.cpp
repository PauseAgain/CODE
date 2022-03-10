#include <stdio.h>

int main()
{
	int count = 0;

	//!缺了初始化   char array[100];   x

	char array[100] = {0};

	scanf("%s", array);

	while (array[count] != '\0')
	{
		count++;//! 这个++同理
		if (array[count] == '0')
		{
			if (array[count + 1] == '0')
			{
				printf("b");
				count ++;
				
			}
			else if (array[count + 1] == '1')
			{
				printf("g");
				count ++;
				//!break;break是无用的!!
			}
		}
		else if (array[count] == '1')
		{
			if (array[count + 1] == '1')
			{
				printf("e");
				count ++;
				
			}
			else if (array[count + 1] == '0')
			{
				
				//?因为每次进入次级目录都已经++过了，所以之后父节点判断
				//?也是判断[count+1] == '0'/'1'

				count++;

				//!如果这一行没有分支叶子，全是父节点\
				//!，直接++，不要把工作量留给下一行 如+=2；
				////if (array[count + 2] == '1')
				if (array[count +1] == '1')
				{
					//!同理，两个父节点,下面[count+x]->[count +1]
					count++;
					if (array[count + 1] == '0')
					{
						printf("a");
						count ++;
						////break;
					}
					else if (array[count + 1] == '1')
					{
						printf("h");
						count ++;
						////break;
					}
				}
				else if (array[count + 1] == '0')
				{
					count++;

					if (array[count + 1] == '1')
					{
						printf("d");
						count ++;
						////break;
					}
					else if (array[count + 1] == '0')
					{
						count++;
						if (array[count + 1] == '1')
						{
							printf("f");
							count ++;
						////	break;
						}
						else if (array[count + 4] == '0')
						{
							printf("c");
							count ++ ;
							////break;
						}
					}
				}
			}
		}
	}
	return 0;
}
#include <stdio.h>
int main()
{
	int i = 0;
	char a[100] = {0};
	scanf("%s", a);
	while (a[i] != '\0')
	{
		if (a[i] == '0')
		{
			if (a[i + 1] == '0')
			{
				i++;
				printf("b");
			}
			else
			{
				i++;
				printf("g");
			}
		}
		else
		{
			if (a[i + 1] == '1')
			{
				i++;
				printf("e");
			}
			else
			{
				i++;
				if (a[i + 1] == '1')
				{
					i++;
					if (a[i + 1] == '0')
					{
						i++;
						printf("a");
					}
					else
					{
						i++;
						printf("h");
					}
				}
				else
				{
					i++;
					if (a[i + 1] == '1')
					{
						i++;
						printf("d");
					}
					else
					{
						i++;
						if (a[i + 1] == '1')
						{
							i++;
							printf("f");
						}
						else
						{
							i++;
							printf("c");
						}
					}
				}
			}
		}
		i++;
	}
	return 0;
}

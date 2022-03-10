#include<stdio.h>

int main()
{
  char str[100];
	scanf("%s", str);

	int xkh = 0;
	int zkh = 0;
	int dkh = 0;
	int x = 0;
	int z = 0;
	int d = 0;


	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
		{
			xkh+=1;
		}

		if (str[i] == '[')
		{
			zkh+=1;
		}

		if (str[i] == '{')
		{
			dkh+=1;
		}
		
		if (str[i] == ')' && (xkh == 1))
		{
			xkh-=1;
		}
		else if (str[i] == ')' && (xkh != 1))
		{
			x = 2;
		}

		if ((str[i] == ')') && (xkh == 1) && (dkh == 1))
		{
			x = 2;
			d = 2;
		}
		if ((str[i] == ')') && (xkh == 1) && (zkh == 1))
		{
			x = 2;
			z = 2;
		}
		if((str[i] == ']') && (zkh == 1))
		{
			zkh --;
		}
		else if ((str[i] == ']') &&(zkh != 1))
		{
			z = 2;
		}

		if ((str[i] == ']') && (zkh == 1)&&(xkh==1))
		{
			z=2;x=2;
		}
		if ((str[i] == ']') && (zkh == 1)&&(dkh==1))
		{
			z=2;d=2;
		}


		if ((str[i] == '}') &&dkh== 1)
		{
			dkh--;
		}
		else if((str[i] == '}') &&dkh!= 1)
		{
			d=2;
		}

		if((str[i] == '}')&&(dkh==1)&&(xkh)==1)
		{
			d=2;x=2;
		}
		if((str[i] == '}')&&(dkh==1)&&(zkh)==1)
		{
			d=2;z=2;
		}

	}

		int n=0;
		if(xkh!=0||x!=0)
		{
			printf("1,");
			n++;
		}
		if(zkh!=0||z!=0)
		{
			printf("2,");
			n++;
		}
		if(dkh!=0||d!=0)
		{
			printf("3,");
			n++;
		}

		if(n==0)
		{
			printf("0");
		}
	return 0;
}
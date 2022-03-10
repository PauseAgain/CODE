#include<stdio.h>

int main()
{
	char str[100];
	
	scanf("%s",str);


	int xkh = 0;
	int zkh = 0;
	int dkh = 0;
	int Xkh = 0;
	int Zkh = 0;
	int Dkh = 0;	

		
	int i = 0;
	while(str[i] != '\0')
	{
				
		if(str[i] == '(')
		{
			xkh += 1;
		}
		if(str[i] == '[')
		{
			zkh += 1;
	
		}
		if(str[i] == '{')
		{
			dkh += 1;

		}	
		
		if((str[i] == ')') && (xkh == 1))
		{
			xkh -= 1;
		}	
		else
		if((str[i] == ')') && (xkh != 1))
		{
			Xkh = 2;
		}
		
		if((str[i] == ')')&&(dkh == 1)&&(xkh == 1))
		{
			Xkh = 2;
			Dkh = 2; 
		} 
		
		if((str[i] == ')')&&(zkh == 1)&&(xkh == 1))
		{
			Xkh = 2;
			Zkh = 2;
		} 

	
	
	
		
		if((str[i] == ']') && (zkh == 1))
		{
			zkh -= 1;
		}	
		
		else
		if((str[i] == ']') && (zkh != 1))
		{
			Zkh = 2;
		} 
		
		if((str[i] == ']')&&(xkh == 1)&&(zkh == 1))
		{
			Zkh = 2;
			Xkh = 2;
		} 
		
		if((str[i] == ']')&&(dkh == 1)&&(zkh == 1))
		{
			Zkh = 2;
			Dkh = 2;
		} 
		
		
		
		
		if((str[i] == '}') && (dkh == 1))
		{
			dkh -= 1;
		}		
		else 
		if((str[i] == '}') && (dkh != 1))
		{
			Dkh = 2;
		}
		
		if((str[i] == '}')&&(xkh == 1)&&(dkh == 1))
		{
			Dkh = 2;
			Xkh = 2;
		} 
		
		if((str[i] == '}')&&(zkh == 1)&&(dkh == 1))
		{
			Dkh = 2;
			Zkh = 2;
		} 
		
		
				
	
	i++;
	
	}
		
	int n = 0;
	
	if(xkh != 0 || Xkh != 0)
	{
		printf("1,");
		n++;
	}
	if(zkh != 0 || Zkh != 0) 
	{
		printf("2,");
		n++;	
	}
	if(dkh != 0 || Dkh != 0)
	{
		printf("3,");	
		n++;
	}
	
	
	if(n == 0)
	{
		printf("0");
	}
	
	return 0;
} 

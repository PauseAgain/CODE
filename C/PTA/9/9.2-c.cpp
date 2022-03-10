/*
7-2 How to Place the Mail (100 分)
Given 10 boxes ,numbered from 0 to 9, to store mail items. 
Every item is also signed with a phone number of its receiver.
 Write a policy to distribute the items into the boxes. 
 The rule is: try to mach the box number with the last digit of the related phone number,
if the box has already ocuppied, use the quadratic probing method to deal with the collision.

输入格式:
a seris of phone numbers separated by commas

输出格式:
the phone numbers of the items in the boxes which orderd from box 0 to 9. If the box is empty, output 0。

输入样例:
13801014370,13901021320,13621026170
结尾无空行
输出样例:
13801014370,13901021320,0,0,13621026170,0,0,0,0,0
结尾无空行
*/
#include<stdio.h>
int main()
{
	char tel[999]={0};
	int x,i=0;
	int j=0;
	int k=1;
	int tmp=0;
	int box[10][11]={0};
	scanf("%s",tel); 
	while(tel[i]!='\0')
{
	x=tel[i+10]-'0';k=1;
	if(box[x][0]==0)
	{
		for(j=0;j<11;i++,j++)
		{
			box[x][j]=tel[i]-'0';
		}
	}
	else 
	{	
		tmp=x;
		while(box[tmp][0]!=0)
		{
			tmp=(x+k*k)%10;
			k++;	
		}
		for(j=0;j<11;i++,j++)
		{
			box[tmp][j]=tel[i]-'0';
		}
	}
	if(tel[i]==',')i++;
}
	for(i=0;i<10;i++)
	{	
		j=0;
		if(box[i][j]!=0)
		{	
			for(j=0;j<11;j++)
			printf("%d",box[i][j]);
		}
		else
		{
			printf("0");
		}
		if(i!=9)printf(",");
	}
	return 0;
}

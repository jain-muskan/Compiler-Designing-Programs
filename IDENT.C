#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char s[100];
	int i=0,flag=0;
	clrscr();
	printf("Enter a word");
	scanf("%s",s);
	if(isalpha(s[0])!=0 || s[0]=='_')
	{
		i=1;
		while(strlen(s)!=i)
		{
			if(isalnum(s[i])==0 && s[i]!='_')
			{
				flag=1;
				break;
			}
			i++ ;
		}
	}
	else
	flag=1;

	if(flag==1)
	{
	printf("\nNOT AN IDENTIFIER");
	}
	else
	printf("\nIDENTIFIER");

	getch();
}
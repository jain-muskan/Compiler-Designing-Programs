#include<stdio.h>
#include<conio.h>
#include<string.h>

enum NT{E=0,e=1,T=2,t=3,F=4};
int top=0,ci=0;
char table[5][6][4]={"\0"},exp[20],st[20];
int flag=0;
void parser(void);
void push(char);
void pop(void);
int  p_table(char);
void create_table();

void main()
{
	int l,m,n,lp=0;
	char t;
	clrscr();
	printf("Give Expression:");
	scanf("%s",exp);
	l=strlen(exp);
	printf("\n%d",strlen(exp));
	exp[l]='$';
	st[0]='$';
	st[1]='E';
	top=1;
	create_table();

	while(ci<strlen(exp))
	{
	parser();
	lp++;
	}

	if(flag==0)
	printf("String Unaccepted");
	getch();
}

void parser()
{
	int j,m,n;
	char str[5];
	if(st[top]==exp[ci])
	{
		if(st[top]=='$')
		{
			printf("\nString Accepted");
			ci++;
			flag=1;

		}
		else
		{
			pop();
			ci++;
		}
	}
	else if(st[top]=='E' || st[top]=='F' || st[top]=='T' || st[top]=='t' || st[top]=='e')
	{
		m=p_table(st[top]);
		n=p_table(exp[ci]);
		strcpy(str,table[m][n]);
		printf("\nexp=%c",exp[ci]);
		printf("\nstr=%s",str);
		if(strcmp(str,"\0")==0)
		{
			printf("\nNO VALUE IN TABLE");
			ci=strlen(exp);
		}
		else if(strcmp(str,"eps")==0)
		{
			pop();
		}
		else
		{
			printf("\n%s",str);
			strrev(str);
			printf("\n%s",str);
			pop();
			j=0;
			while(j<strlen(str))
			{
				push(str[j]);
				j++;
			}
		}
	}
	else
	{
		ci=strlen(exp);
	}


}

void push(char ch)
{
	top++;
	st[top]=ch;
	printf("\nPUSH:%c",ch);
}

void pop()
{
	printf("\nPOP:%c",st[top]);
	st[top]='\0';
	top--;

}


int p_table(char eci)
{
	int x;
	if(eci=='i')
	x=0;
	else if(eci=='+')
	x=1;
	else if(eci=='*')
	x=2;
	else if(eci=='(')
	x=3;
	else if(eci==')')
	x=4;
	else if(eci=='$')
	x=5;
	else if(eci=='E')
	x=0;
	else if(eci=='e')
	x=1;
	else if(eci=='T')
	x=2;
	else if(eci=='t')
	x=3;
	else if(eci=='F')
	x=4;
	else
	x=-1;

	return x;
}

void create_table()
{
	strcpy(table[E][0],"Te");
	strcpy(table[E][3],"Te");
	strcpy(table[e][1],"+Te");
	strcpy(table[e][4],"eps");
	strcpy(table[e][5],"eps");
	strcpy(table[T][0],"Ft");
	strcpy(table[T][3],"Ft");
	strcpy(table[t][1],"eps");
	strcpy(table[t][2],"*Ft");
	strcpy(table[t][4],"eps");
	strcpy(table[t][5],"eps");
	strcpy(table[F][0],"i");
	strcpy(table[F][3],"(E)");
}
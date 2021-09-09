#include<stdio.h>
#include<conio.h>

void E();
void EPRIME();
void T();
void TPRIME();
void F();

char c[20];
int p=0;

void main()
{


	clrscr();
	printf("Give Expression:");
	scanf("%s",c);
	E();
	if(p<strlen(c) )
	printf("Not part of the language");
	else
	printf("Valid Expression");
	getch();

}

void E()
{
	T();
	EPRIME();

}

void EPRIME()
{
	if(c[p]=='+'&& p<strlen(c))
	{
		p++;
		T();
		EPRIME();
	}
}

void T()
{
	F();
	TPRIME();
}

void TPRIME()
{
	if(c[p]=='*' && p<strlen(c))
	{
		p++;
		F();
		TPRIME();

	}
}

void F()
{
	if(c[p]=='(')
	{
		p++;
		E();
		if(c[p]==')')
		{
			p++;

		}
		else
		printf("\nMissing Right Paranthesis");
	}
	else if(c[p]=='i')
	{
		p++;

	}
	else
	{
		printf("\nIDENTIFIER EXPECTED");
	}
}
